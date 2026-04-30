package v8.test.SeleniumTestKeepNotes;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class KeepNotesCreateNewNoteAutomationTest {
	public static void main(String[] args) {
    	System.out.println("KeepNotes Create New Note Automation Test Executed");
    	
        WebDriver driver = new ChromeDriver();

        // Login 
        driver.get("http://localhost:8080/login");
        driver.findElement(By.name("email")).sendKeys("vishal3@gmail.com");
        driver.findElement(By.name("password")).sendKeys("12345678");
        driver.findElement(By.xpath("//button[@type='submit']")).click();
        try { Thread.sleep(2000); } catch(Exception e){}
        
        // create note
        driver.get("http://localhost:8080/NotesHome");
        driver.findElement(By.name("title")).sendKeys("SE Automation Test");
        driver.findElement(By.name("description")).sendKeys("This is First note. By Selenium Automation on 30-04-2026");
        driver.findElement(By.xpath("//button[@type='submit']")).click();
        try { Thread.sleep(3000); } catch(Exception e){}
        
        System.out.println("KeepNotes Create New Note Automation Test Done");
        driver.quit(); // close Chrome
	}
}
