class Country{
    String countryName = "India";
    public void displayCountry(){
        System.out.println("Country name: " + countryName);
    }
}

class State extends Country {
    String stateName = "Gujarat";
    public void displayState(){
        System.out.println("State name: " + stateName);
    }
}

class City extends State { // multi level inheritence
    String cityName = "Ahemdabad";
    public void displayCity(){
        System.out.println("City name: " + cityName);
    }
}

class University {
    String universityName = "LJU";
    public void displayUniversityDetails(){
        System.out.println("University name: " + universityName);
    }
}

class Dept extends University { // simple inheritence
    String dept = "MCA";
    public void displayDept(){
        System.out.println("Department name: " + dept);
    }
}

class MultiLevelInheritence{
    public static void main(String arg[]){

        System.out.print("-------------------------\n");
        City c = new City();
        c.displayCountry();
        c.displayState();
        c.displayCity();

        System.out.print("-------------------------\n");
        Dept d = new Dept();
        d.displayUniversityDetails();
        d.displayDept();

        System.out.print("-------------------------\n");
    }
}