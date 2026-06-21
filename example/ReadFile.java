
import java.io.BufferedReader;
import java.io.FileReader;

public class ReadFile {
    public void read(String fileName) {

        int WordCounter = 0;

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (!line.trim().isEmpty()) {
                    WordCounter += line.trim().split("\\s+").length;
                }
            }
            System.out.println("quantity of word: " + WordCounter);
        } catch (Exception e) {
            System.err.println(e.getMessage());

        }

    }

    public static void main(String[] args) {
        new ReadFile().read("test.txt");
    }
}