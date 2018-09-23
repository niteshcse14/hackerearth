import java.io.*;
import java.util.*;
import java.math.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T;
      T=sc.nextInt();
      while(T-->0)
      {
         int i,count=0,count1=0,j=0,k,ans_suvo=0,ans_suvojit=0;
         String str=sc.next(),str1="SUVOJIT",str2="SUVO";
         char ch[]=new char[str.length()];
         for(i=0;i<str.length();i++)
         {
            if(str.charAt(i)!=str1.charAt(j))
            {
               j=0;
            }
            if(str.charAt(i)==str1.charAt(j))
            {
               j++;
            }
            
            if(j==7)
            {
               j=0;
               ans_suvojit++;
            }
         }
         j=0;
         for(i=0;i<str.length();i++)
         {
            if(str.charAt(i)!=str2.charAt(j))
            {
               j=0;
            }
            if(str.charAt(i)==str2.charAt(j))
            {
               j++;
            }
            if(j==4)
            {
               j=0;
               ans_suvo++;
            }
         }
         if(ans_suvo!=0)
            ans_suvo=ans_suvo-ans_suvojit;
         System.out.println("SUVO = "+ans_suvo+", SUVOJIT = "+ans_suvojit);
      }
   }
}
