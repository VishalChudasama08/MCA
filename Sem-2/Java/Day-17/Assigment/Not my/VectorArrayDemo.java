import java.util.Scanner;

import javafx.scene.transform.Scale;

class Vector{
     int x,y;
    Vector(int x,int y){
        this.x=x;
        this.y=y;
    }
    void display(){
        System.out.println("x:"+x+"y:"+y);
    }
    class VectorUtils{
       Vector add(Vector v1, Vector v2){
            Vector v3=new Vector(x, y);
            v3.x=v1.x+v2.x;
            v3.y=v1.y+v2.y;
            return v3;
            
     }
     Vector scale(Vector v, int factor)
     {
        v.x =v.x+factor;
        v.y =v.y+factor;
        return v;
     }
        
    }

}

class VectorArrayDemo{
    
   
    public static void main(String[] args) {
        int x,y;
        int a;
        Vector o[]=new Vector[3];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<3;i++){
            System.out.print("enter x and y: ");
            x=sc.nextInt();
            y=sc.nextInt();
            o[i]=new Vector(x, y);
        }
        
        for(int i=0;i<3;i++){
            Vector.add(o[i],new Vector(1,1));
            
            o[i].display();
        }

    }
   
}