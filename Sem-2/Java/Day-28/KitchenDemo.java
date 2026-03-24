class KitchenThread implements Runnable {
    private String taskName;
    private int timeNeeded;

    KitchenThread(String taskName, int timeNeeded){
        this.taskName = taskName;
        this.timeNeeded = timeNeeded;
    }

    public void run(){
        System.out.println("Started: " + taskName);
        try {
            for(int i=1; i<=timeNeeded; i++){
                Thread.sleep(1000);
                System.out.println("\t["+taskName+"]: " + ((i*100)/timeNeeded) + "% done...");
            }
        } catch (InterruptedException e){
            System.out.println(taskName + " was interrupted!");
        }
        System.out.println("FINISHED: " + taskName);
    }
}

class KitchenDemo {
    public static void main(String [] args){
        Thread kt1 = new Thread(new KitchenThread("Boil Pasta", 5));
        Thread kt2 = new Thread(new KitchenThread("Chopping Salad", 4));
        Thread kt3 = new Thread(new KitchenThread("Making Sause", 8));

        kt1.start();
        kt2.start();
        kt3.start();

    }
}