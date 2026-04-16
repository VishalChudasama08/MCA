import java.util.*; 
 class StackDemo
 { 
 static void show(String s) 
 { 
 System.out.println(s); 
 } 
 public static void main(String args[]) 
 { 
 Stack S = new Stack(); 
 S.push(new Integer(5)); 
 S.push(new Integer(7)); 
 S.push(new Integer(3)); 
 show(“\nStack contents”); 
 show(S + “ “); 
 show(“\nFirst item popped: “ + S.pop()); 
 S.push(“Two”); 
 S.push(“One”); 
 S.push(“Zero”); 
 show(“\nAfter adding some elements”); 
 show(“Stack contents\n”); 
 show(S + “ “); 
 show(“\nFirst item popped:” + S.pop()); 
 show(“\nFirst item peeked:” + S.peek()); 
 show(“\nStack contents”); 
 show(S + “ “); 
 int pos = S.search(new Integer(6)); 
 if (pos != -1) 
 show(“\nFrom top offset of 6 is:” + pos); 
 else 
 show(“\nElement is not in stack”); 
 } 
 }