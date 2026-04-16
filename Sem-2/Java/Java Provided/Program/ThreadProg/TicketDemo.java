// 1. We create a class that EXTENDS Thread
class TicketWindow extends Thread {
    // This variable is 'static' so all windows share the same 10 tickets
    private static int tickets = 10;

    // We give each window a name when we create it
    public TicketWindow(String name) {
        super(name);
    }

    // 2. This is the code the thread will run
    @Override
    public void run() {
        while (tickets > 0) {
            sell();
            try {
                Thread.sleep(500); // Pause so we can see the output
            } catch (Exception e) { }
        }
    }

    // 3. 'synchronized' prevents two windows from selling the same ticket
    private synchronized static void sell() {
        if (tickets > 0) {
            System.out.println(Thread.currentThread().getName() + " sold ticket #" + tickets);
            tickets--;
        } else {
            System.out.println("Sold out!");
        }
    }
}

public class TicketDemo {
    public static void main(String[] args) {
        // Create three separate thread objects
        TicketWindow w1 = new TicketWindow("Window-1");
        TicketWindow w2 = new TicketWindow("Window-2");
        TicketWindow w3 = new TicketWindow("Window-3");

        // Start them!
        w1.start();
        w2.start();
        w3.start();
    }
}