class India{
    void showIndia(){
        System.out.println("India");
    }
}
class Gujarat extends India{
    void showGujarat(){
        System.out.println("Gujarat");
    }
}
class Dwarka extends India{
    void showDwarka(){
        System.out.println("Dwarka");
    }
}

class Inheritence{
    public static void main(String[] arg){
        Dwarka d = new Dwarka();
        d.showDwarka();
        d.showIndia();

        Gujarat g = new Gujarat();
        g.showGujarat();
        g.showIndia();
    }
}