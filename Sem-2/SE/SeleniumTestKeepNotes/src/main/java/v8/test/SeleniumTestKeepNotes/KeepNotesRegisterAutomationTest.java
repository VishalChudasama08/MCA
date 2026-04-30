package v8.test.SeleniumTestKeepNotes;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class KeepNotesRegisterAutomationTest {
	public static void main(String[] args) {

    	System.out.println("KeepNotes Register Automation Test Executed");
    	
        WebDriver driver = new ChromeDriver();

        // hit site api
        driver.get("http://localhost:8080/register");

        // Enter Register details
        driver.findElement(By.name("firstName")).sendKeys("Vishal");
        driver.findElement(By.name("lastName")).sendKeys("Chudasama");
        driver.findElement(By.name("email")).sendKeys("vishal3@gmail.com");
        driver.findElement(By.name("password")).sendKeys("12345678");
        driver.findElement(By.name("cPassword")).sendKeys("12345678");
        driver.findElement(By.name("phoneNumber")).sendKeys("9876543210");
        
        try { Thread.sleep(200); } catch(Exception e){}

        // Click login
        driver.findElement(By.xpath("//button[@type='submit']")).click();

        try { Thread.sleep(3000); } catch(Exception e){}

        System.out.println("KeepNotes Register Automation Test Done");

        driver.quit();
    }
}
