// A task representing a kitchen activity
class KitchenTask implements Runnable {
    private String taskName;
    private int timeNeeded; // in seconds

    public KitchenTask(String name, int time) {
        this.taskName = name;
        this.timeNeeded = time;
    }

    @Override
    public void run() {
        System.out.println("Started: " + taskName);
        try {
            // Simulate the time it takes to do the task
            for(int i = 1; i <= timeNeeded; i++) {
                Thread.sleep(1000); // 1 second per step
                System.out.println("  [" + taskName + "] is " + (i * 100 / timeNeeded) + "% done...");
            }
        } catch (InterruptedException e) {
            System.out.println(taskName + " was interrupted!");
        }
        System.out.println("FINISHED: " + taskName);
    }
}

public class KitchenDemo {
    public static void main(String[] args) {
        System.out.println("--- Chef starts the meal ---");

        // Create the tasks
        Thread pasta = new Thread(new KitchenTask("Boiling Pasta", 5));
        Thread sauce = new Thread(new KitchenTask("Simmering Sauce", 3));
        Thread salad = new Thread(new KitchenTask("Chopping Salad", 2));

        // Start all tasks simultaneously
        pasta.start();
        sauce.start();
        salad.start();

        System.out.println("--- Chef is monitoring all pots! ---");
    }
}
/*
If a task takes 5 seconds (timeNeeded = 5) and we are currently at second 2 (i = 2):

Multiplication first: 2 * 100 = 200

Division second: 200 / 5 = 40

Result: "40% done..."
*/