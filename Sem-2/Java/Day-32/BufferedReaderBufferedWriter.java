import java.io.*;

class BufferedReaderBufferedWriter{
    public static void main(String [] args){
        try {
            BufferedReader br = new BufferedReader(new FileReader("file1.txt"));
            StringBuilder sb = new StringBuilder();
            String line;

            while((line = br.readLine()) != null){
                sb.append(line).append('\n');
            }

            br.close();

            sb.reverse();

            BufferedWriter bw = new BufferedWriter(new FileWriter("file2.txt"));
            bw.write(sb.toString());
            bw.close();

            System.out.println("Work Done! file content reverse and store in file2.txtsuccessfully");
        } catch (IOException e){
            System.out.print(e);
        }
    }
}