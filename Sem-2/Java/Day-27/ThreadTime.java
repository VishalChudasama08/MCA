import java.util.*;

class ShowTimeThread extends Thread {
    public void run(){
        try {
            while(true) {
                Date d = new Date();
                // Calender cal = Calender.getInstance();
                // cal.setTime(d);

                // System.out.println(cal.get(Calender.HOUR_OF_DAY) +":"+ cal.get(Calender.MINUTE) +":");
                System.out.println(d);
                Thread.sleep(1000);
            }  
        } catch (InterruptedException e){
            System.out.print(e);
        }
        
    }
}

class ThreadTime {
    public static void main(String [] args){
        ShowTimeThread st = new ShowTimeThread();
        st.start();

    }
}