import java.io.*;
import java.util.*;
import java.math.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int L,N,W,H;
      L=sc.nextInt();
      N=sc.nextInt();
      while(N-->0)
      {
         W=sc.nextInt();
         H=sc.nextInt();
         
         if(W<L || H<L)
            System.out.println("UPLOAD ANOTHER");
         else if(W==H)
            System.out.println("ACCEPTED");
         else
            System.out.println("CROP IT");
      }
   }
}
