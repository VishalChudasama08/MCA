class demo{ 
	String str; 
	int num; 
	
	demo(String s) { 
		str=s; 
		System.out.println("Constructor with string argument"+str); //1
	} 
	demo(int x) 
	{ 
		num=x; 
		System.out.println("Consturctor with int  argument"+num); 
	}	 
	demo(String str, int num){ 
		this(str); //call string cons
		this.num=num; 
		System.out.println("Constructor with string & int argument"+str+"  "+num); //2
	} 
	demo(){ 
		this("Default", 235); //call string int const
		System.out.println("Constructor with default argument"); //3
	} 
	void show() 
	{ 
		System.out.println("Show method Str :="+str+"\tnum  :="+this.num); //4
	} 
 } 
 class JPS37 
 { 
 public static void main(String arg[]) 
 { 
	demo d1 = new demo(); //call default
	d1.show(); 
	d1 = new demo(20); 
	d1.show(); 
	d1 = new demo("fun"); 
	d1.show(); 
	d1 = new demo("welcome", 345); 
	d1.show(); 
 } 
 } 