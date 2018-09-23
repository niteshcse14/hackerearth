import java.io.*;
import java.util.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int size,n,i=0,j=0,flag=0,count=0,T;
      T=sc.nextInt();
      while(T>0)
      {
         n=sc.nextInt();
         for(i=1;i<=n;i++)
         {
             flag=0;
             for(j=2;j<i;j++)
             {
               if(i%j==0)
               {
                   flag=1;
                   break;
               }
             }
         
            if(flag==0)
            {
                if(n%i==0 && i>1 && i<n)
                {
                     count++;
                }
            }
          }
          if(count!=0)
          {
             System.out.println(n-count);
          }
          else
          {
             System.out.println("0");
          }
         T--;
      }
   }
}
