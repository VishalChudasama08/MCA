import java.io.*;
import java.util.*;

public class FileClasses {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		String fileName = "simpleFile.txt";
		File file = new File(fileName);

		FileWriter fw = new FileWriter(fileName);
		fw.write("String");
		fw.close();

		FileReader fr = new FileReader(fileName);
		int i;
		while((i = fr.read()) != -1){
			System.out.print((char)i);
		}
		fr.close();

		BufferedWriter bw = new BufferedWriter(new FileWriter(fileName));
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		StringBuffer sb = new StringBuffer();
		sb.append(fileName);
		String str = sb.toString();
		int l = sb.length();
		sb.delete(0, l); // delete start , end
		sb.reverse(); // now all are reversed
		String line;
		while((line = br.readLine()) != null){
			sb.append(line).append("\n");
			bw.write(line.trim().replaceAll("\\s+", " ") + "\n");
		}
		bw.close();
		br.close();


		FileOutputStream fos = new FileOutputStream("demo.dat");
		fos.write(12);
		fos.write('v');
		fos.write('\n');
		fos.write("Vishal".getBytes());
		fos.close();


		FileInputStream fis = new FileInputStream("demo.dat");
		int j;
		while((j=fis.read()) != -1){
			System.out.println((char)j);
		}
		fis.close();


		DataOutputStream dos = new DataOutputStream(new FileOutputStream("demo.dat"));
		dos.writeInt(123);
		dos.writeFloat(12.12f);
		dos.writeChar('v');
		dos.writeBoolean(true);
		dos.writeUTF("Vishal");
		dos.close();

		DataInputStream dis = new DataInputStream(new FileInputStream("demo.dat"));
		int num = dis.readInt(); // read order by order as per it write
		float f = dis.readFloat();
		char c = dis.readChar();
		boolean b = dis.readBoolean();
		String s = dis.readUTF();
		dis.close();


		RandomAccessFile raf = new RandomAccessFile("newFile.txt", "rw");
		raf.writeInt(12);
		raf.writeFloat(12.12f);
		raf.writeDouble(23.23d);
		raf.writeChar('\n');
		raf.writeBoolean(true);
		raf.writeUTF("Vishal");

		raf.seek(0);

		raf.readInt();
		raf.readFloat();
		Double dnew = 234.123d;
		raf.writeDouble(dnew); // order mater

		raf.seek(0);

		while(raf.getFilePointer() < raf.length()){ 
			// read as order of write
			System.out.println(raf.readInt() + raf.readFloat() + raf.readDouble() + raf.readChar() + "" + raf.readBoolean() + raf.readUTF());
		}
		


		
		if(file.createNewFile()){ // create file
			System.out.println("File created");
		} else {
			System.out.println("File already exists");
		}

		if(!file.exists()){ // check file exists
			if(file.mkdir()){ // create folder & sub-folder (for sub-folder creation give full path on File class)
				System.out.println("Folder created successfully");
			} else {
				System.out.println("Failed to create folder");
			}

			if(file.delete()){ // delete file and folder
				System.out.println("file deleted successfully");
			} else {
				System.out.println("Failed to delete file");
			}

			File newFile = new File("NewName.txt");
			if(file.renameTo(newFile)){ // rename file and folder
				System.out.println("File rename successfully");
			} else {
				System.out.println("Failed to rename file");
			}
		} else {
			System.out.println("File already exists");
		}
	}	
}
