package example;
public class calculateThread {

    public calculateThread(int start, int end) {
        // odd(start, end);
        even(start, end);

    }

    synchronized public void odd(int start, int end) {
        Thread odd = new Thread(() -> {

            for (int numb = start; numb <= end; numb++) {
                if (numb % 2 != 0) {

                    System.out.println("Odd: " + numb);
                }
            }

        });
        odd.start();
    }

    synchronized public void even(int start, int end) {
        Thread even = new Thread(() -> {
            for (int numb = start; numb <= end; numb++) {
                if (numb % 2 == 0) {

                    System.out.println("Even: " + numb);
                }
            }

        });
        even.start();
    }
    
    public static void main(String[] args) {
        new calculateThread(1, 100);
    }
}