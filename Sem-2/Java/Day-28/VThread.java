class VThread implements Runnable {
    public void run(){
        for(int i = 1; i<5; i++){
            System.out.println(i);
            try {
            Thread.sleep(250);
            } catch (InterruptedException e){
                System.out.println(e);
            }
        }
    }
    public static void main(String [] args){
        Thread vt = new Thread(new VThread());

        vt.start();
    }
}