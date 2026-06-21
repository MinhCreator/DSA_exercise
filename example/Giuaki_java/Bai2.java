import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import java.io.File;
import java.io.IOException;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.DOMException;
import org.xml.sax.SAXException;

public class Bai2 {
    public static void main(String[] args) {
        try {

            DocumentBuilderFactory fct = DocumentBuilderFactory.newInstance();

            DocumentBuilder builder = fct.newDocumentBuilder();
            Document doc = builder.parse(new File("b2.xml"));

            Element root = doc.getDocumentElement();
            System.out.println("Root element: " + root.getNodeName());
            System.out.println("-----------------------------");
            NodeList students = root.getElementsByTagName("student");

            for (int i = 0; i < students.getLength(); i++) {

                Element student = (Element) students.item(i);
                System.out.println("Current element: " + student.getNodeName());
                System.out.println("Student roll no: " + student.getAttribute("rollno"));

                String firstname = student.getElementsByTagName("firstname").item(0).getTextContent();
                String lastname = student.getElementsByTagName("lastname").item(0).getTextContent();
                String nickname = student.getElementsByTagName("nickname").item(0).getTextContent();
                String marks = student.getElementsByTagName("marks").item(0).getTextContent();

                System.out.println("First name: " + firstname);
                System.out.println("Last name: " + lastname);
                System.out.println("Nick name: " + nickname);
                System.out.println("Marks: " + marks);
            }
        } catch (IOException | ParserConfigurationException | DOMException | SAXException e) {
        }
    }
}
