import java.io.*;
import java.util.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      String str;
      str=sc.next();
      int len=0,i=0;
      len=str.length();
      char ch[]=new char[len];
      while(i<len)
      {
         if((int)(str.charAt(i))<=90)
         {
            ch[i]=(char)((int)(str.charAt(i))+32);
         }
         else
         {
            ch[i]=(char)((int)(str.charAt(i))-32);
         }
         i++;
      }
      for(i=0;i<len;i++)
      {
         System.out.print(ch[i]);
      }
      System.out.println();
   }
}
