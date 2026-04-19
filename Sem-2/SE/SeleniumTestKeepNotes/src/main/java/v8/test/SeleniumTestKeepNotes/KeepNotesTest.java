package v8.test.SeleniumTestKeepNotes;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class KeepNotesTest {
    public static void main(String[] args) {

        WebDriver driver = new ChromeDriver();

        // Open your Spring Boot app
        driver.get("http://localhost:8080/login");

        // Enter login details
        driver.findElement(By.name("email")).sendKeys("test@gmail.com");
        driver.findElement(By.name("password")).sendKeys("123456");

        // Click login
        driver.findElement(By.xpath("//button[@type='submit']")).click();

        try { Thread.sleep(3000); } catch(Exception e){}

        System.out.println("Automation Test Done");

        driver.quit();
    }
}