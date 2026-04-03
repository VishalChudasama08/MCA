import java.io.*;

class CountWordCharLine{
    public static void main(String [] args){
        try {
            BufferedReader br = new BufferedReader(new FileReader("file1.txt"));
            String line;
            int countLine=0, countWord=0, countChar=0; 

            while((line = br.readLine()) != null){
                countLine++;
                countChar += line.length();
                countWord += line.split(" ").length; // split by space , split(\\s+) also work
            }

            System.out.println("Total line: " + countLine);
            System.out.println("Total character: " + countChar);
            System.out.println("Total word: " + countWord);
        } catch (IOException e){
            System.out.print(e);
        }
    }
}