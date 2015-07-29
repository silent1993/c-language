package lab3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.security.spec.ECFieldF2m;
import java.util.HashMap;

import javax.security.auth.Refreshable;
import javax.sound.midi.Receiver;

public class Server {
	public static void main(String[] args) throws Exception {
		String serverHost = "127.0.0.1";
		int serverPort = 3344;
		DatagramSocket ds = new DatagramSocket(new InetSocketAddress(
				serverHost, serverPort));
		System.out.println("服务端启动!");
		new Thread(new server_receive(ds)).start();
	}
}

class server_receive implements Runnable {
	DatagramPacket packet;
	DatagramSocket socket;

	// server_send send;

	class pkg {
		int ACK_NUM;
		String content;

		public int getACK_NUM() {
			return ACK_NUM;
		}

		public void setACK_NUM(int aCK_NUM) {
			ACK_NUM = aCK_NUM;
		}

		public String getContent() {
			return content;
		}

		public void setContent(String content) {
			this.content = content;
		}

		public pkg(int num, String c) {
			ACK_NUM = num;
			content = c;
		}
	}

	class information {
		HashMap<Integer, pkg> store = new HashMap<>();
		int size = 6;
		int MAX_PKG_NUM = 7;

		// int num=0;
		public boolean receive(int num) {
			return true;
		}

		private File file;

		public void receive(int ack, String con) {
			for (int i = 0; i < size; i++) {
				if (store.get(i).getACK_NUM() == ack) {
					// System.out.println("store "+ack+" content:"+con);
					store.get(i).setContent(con);
				}
			}
			refresh();
		}

		public void refresh() {
			int i = 0;
			try {
				StringBuffer content = new StringBuffer();
				try {
					BufferedReader tempBufferedReader = new BufferedReader(
							new FileReader(file));
					String line;
					while ((line = tempBufferedReader.readLine()) != null) {
						content.append(line + "\n");
					}
					tempBufferedReader.close();
				} catch (FileNotFoundException e) {

				}
				while (i < size && store.get(i).getContent() != null) {
					content.append(store.get(i).getContent() + "\n");
					for (int j = 0; j < size - 1; j++) {
						store.put(j, store.get(j + 1));
					}
					store.put(size - 1, new pkg(MAX_PKG_NUM++, null));
				}
				// System.out.println("内容："+content);
				BufferedWriter tempBufferedWriter = new BufferedWriter(
						new FileWriter(file));
				tempBufferedWriter.write(content.toString());
				tempBufferedWriter.flush();
				tempBufferedWriter.close();
			} catch (Exception e1) {
				e1.printStackTrace();
			}
		}

		public File getFile() {
			return file;
		}

		public void setFile(File file) {
			this.file = file;
		}

		public information(File f) {
			// this.ACKNumber = ACKNumber;
			this.file = f;
			for (int i = 0; i < size; i++) {
				store.put(i, new pkg(i + 1, null));
			}
		}
	}

	HashMap<InetAddress, HashMap<Integer, information>> memo = new HashMap<>();
	byte buffer[] = new byte[1024];

	public server_receive(DatagramSocket ds) {
		// TODO Auto-generated constructor stub
		try {
			socket = ds;
			// this.send = send;
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		HashMap<Integer,Integer> lossMap=new HashMap<>();
		try {
			while (true) {
				packet = new DatagramPacket(buffer, buffer.length);
				socket.receive(packet);
				String info = new String(packet.getData(), 0,
						packet.getLength());
				InetAddress address = packet.getAddress();
				int port = packet.getPort();
				int offset = info.indexOf("@@@");
				// String
				// log11="服务器接收信息   来自客户端地址："+address.getHostAddress()+",端口："+port+",content:"+info;
				// System.out.println(log11);
				String log = info.substring(offset + 3);
				if (offset != -1) {
					info = new String(packet.getData(), 0, offset);
					info = "ACK" + info;
					int No = Integer.parseInt(info.substring(3, info.length()));
					System.out.println("recv:  " + No);
					// boolean flag = false;
					if (memo.get(address) == null) {
						HashMap<Integer, information> temp = new HashMap<>();
						temp.put(port, null);
						memo.put(address, temp);
					}
					if (memo.get(address).get(port) == null) {
						File tempFile = new File(
								"C:\\Users\\Zh\\Desktop\\destination\\" + log);
						if (tempFile.exists()) {
							tempFile.delete();
							tempFile.createNewFile();
						} else {
							tempFile.createNewFile();
						}
						information tempInformation = new information(tempFile);
						memo.get(address).put(port, tempInformation);
						// packet = new DatagramPacket(buffer, buffer.length,
						// address, port);
						// packet.setData(info.getBytes());
						// System.out.println(info);
						// socket.send(packet);
					} else {
						memo.get(address).get(port).receive(No, log);

					}
					if (No % 4 == 3) {
						if(lossMap.get(No)==null){
							lossMap.put(No, 0);
						}
						int times=lossMap.get(No);
						if (times<3) {
							lossMap.put(No, times+1);
							System.out.println("loss package: " + No);
						}else{
							packet = new DatagramPacket(buffer, buffer.length,
									address, port);
							packet.setData(info.getBytes());
							socket.send(packet);
							lossMap.put(No, 0);
						}
					}else {
						packet = new DatagramPacket(buffer, buffer.length,
								address, port);
						packet.setData(info.getBytes());
						socket.send(packet);
					}
				} else {
					System.out.println("wrong format");
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}