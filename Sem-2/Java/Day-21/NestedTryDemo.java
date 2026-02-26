class NestedTryDemo {
    public static void main(String [] args){
        try {
            int arr[] = {10, 20, 30}; // 3

            try {
                System.out.println(arr[5]); 
            } 
            catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Inner Catch: " + e.getMessage());
            } 
            finally {
                System.out.println("Inner Finally");
            }
        } 
        catch (NumberFormatException e) {
            System.out.println("Outer Catch: " + e.getMessage());
        } 
        finally {
            System.out.println("Inner Finally");
        }
    }
}