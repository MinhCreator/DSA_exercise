public class Bai3 {
    public static void main(String[] args) {
        int[] data = {1,3,5,7,9};

        Thread t1 = new Thread(() -> {
            int sum = 0;
            for (int i = 0; i < data.length; i++) {
                sum += data[i];
            }
            System.out.println("Sum = " + sum);
        });
        Thread t2 = new Thread(new Runnable() {
            public void run() {
                int sum = 0;
                for (int i = 0; i < data.length; i++) {
                    sum += data[i];
                }
                double avg = (double) sum / data.length;
                System.out.println("Average = " + avg);
            }
        });

        Thread t3 = new Thread(new Runnable() {
            @Override
            public void run() {
                int max = data[0];
                for (int i = 1; i < data.length; i++) {
                    if (data[i] > max) {
                        max = data[i];
                    }
                }
                System.out.println("Max = "+ max);
            }
        });

        t1.start();
        t2.start();
        t3.start();
    }
}
