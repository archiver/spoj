import java.util.Scanner;

class Main
{
   public static void main(String args[])
   {
       Scanner in = new Scanner(System.in);
       int num;
       while(true)
       {
          num=in.nextInt();
          if(num==42) break;
          System.out.println(num);
       }
   }
}
