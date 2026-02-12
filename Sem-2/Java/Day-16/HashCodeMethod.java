class HashCodeMethod{
    int id = 10;
    @Override
    public int hashCode(){
        return id*31;
    }
    public static void main(String [] arg){
        HashCodeMethod h = new HashCodeMethod();
        System.out.println(h.hashCode());
    }
}