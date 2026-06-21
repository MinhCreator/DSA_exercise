1. Uploading an Image to the Database
Use a JFileChooser to select the file, then convert it into a stream for the database. 
Step 1: Select File
java
	JFileChooser chooser = new JFileChooser();
	chooser.showOpenDialog(null);
	File f = chooser.getSelectedFile();
	String path = f.getAbsolutePath();

Step 2: Save to DB
Use a PreparedStatement to handle binary data via setBinaryStream.
java
	FileInputStream fis = new FileInputStream(f);
	PreparedStatement ps = connection.prepareStatement("INSERT INTO table (image_col) VALUES (?)");
	ps.setBinaryStream(1, fis, (int) f.length());
	ps.executeUpdate();

2. Rendering an Image from the Database
To display the image, retrieve the bytes, convert them to an ImageIcon, and set them on a JLabel. 

Step 1: Retrieve Bytes
java
	ResultSet rs = statement.executeQuery("SELECT image_col FROM table WHERE id = 1");
	if (rs.next()) {
	    byte[] imgBytes = rs.getBytes("image_col");

Step 2: Display in Swing
Use ImageIcon to wrap the byte array.
java
    ImageIcon icon = new ImageIcon(imgBytes);
    // Optional: Scale image to fit JLabel
    Image img = icon.getImage().getScaledInstance(label.getWidth(), label.getHeight(), Image.SCALE_SMOOTH);
    label.setIcon(new ImageIcon(img));
}