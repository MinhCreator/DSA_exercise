import java.io.IOException;
import java.nio.file.*;
import java.nio.*;
import java.util.Scanner;


public class RenameFile {

    public String rename(String file, String newName) {
        Path sourceFile = Paths.get(file);

        try {
            Files.move(sourceFile, sourceFile.resolveSibling(newName));
            return "Renamed sucess"; 
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
        return "failed Renamed file";
    }    

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String file, newName;
        System.out.println("enter file need to rename: ");
        file = sc.next();
        System.out.println("enter new name: ");
        newName = sc.next();

        System.out.println(new RenameFile().rename(file, newName));
        sc.close();
    }
}