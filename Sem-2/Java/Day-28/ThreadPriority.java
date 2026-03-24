class DemoWorker implements Runnable {
    public void run(){
        String name = Thread.currentThread().getName();
        System.out.println("Thread: " + name + " has started.\n");

        for(int i=1; i<=3; i++){
            try {
                System.out.println(name + " processing step " + i);
                Thread.sleep(1000);
            } catch (InterruptedException e){
                System.out.println( name + " was interrupted!");
                return;
            }
        }

        System.out.println(name + " has finished.\n");
    }
}

class ThreadPriority {
    public static void main(String [] atgs){
        Thread t1 = new Thread(new DemoWorker(), "Thread-max");
        Thread t2 = new Thread(new DemoWorker(), "Thread-min");

        // 1. setting priorities
        t1.setPriority(Thread.MAX_PRIORITY);
        t2.setPriority(Thread.MIN_PRIORITY);

        t1.start();
        t2.start();

        // isAlive(): checks if thread is still running
        System.out.println(t1.getName() + " is alive: " + t1.isAlive());
        System.out.println(t2.getName() + " is alive: " + t2.isAlive());

        try {
            // join();  
            System.out.println("Main thread waiting for " + t1.getName() + " to finish...");
            t1.join(); // kill therad 1
            System.out.println(t1.getName() + " is alive: " + t1.isAlive());

            // interrupt(): send an interrupt signal to t2
            System.out.println("Main thread is impatient! Interrupting " + t2.getName());
            t2.interrupt();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread execution finished.");
    }
}