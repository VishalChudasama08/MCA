class MethodOverloading_MethodOverriding{
    public void sum(){ // MethodOverloading
        System.out.println("public void sum()");
    }
    public void sum(int a, int b){ // MethodOverloading
        System.out.println("public void sum(int a, int b)");
    }
    public void sum(int a, int b, int c){ // MethodOverloading
        System.out.println("public void sum(int a, int b, int c)");
    }
    // public int sum(int a, int b){ // MethodOverriding
    //     System.out.println("public int sum(int a, int b)");
    //     return 0;
    // }
    // public float sum(int a, int b){ // MethodOverriding
    //     System.out.println("public float sum(int a, int b)");
    // }
    public int sum(float a, float b){ // MethodOverloading
        System.out.println("public int sum(float a, float b)");
        return 0;
    }
    public int sum(float a, int b){ // MethodOverloading
        System.out.println("public int sum(float a, int b)");
        return 0;
    }
    // public float sum(float a, int b){ // MethodOverriding
    //     System.out.println("public float sum(float a, int b)");
    // }
    public static void main(String arg[]){ 
        MethodOverloading obj = new MethodOverloading();
        obj.sum();

        // MethodOverloading: same name method but argument is diffrent
        // MethodOverriding: same name method but return type is diffrent
    }
}