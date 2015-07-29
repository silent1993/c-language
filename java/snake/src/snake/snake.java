package snake;

import java.awt.Container;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;


public class snake {
	public static void main(String[] args) {
		new SnakeFrame().setVisible(true);
	}
}

class SnakeFrame extends JFrame {
	public static final int height = 410;
	public static final int width = 410;

	public SnakeFrame() {
		setTitle("Snake");
		setSize(height, width);
		SnakePanel panel = new SnakePanel();
		Container contentPane = getContentPane();
		contentPane.add(panel);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

class SnakePanel extends JPanel {
	public static int size = 40;
	public int time[][] = new int[40][40];
	public int x, y, dir, length = 3;
	public boolean flag = true;
	Timer timer;

	public SnakePanel() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				time[i][j] = 0;
			}
		}
		x=y=0;
		dir=1;
		time[x][y] = length;
		//new eat
		Random random = new Random();
		int tmpx = Math.abs(random.nextInt())%40, tmpy = Math.abs(random.nextInt())%40;
		while(time[tmpx][tmpy] != 0) {
			tmpx = Math.abs(random.nextInt())%40;
			tmpy = Math.abs(random.nextInt())%40;
		}
		time[tmpx][tmpy] = -1;
		repaint();
		
		KeyHandler listener = new KeyHandler();
		addKeyListener(listener);
		
		timer = new Timer();
		timer.schedule(new refreshtask(), 333, 333);
	}

	public boolean isFocusTraversable() {
		return true;
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g;

		// draw all
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if(time[i][j] > 0) {
					g2.fillRect(i*10, j*10, 10, 10);
					if(flag) time[i][j]--;
				}
				if(time[i][j] < 0) {
					g2.fillRect(i*10, j*10, 10, 10);
				}
			}
		}
	}

	private class KeyHandler implements KeyListener {
		public void keyPressed(KeyEvent event) {
			int keyCode = event.getKeyCode();

			// add line segment
			if (keyCode == KeyEvent.VK_LEFT) {
				if(dir != 1) {
					dir = 3;
				}
			}
			else if (keyCode == KeyEvent.VK_RIGHT) {
				if(dir != 3) {
					dir = 1;
				}
			}
			else if (keyCode == KeyEvent.VK_UP) {
				if(dir != 2) {
					dir = 0;
				}
			}
			else if (keyCode == KeyEvent.VK_DOWN) {
				if(dir != 0) {
					dir = 2;
				}
			}
		}

		public void keyReleased(KeyEvent event) {
			
		}

		public void keyTyped(KeyEvent event) {
			
		}
	}
	class refreshtask extends TimerTask {
		public void run() {
			if (dir == 0) { y = y-1;	}
			else if (dir == 2) { y = y+1; }
			else if (dir == 1) { x = x+1; }
			else if (dir == 3) { x = x-1; }
			if(x == size) x = 0;
			if(y == size) y = 0;
			if(x == -1) x = size - 1;
			if(y == -1) y = size - 1;
			//fail
			if(time[x][y] > 0) {
				flag = true;
				JOptionPane.showMessageDialog(null, "you lose");
				timer.cancel();
			}
			//move
			if(time[x][y] == 0) {
				flag = true;
				time[x][y] = length;
			}
			//eat
			if(time[x][y] < 0) {
				flag = false;
				time[x][y] = length;
				length++;
				//new eat
				Random random = new Random();
				int tmpx = Math.abs(random.nextInt())%40, tmpy = Math.abs(random.nextInt())%40;
				while(time[tmpx][tmpy] != 0) {
					tmpx = Math.abs(random.nextInt())%40;
					tmpy = Math.abs(random.nextInt())%40;
				}
				time[tmpx][tmpy] = -1;
			}
			
			repaint();
		}
	}
}

