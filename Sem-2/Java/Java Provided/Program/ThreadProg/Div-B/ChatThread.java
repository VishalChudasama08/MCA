
import java.util.Scanner;

class ChatSender implements Runnable {
    private Scanner scanner;
    private String userName;

    public ChatSender(String userName, Scanner scanner) {
        this.userName = userName;
        this.scanner = scanner;
    }

    public void run() {
        while (true) {
            synchronized (scanner) { // Synchronizing input to avoid conflicts
                System.out.print(userName + " (Send): ");
                String message = scanner.nextLine();
                if (message.equalsIgnoreCase("bye")) {
                    System.out.println(userName + " has left the chat.");
                    System.exit(0);
                }
            }
            try {
                Thread.sleep(500); // Small delay to simulate real chat
            } catch (InterruptedException e) {
                System.out.println(userName + " was interrupted.");
            }
        }
    }
}

class ChatReceiver implements Runnable {
    private Scanner scanner;
    private String userName;

    public ChatReceiver(String userName, Scanner scanner) {
        this.userName = userName;
        this.scanner = scanner;
    }

    public void run() {
        while (true) {
            synchronized (scanner) { //  ensures only one thread can use the scanner at a time.
                System.out.print(userName + " (Reply): ");
                String message = scanner.nextLine();
                if (message.equalsIgnoreCase("bye")) {
                    System.out.println(userName + " has left the chat.");
                    System.exit(0);
                }
            }
            try {
                Thread.sleep(500); // Small delay to simulate real chat
            } catch (InterruptedException e) {
                System.out.println(userName + " was interrupted.");
            }
        }
    }
}

public class ChatThread {
    public static void main(String[] args) {
        System.out.println("Two-Way Chat Started! Type 'bye' to stop.");
        Scanner scanner = new Scanner(System.in); // Shared Scanner for both users

        Thread sender = new Thread(new ChatSender("Rishi", scanner));
        Thread receiver = new Thread(new ChatReceiver("Mehul", scanner));

        sender.start();
        receiver.start();
    }
}
