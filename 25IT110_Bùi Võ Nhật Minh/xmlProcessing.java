
import java.io.File;
import java.io.IOException;

import org.w3c.dom.Document;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.DOMException;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class xmlProcessing {

    public void xml(String fileName) {

        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();

            DocumentBuilder builder = factory.newDocumentBuilder();
            Document document = builder.parse(new File(fileName));

            Element root = document.getDocumentElement();
            System.out.println("Root element: " + root.getNodeName());
            System.out.println("-----------------------------");

            NodeList student = root.getElementsByTagName("student");

            for (int index = 0; index < student.getLength(); index++) {
                Element st = (Element) student.item(index);
                System.out.println("Current element: " + st.getNodeName());
                System.out.println("Student roll no: " + st.getAttribute("rollno"));

                String firstname = st.getElementsByTagName("firstname").item(0).getTextContent();
                String lastname = st.getElementsByTagName("lastname").item(0).getTextContent();
                String nickname = st.getElementsByTagName("nickname").item(0).getTextContent();
                String marks = st.getElementsByTagName("marks").item(0).getTextContent();
                
                System.out.println("First name: " + firstname);
                System.out.println("Last name: " + lastname);
                System.out.println("Nick name: " + nickname);
                System.out.println("Marks: " + marks);
            }

        } catch (IOException | ParserConfigurationException | DOMException | SAXException e) {
        }

    }

    public static void main(String[] args) {
        new xmlProcessing().xml("student.xml");
    }
}