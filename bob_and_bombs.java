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
         int i=0,j,flag=0,w=0,b=0,ans=0;
         String str=sc.next();
         char ch[]=str.toCharArray();
         for(i=0;i<str.length();i++)
         {
            if(ch[i]!='B')
            {
               w_l++;
               //b++;
            }
            
            if(arr[i]==B)
            {
               b++;
            }
            
            if(b>=2)
            {
               if(w_l>=2)
               {
                  ans=ans+2;
               }
               else if(w_l==1)
               {
                  ans=ans+1;
               }
               else
               {
                  ans=ans+0;
               }
               
               if(w_r>=2)
               {
                  ans=ans+2;
               }
               else if(w_r==1)
               {
                  ans=ans+1;
               }
               else
               {
                  ans=ans+0;
               }
               
               w_l=0;
               w_r-=2;
            }
            
            if(b!=0)
            {
               w_r++;
            }
         }
         System.out.println(ans);
      }
   }
}
