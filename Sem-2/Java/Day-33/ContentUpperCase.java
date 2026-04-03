import java.io.*;

class ContentUpperCase {
    public static void main(String [] args){
        String sourseName = "file1.txt";
        String upperCaseFileName = "file2.txt";
        try {
            BufferedReader br = new BufferedReader(new FileReader("file1.txt"));
            StringBuilder sb = new StringBuilder();
            String line;

            BufferedWriter bw = new BufferedWriter(new FileWriter("file2.txt"));

            while((line = br.readLine()) != null){
                bw.write(line.toUpperCase() + "\n");
            }
            System.out.print(sourseName+" file convert in uppercase on "+upperCaseFileName+" file successfully!");
            br.close();
            bw.close();

        } catch (IOException e){
            System.out.print(e);
        }
    }
}