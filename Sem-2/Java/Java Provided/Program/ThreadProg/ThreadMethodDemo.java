class DemoWorker implements Runnable {
    public void run() {
        String name = Thread.currentThread().getName();
        System.out.println(name + " has started.");

        for (int i = 1; i <= 3; i++) {
            try {
                System.out.println(name + " processing step " + i);
                Thread.sleep(1000);   // sleep(): Pauses the thread for 1 second
            } catch (InterruptedException e) {
                // interrupt(): Handles the interruption signal
                System.out.println(name + " was interrupted while sleeping!");
                return; 
            }
        }
        System.out.println(name + " has finished.");
    }
}

public class ThreadMethodDemo {
    public static void main(String[] args) {
        Thread t1 = new Thread(new DemoWorker(), "High-Priority-Thread");
        Thread t2 = new Thread(new DemoWorker(), "Low-Priority-Thread");

        // 1. Setting Priorities
        t1.setPriority(Thread.MAX_PRIORITY); // 10
        t2.setPriority(Thread.MIN_PRIORITY); // 1
        
        System.out.println("Starting threads...");
        t1.start();
        t2.start();

        // 2. isAlive(): Checks if thread is still running
        System.out.println(t1.getName() + " is alive: " + t1.isAlive());

        try {
            // 3. join(): Main thread waits for t1 to finish before moving on
            System.out.println("Main thread waiting for " + t1.getName() + " to finish...");
            t1.join(); 
            
            // 4. interrupt(): Send an interrupt signal to t2
            System.out.println("Main thread is impatient! Interrupting " + t2.getName());
            t2.interrupt();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread execution finished.");
    }
}