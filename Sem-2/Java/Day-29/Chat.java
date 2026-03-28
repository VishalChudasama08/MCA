import java.util.*;

class ChatSender implements Runnable {
    private Scanner scan;
    private String userName;

    ChatSender(Scanner scan, String userName){
        this.scan = scan;
        this.userName = userName;
    }

    public void run(){
        while(true){
            synchronized (scan) { // synchronized scanner for conflict
                System.out.print(userName + " [Send]: ");
                String message = scan.nextLine();
                if(message.equalsIgnoreCase("bye")){
                    System.out.print("Are you scure you want to left chat ? [y/n]: ");
                    String confirm = scan.nextLine();
                    if(confirm.equalsIgnoreCase("y")){
                        System.out.println(userName + " has left the chat");
                        System.exit(0);
                    }
                }
            }
            try{
                Thread.sleep(500);
            } catch (InterruptedException e){
                System.out.println(userName + " was interrupted!");
            }
        }
    }
}
class ChatReceiver implements Runnable {
    private Scanner scan;
    private String userName;

    ChatReceiver(Scanner scan, String userName){
        this.scan = scan;
        this.userName = userName;
    }

    public void run(){
        while(true){
            synchronized (scan) { // synchronized scanner for conflict
                System.out.print(userName + " [Receive]: ");
                String message = scan.nextLine();
                if(message.equalsIgnoreCase("bye")){
                    System.out.print("Are you scure you want to left chat ? [y/n]: ");
                    String confirm = scan.nextLine();
                    if(confirm.equalsIgnoreCase("y")){
                        System.out.println(userName + " has left the chat");
                        System.exit(0);
                    }
                }
            }
            try{
                Thread.sleep(500);
            } catch (InterruptedException e){
                System.out.println(userName + " was interrupted!");
            }
        }
    }
}
class Chat {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);

        System.out.println("Type 'bye' to stop.");

        Thread senderTheard = new Thread(new ChatSender(scan, "Vishal"));
        Thread receiverTheard = new Thread(new ChatReceiver(scan, "Ajay"));

        senderTheard.start();
        receiverTheard.start();
    }
}