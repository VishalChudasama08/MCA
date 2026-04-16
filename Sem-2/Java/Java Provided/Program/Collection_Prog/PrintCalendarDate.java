import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class PrintCalendarDate {
    public static void main(String[] args) {
        // 1. Obtain a Calendar instance set to the current time
        Calendar calendar = Calendar.getInstance();
        
        // 2. Convert the Calendar object to a Date object using getTime()
        Date currentDate = calendar.getTime();
        
        // 3. Print the date in the default format
        System.out.println("Current date and time (default format): " + currentDate);
        
        // 4. Optionally, format the date into a specific pattern
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String formattedDate = dateFormat.format(currentDate);
        System.out.println("Current date and time (formatted): " + formattedDate);
    }
}
