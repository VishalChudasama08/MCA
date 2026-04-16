/*
Write program using multiple Thread A student studies while listening to music. 
Each activity is a separate thread.



*/
class StudyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Student is studying... ");
            try {
                Thread.sleep(1000); // Simulating time taken to study
            } catch (InterruptedException e) {
                System.out.println("Study interrupted!");
            }
        }
    }
}

class MusicThread implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Student is listening to music... ");
            try {
                Thread.sleep(800); // Simulating time taken to listen
            } catch (InterruptedException e) {
                System.out.println("Music interrupted!");
            }
        }
    }
}

public class Prog65 {
    public static void main(String[] args) {
        StudyThread study = new StudyThread();
	
        Thread music = new Thread(new MusicThread());

        // Start both threads
        study.start();
        music.start();
    }
}
