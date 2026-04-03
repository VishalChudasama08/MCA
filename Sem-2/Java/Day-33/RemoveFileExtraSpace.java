import java.io.*;
class RemoveFileExtraSpace {
    public static void main(String [] args){
        String spaceFileName = "extra_space.txt";
        String perfectFileName = "perfect.txt";

        try {
            BufferedReader br = new BufferedReader(new FileReader(spaceFileName));
            BufferedWriter bw = new BufferedWriter(new FileWriter(perfectFileName));
            String line;
            
            while((line = br.readLine()) != null){
                bw.write(line.trim().replaceAll("\\s+", " ") + "\n");
            }
            br.close();
            bw.close();
            System.out.print("removed etra space Successfully!");
        } catch (IOException e){
            System.out.print(e);
        }
    }
}