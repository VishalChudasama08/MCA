class Thread1 extends Thread {
    public void run(){
        try {
            while(true) {
                System.out.println("Thread 1...");
                Thread.sleep(2000);
            }
            
        } catch (InterruptedException e){
            System.out.print(e);
        }
    }
}

class Thread2 extends Thread {
    public void run(){
        System.out.println("Thread 2");
    }
}

class ThreadDemo {
    public static void main(String [] args){
        Thread1 t1 = new Thread1();
        t1.start();

        Thread2 t2 = new Thread2();
        t2.start();

    }
}