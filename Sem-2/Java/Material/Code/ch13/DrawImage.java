import java.applet.*;
import java.awt.*;
/*
  <applet code="DrawImage" width=280 height=280>
  <param name="file" value="sun.jpg">
  </applet>
*/

public class DrawImage extends Applet {
  Image image;
 
  public void init() {
   // Image = getImage(getDocumentBase(), getParameter("file"));
   URL h= new URL("e://advjava");
    //String s = "e:/advjava";
    Image = getImage(h,"logo.jpg");
  }
    
  public void paint(Graphics g) {
    g.drawImage(image, 0, 0, this);
  }
}