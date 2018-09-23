import java.io.*;
import java.util.*;
import java.math.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,i;
      String str="";
      N=sc.nextInt();
      int arr[]=new int[N];
      
      for(i=0;i<N;i++)
      {
         arr[i]=sc.nextInt();
      }
      BigInteger ans=new BigInteger("1");
      for(i=0;i<N;i++)
      {
         str=String.valueOf(arr[i]);
         ans=(ans.multiply(new BigInteger(str))).mod(((new BigInteger("10")).pow(9)).add(new BigInteger("7")));
      }
      System.out.println(ans);
   }
}
