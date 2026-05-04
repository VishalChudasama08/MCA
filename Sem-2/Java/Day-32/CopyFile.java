import java.io.*;

class CopyFile {
    public static void main(String [] args){
        
        String sourceFileName = "file1.txt";
        String copyFileName = "file2.txt";

        File f = new File(copyFileName);
        try {
            if(f.createNewFile()){
                FileReader fr = new FileReader(sourceFileName);
                FileWriter fw = new FileWriter(copyFileName);
                int i;
                while((i = fr.read()) != -1){
                    fw.write((char)i);
                }
                System.out.print(sourceFileName + "File copy on " + copyFileName + "File successfully!");
                fr.close();
                fw.close();
            } else {
                System.out.print("Faild to new file create file");
            }
        } catch (IOException e){
            System.out.print(e);
        }
    }
}