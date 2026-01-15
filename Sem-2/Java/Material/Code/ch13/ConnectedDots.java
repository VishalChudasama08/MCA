import java.applet.*;
import java.awt.*;
/*
  <applet code="ConnectedDots" width=250 height=100>
  </applet>
*/

public class ConnectedDots extends Applet 
implements Runnable {
  int xlast, ylast;
  Thread t;

  public void init() {

    // Initialize xlast and ylast
    xlast = -1;
    ylast = 1;

    // Start thread
    t = new Thread(this);
    t.start();
  }

  public void run() {
    try {
      while(true) {

        // Request a repaint
        repaint();

        // Sleep before displaying next dot
        Thread.sleep(200);
      }
    }
    catch(Exception e) {
    }
  }

  public void update(Graphics g) {
    paint(g);
  }

  public void paint(Graphics g) {

    // Pick a random point in the applet
    Dimension d = getSize();
    int x = (int)(Math.random() * d.width);
    int y = (int)(Math.random() * d.height);

    // Draw dot
    g.fillRect(x - 2, y - 2, 5, 5);

    // Draw a line from the previous dot
    if(xlast != -1) {
      g.drawLine(xlast, ylast, x, y);
    }

    // Update xlast and ylast
    xlast = x;
    ylast = y;
  }
}