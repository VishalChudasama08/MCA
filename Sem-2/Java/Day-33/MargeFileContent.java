import java.io.*;

class MargeFileContent {
    public static void main(String [] args){
        String file1Name = "file1.txt";
        String file2Name = "file2.txt";
        String margeFileName = "marge.txt";
        
        File f = new File(margeFileName);
        try {
            // if(f.createNewFile()){
                FileWriter fw = new FileWriter(margeFileName);
                FileReader fr1 = new FileReader(file1Name);
                int i;
                while((i = fr1.read()) != -1){
                    fw.write((char)i);
                }
                fr1.close();
                fw.write("\n");
                
                FileReader fr2 = new FileReader(file2Name);
                // int i;
                while((i = fr2.read()) != -1){
                    fw.write((char)i);
                }
                fr2.close();
                fw.close();
                System.out.print( file1Name + "file and " + file2Name + "file marge on " + margeFileName + "file Successfully!");
            // } else {
            //     System.out.println( "Faild to create " +margeFileName + " file!");
            // }
        } catch (IOException e){
            System.out.print(e);
        }
    }
}