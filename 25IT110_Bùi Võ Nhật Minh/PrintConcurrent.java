
public class PrintConcurrent implements Runnable {

    synchronized private void printOdd() {
        for (int start = 1; start <= 100; start++) {

            if (start % 2 != 0) {
                System.out.print(start + " ");
            }

        }
    }

    synchronized private void printEven() {
        System.out.println("\n");
        System.out.println(
                "---------------------------------------------------------------------------------------------------");
        for (int start = 1; start <= 100; start++) {

            if (start % 2 == 0) {
                System.out.print(start + " ");
            }

        }
    }

    @Override
    public void run() {
        printOdd();
        printEven();
    }

    public static void main(String[] args) {
        PrintConcurrent t = new PrintConcurrent();
        t.run();
    }
}