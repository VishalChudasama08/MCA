class Game { 
	String pname; 
	int points; 
	Game(String pname, int points) 
	{ 
		this.pname = pname; 
		this.points = points; 
	} 
	void show() 
	{ 
		System.out.print("Name := " + this.pname); 
		System.out.println("\tPoints :=" + this.points); 
	} 
	Game check(Game g) 
	{ 
		if (this.points > g.points) 
			return this; 
		else 
			return g; 
	} 
	
 } 
 class ReturnCurrentObject
 { 
	public static void main(String args[]) 
	{ 
		Game g1 = new Game("Hari", 1560); 
		Game g2 = new Game("Man", 1665); 
		System.out.println("\n++++++++++++++++++++++++"); 
		System.out.println("\tPlayer-1"); 
		System.out.println("**************************"); 
		g1.show(); 
		System.out.println("\n************************"); 
		System.out.println("\tPlayer-2"); 
		System.out.println("++++++++++++++++++++++++++"); 
		g2.show(); 
		Game winner; 
		winner = g1.check(g2); 
		System.out.print("\n Winner is " + winner.pname); 
		System.out.println(" with "+winner.points+"  points"); 
	} 
 } 