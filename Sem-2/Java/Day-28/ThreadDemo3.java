class MusicThread extends Thread {
    public void run(){
        for(int i=0; i<5; i++){    
            System.out.println("Student is listening Musice....");
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}
class StudyThread implements Runnable{
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("Student is studying...");
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}
class ThreadDemo3 {
    public static void main(String [] args){
        MusicThread mt = new MusicThread();
        mt.start();

        Thread st = new Thread(new StudyThread());
        st.start();
    }
}