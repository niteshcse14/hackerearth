import java.io.*;
import java.util.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int count=0,i;
         String str=sc.next();
         for(i=0;i<str.length();i++)
         {
            if(str.charAt(i)=='A' ||str.charAt(i)=='E' ||str.charAt(i)=='I' ||str.charAt(i)=='O' ||str.charAt(i)=='U' ||str.charAt(i)=='a' ||str.charAt(i)=='e' ||str.charAt(i)=='i' ||str.charAt(i)=='o' ||str.charAt(i)=='u')
            {
               count++;
            }
         }
         System.out.println(count);
      }
   }
}
