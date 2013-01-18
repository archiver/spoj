import java.math.BigInteger;
import java.util.Scanner;

class Main
{
  static int gcd(int a, int b)
  {
    if(b==0) return a;
    return gcd(b,a%b);
  }

  public static void main(String args[])
  {
    Scanner in = new Scanner(System.in);
    int num=in.nextInt();
    for(int i=0;i<num;++i)
    {
      BigInteger a = new BigInteger(in.next());
      BigInteger b = new BigInteger(in.next());
      BigInteger rem=b.remainder(a);
      int asmall = a.intValue();
      int bsmall = b.intValue();

      System.out.println(gcd(asmall,bsmall));
    }
  }
}
