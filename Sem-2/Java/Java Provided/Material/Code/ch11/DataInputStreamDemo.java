import java.io.*;
class student
{
   int rollno;
   string name;
   student(DataOutputStream dis)
   {
       rollno=sc.nextInt();
	   dis.writInt(rollno);
	   name=sc.next();
	   dis.writeUTF(name);
	}   

	   static void display(DataInputStream dis)
	   {
	     System.out.println(dis.readInt());
		 System.out.println(dis.readUTF());


}


class DataInputStreamDemo {

  public static void main(String args[]) {

    try {

      // Create a file input stream
      FileOutputStream fos =
        new FileoutputStream("frist.txt");

      // Create a data input stream
      DataOutputStream dos =
        new DataInputStream(fos);
		student s;
		for(i=0;i<5;i++)
		{
		s=new student(dos);
		}
		
      // Read and display data
      // Close file input stream
      fos.close();
	  dos.close();
	  FileInputStream fis =
        new FileoutputStream("frist.txt");

      // Create a data input stream
      DataInputStream dis =
        new DataInputStream(fis);
	  for(i=0;i<5;i++)
	  {
	   System.out.println(dis.readInt());
		 System.out.println(dis.readUTF());
	  }
	  fis.close();
	  dis.close();
	  
    }
    catch(Exception e) {
      System.out.println("Exception: " + e);
    }
  }
}
