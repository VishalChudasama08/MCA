import java.util.*;
class ThreadCnt extends Thread {
  String threadName;
  ThreadCnt()
  {
	threadName="Counter  ==>";
	start();
  }
  public void run() {
    try {
	
	
		int cnt=0;
      while(true) {
        Thread.sleep(5000);
        System.out.println(threadName+  +cnt++);
      }
    }
    catch(InterruptedException ex) {
      ex.printStackTrace();
	  }
	
  }
}
class ThreadDate extends Thread {
  String threadName;
  ThreadDate()
  {
	threadName="Date  ==>";
	start();
  }
  public void run() {
    try {
		int cnt=0;
	  
      while(true) {
	  Thread.sleep(1000); 
	  Calendar calendar = Calendar.getInstance();
	  System.out.print(threadName);
	  System.out.println(calendar.get(Calendar.HOUR)+" :" +calendar.get(Calendar.MINUTE)+" : "+calendar.get(Calendar.SECOND));
        
      }
    }
	catch(InterruptedException ex) {
      ex.printStackTrace();
	  }
	
    }//run
  
}
class Thread_Cnt_Date {
  public static void main(String args[]) {
    
    ThreadCnt tcnt = new ThreadCnt();
	ThreadDate tdate =new ThreadDate();
    
	//tdate.start();//call run method Date Thread
	//tcnt.start();//call run method Counter Thread
  }
}