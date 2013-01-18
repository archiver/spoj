import java.math.BigInteger;
import java.util.Scanner;

class Main
{
   public static void main(String args[])
   {
     Scanner in = new Scanner(System.in);
     int num = in.nextInt();
     for(int i=0;i<num;++i)
     {
       BigInteger a = new BigInteger(in.next());
       BigInteger b = new BigInteger(in.next());
       System.out.println(a.multiply(b));
     }
   }
}
