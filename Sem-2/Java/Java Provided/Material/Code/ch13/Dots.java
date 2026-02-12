import java.applet.*;
import java.awt.*;
/*
  <applet code="Dots" width=250 height=100>
  </applet>
*/

public class Dots extends Applet 
implements Runnable {
  Thread t;

  public void init() {

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

  //public void update(Graphics g) {
  //  paint(g);
  //}

  public void paint(Graphics g) {

    // Pick a random point in the applet
    Dimension d = getSize();
    
    int x = 0;
    int y = 0;

    // Draw a dot at that location
    for(x=0;x<d.width;x++)
    {
    	g.fillRect(x, y, 2, 2);
    }
    
  }
}