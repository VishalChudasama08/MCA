import java.util.Scanner;

interface MedicalService {
    void admit();
    void discharge() throws InvalidDischargeException;
}

class Patient implements MedicalService {

    int patientId;
    String name;
    boolean isAdmitted = false;

    // Constructor
    Patient(int patientId, String name) {
        this.patientId = patientId;
        this.name = name;
    }

    public void admit() {
        isAdmitted = true;
        System.out.println("Patient admitted successfully.");
    }

    public void discharge() throws InvalidDischargeException {
        if (!isAdmitted) {
            throw new InvalidDischargeException("Patient is not admitted!");
        }
        isAdmitted = false;
        System.out.println("Patient discharged successfully.");
    }

    void display() {
        System.out.println("Patient ID: " + patientId);
        System.out.println("Name: " + name);
        System.out.println("Admitted Status: " + isAdmitted);
    }
}


public class HospitalDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Patient ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Patient Name: ");
        String name = sc.nextLine();

        Patient p = new Patient(id, name);

        try {
            p.discharge();   // Trying to discharge before admitting
        } catch (InvalidDischargeException e) {
            System.out.println("Error: " + e.getMessage());
        }

        p.admit();

        try {
            p.discharge();   // Now valid discharge
        } catch (InvalidDischargeException e) {
            System.out.println("Error: " + e.getMessage());
        }

        p.display();
    }
}