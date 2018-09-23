import java.io.*;
import java.util.*;
class HE
{
   public static void main(String[] args)throws Exception
   {
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      String str=br.readLine();
      StringBuffer buffer=new StringBuffer(String.valueOf(str));
      buffer.reverse();
      String str1=String.valueOf(buffer);
      if(str.equals(str1))
      {
         System.out.println("YES");
      }
      else
      {
         System.out.println("NO");
      }
   }
}
