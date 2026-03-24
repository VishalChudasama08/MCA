import java.util.*;

class ShowTimeThread implements Runnable {
    public void run(){
        try {
            while(true) {
                Date d = new Date();

                // StringBuffer sb = new StringBuffer(d);

                // System.out.println(sb);
                System.out.println(d);

                Thread.sleep(1000);
            }  
        } catch (InterruptedException e){
            System.out.print(e);
        }
        
    }
}

class ThreadByRunnable {
    public static void main(String [] args){
        ShowTimeThread st = new ShowTimeThread();
        Thread t = new Thread(st);

        t.start();
    }
}