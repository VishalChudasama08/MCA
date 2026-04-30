package v8.test.SeleniumTestKeepNotes;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class KeepNotesLoginAutomationTest {
    public static void main(String[] args) {

    	System.out.println("KeepNotes Login Automation Test Executed");
    	
        WebDriver driver = new ChromeDriver();

        // hit site api
        driver.get("http://localhost:8080/login");

        // Enter login details
        driver.findElement(By.name("email")).sendKeys("vishal@gmail.com");
        driver.findElement(By.name("password")).sendKeys("12345678");

        // Click login
        driver.findElement(By.xpath("//button[@type='submit']")).click();

        try { Thread.sleep(3000); } catch(Exception e){}

        System.out.println("KeepNotes Login Automation Test Done");

        driver.quit();
    }
}