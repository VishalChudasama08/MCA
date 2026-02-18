class Mobile {

    interface Camera {
        void click();
    }

    interface Battery {
        void charge();
    }
}

class SmartPhone implements Mobile.Camera, Mobile.Battery {

    public void click() {
        System.out.println("Photo Clicked");
    }

    public void charge() {
        System.out.println("Charging...");
    }

    // Main Method Added Here
    public static void main(String[] args) {

        SmartPhone sp = new SmartPhone();

        sp.click();    // Calling Camera method
        sp.charge();   // Calling Battery method
    }
}
