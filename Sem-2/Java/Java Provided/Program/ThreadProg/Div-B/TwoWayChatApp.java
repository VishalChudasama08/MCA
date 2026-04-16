/*Write Program and make Chat Application (Send & Receive Messages in Parallel)using
Runnable Interface Simulates a chat app where a user can type messages while receiving
them.( Runnable, Thread.sleep()).*/


import java.util.Scanner;

class ChatSender implements Runnable {
    private Scanner scanner;
    private String userName;

    public ChatSender(String userName) {
        this.userName = userName;
        synchronized scanner = new Scanner(System.in);
    }

    public void run() {
        while (true) {
		try
		{
            System.out.print(userName + " (Send): ");
			Thread.sleep(500);
            String message = scanner.nextLine();
			
			 if (message.equalsIgnoreCase("bye")) //BYE Bye bye
			 {
                System.out.println(userName + " has left the chat.");
                System.exit(0);
             }
           
		}catch(InterruptedException ie)	{	}
        }
    }
}

class ChatReceiver implements Runnable {
    private Scanner scanner;
    private String userName;

    public ChatReceiver(String userName) {
        this.userName = userName;
        scanner = new Scanner(System.in);
    }

    public void run() {
        while (true) {
		try{
            Thread.sleep(500);
			System.out.print(userName + " (Reply): ");
			
            String message = scanner.nextLine();
            if (message.equalsIgnoreCase("exit")) {
                System.out.println(userName + " has left the chat.");
                System.exit(0);
            }
		}catch(InterruptedException ie)	{	}
        }
    }
}

public class TwoWayChatApp {
    public static void main(String[] args) {
        System.out.println("Two-Way Chat Started! Type 'exit' to stop.");

        Thread sender = new Thread(new ChatSender("Mehul"));
        Thread receiver = new Thread(new ChatReceiver("Rishi"));

        sender.start();
        receiver.start();
    }
}
