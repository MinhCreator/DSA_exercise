import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Bai1 {
    public static void main(String[] args) {
        
        String filename = "abc.txt"; 
        int wordCount = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (!line.trim().isEmpty()) {
                    wordCount += line.trim().split("\\s+").length;
                }
            }
            System.out.println("Number  words: " + wordCount);
        } catch (IOException e) {
            System.err.println("Error ");
        }
    }
}
