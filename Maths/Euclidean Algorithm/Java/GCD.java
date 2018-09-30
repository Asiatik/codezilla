public class GCD{
    
    public static int gcd(int a, int b){
        if ( a==0 || b==0){
            return a+b;
        }
        return gcd(b, b % a)
    }
    
    public static void main(String args[]){
    }
}
