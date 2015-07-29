package lab3;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

import javax.print.attribute.Size2DSyntax;
import javax.swing.JFileChooser;
import javax.swing.JLabel;

public class Client {
	private byte[] buffer = new byte[1024];
	private DatagramSocket ds = null;

	public Client() throws Exception {
		ds = new DatagramSocket();
	}

	public final DatagramPacket send(final String host, final int port,
			final byte[] bytes) throws IOException {
		DatagramPacket dp = new DatagramPacket(bytes, bytes.length,
				InetAddress.getByName(host), port);
		ds.send(dp);
		return dp;
	}

	public final String receive() throws Exception {
		DatagramPacket dp = new DatagramPacket(buffer, buffer.length);
		ds.receive(dp);
		String info = new String(dp.getData(), 0, dp.getLength());
		return info;
	}

	public static void main(String[] args) throws Exception {
		Client client = new Client();
		String serverHost = "127.0.0.1";
		int serverPort = 3344;
		// while()
		new Thread(new client_receive(client)).start();
		new Thread(new client_send(client, serverHost, serverPort)).start();
		;
	}
}
class check{
		public int getACKNum() {
		return ACKNum;
	}
	public void setACKNum(int aCKNum) {
		ACKNum = aCKNum;
	}
	public boolean isACK_Recv() {
		return ACK_Recv;
	}
	public void setACK_Recv(boolean aCK_Recv) {
		ACK_Recv = aCK_Recv;
	}
		int ACKNum;
		boolean ACK_Recv;
		public check(){
			ACKNum=0;
			ACK_Recv=false;
		}
		public check(int num ,boolean b){
			ACKNum=num;
			ACK_Recv=b;
		}
	}
class Window{
	HashMap<Integer, check> window;
	int size=6;
	int MAX_PKG_NUM=6;
	int MAX_ACK;
	public int getMAX_PKG_NUM() {
		return MAX_PKG_NUM;
	}
	public int getMAX_ACK(){
		return MAX_ACK;
	}
	public Window(){
		window=new HashMap<>();
		MAX_ACK=-1;
		for(int i=0;i<size;i++){
			window.put(i, new check(i,false));
		}
	}
	void reiceive(String s){
		System.out.println("recv: "+s);
		for(int i=0;i<size;i++){
			//System.out.println(i);
			if(s.equals("ACK"+window.get(i).getACKNum())){
				window.get(i).setACK_Recv(true);
			}
		}
		refresh();
		display();
	}
	void refresh(){
		int i=0;
		while(i<size&&window.get(i).isACK_Recv()){
			for(int j=0;j<size-1;j++){
				window.put(j, window.get(j+1));
			}
			window.put(size-1, new check(MAX_PKG_NUM++,false));
			//window.put(window.size(), new check());
		}
		//System.out.println(window.get(0).getACKNum());
		MAX_ACK=window.get(0).getACKNum()-1;
		//System.out.println("MAC_ACK="+MAX_ACK);
		//MAX_ACK=(window.get(0).getACKNum()-1)<0?0:(window.get(0).getACKNum()-1);
	}
	void display(){
		System.out.printf("%9s","ACK_NUM");
		for(int i=0;i<size;i++){
			System.out.printf("%10s",window.get(i).getACKNum()+"  ");
		}
		System.out.println();
		System.out.printf("%9s","CHECK");
		for(int i=0;i<size;i++){
			System.out.printf("%10s",window.get(i).isACK_Recv()+"  ");
		}
		System.out.println();
	}
}
class client_receive implements Runnable {
	Client client = null;
	DatagramSocket socket;
	static Window window=new Window(); 
	//static boolean wait = false;
	byte[] buffer = new byte[1024];

	public client_receive(Client c) {
		client = c;
		try {
			socket = new DatagramSocket();
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void run() {
		while (true) {
			try {

				String recv = client.receive();
				if (recv.matches("ACK[0-9]+")) {
					window.reiceive(recv);
					//wait = true;
				}
				System.out.println(recv + "   in receive");
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}

class client_send implements Runnable {
	int No = 1;
	Client client = null;
	String serverHost;
	int serverPort;
	Scanner scanner = new Scanner(System.in);
	HashMap<Integer, String> history=new HashMap<>();
	public client_send(Client c, String serverHost, int serverPort) {
		client = c;
		this.serverHost = serverHost;
		this.serverPort = serverPort;
	}
	public void run() {
		try {
			JFileChooser fileChooser=new JFileChooser(new File("C:\\Users\\Zh\\Desktop\\source"));
			fileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES );  
	        fileChooser.showDialog(new JLabel(), "Ñ¡Ôñ");  
	        File file=fileChooser.getSelectedFile();
	        BufferedReader br=new BufferedReader(new FileReader(file));
	        history.put(0, new String("0@@@"+file.getName()));
	        client.send(serverHost, serverPort, history.get(0).getBytes());
			String buf;
			while ((buf=br.readLine())!=null) {
				long time_begin = System.currentTimeMillis();
				long time_count;
				//System.out.println("No:  "+No+"  MAX: "+client_receive.window.getMAX_PKG_NUM()+" ACK"+client_receive.window.getMAX_ACK());
				while(No>=client_receive.window.getMAX_PKG_NUM()){
					//System.out.println("a");
					time_count = System.currentTimeMillis() - time_begin;
					if (time_count > 50) {
						System.out.println("wait");
						int reSend=client_receive.window.getMAX_ACK()+1;
						for(int i=reSend;i<No;i++){
							System.out.println("resend pkg: "+i);
							client.send(serverHost, serverPort, history.get(i).getBytes());
						}
						time_begin = System.currentTimeMillis();
					}
				};
				System.out.println("send "+No);
				history.put(No, new String(Integer.toString(No) +"@@@" + buf));
				client.send(serverHost, serverPort, history.get(No++).getBytes());
			}
			br.close();
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}