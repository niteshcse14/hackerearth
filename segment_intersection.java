import java.io.*;
import java.util.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int T=0;
      T=sc.nextInt();
      while(T>0)
      {
         int l1=0,r1=0,l2=0,r2=0,i=0,j=0,len_seg1=0,len_seg2=0,count=0,k=0,m=0;
         l1=sc.nextInt();
         r1=sc.nextInt();
         l2=sc.nextInt();
         r2=sc.nextInt();
         int c_arr[]=new int[r1-l1+1],c_arr1[]=new int[r2-l2+1];
         for(i=l1;i<=r1;i++)
         {
            c_arr[k]=i;
            k++;
         }
         for(j=l2;j<=r2;j++)
         {
            c_arr1[m]=j;
            m++;
         }
        /*
         System.out.println("c_arr seg1");
         for(i=0;i<k;i++)
         {
            System.out.print(c_arr[i]+" ");
         }
         System.out.println("\nc_arr1 seg2");
         for(i=0;i<m;i++)
         {
            System.out.print(c_arr1[i]+" ");
         }
         System.out.println();
         */
         len_seg1=k;
         len_seg2=m;
         if(len_seg1>=len_seg2)
         {
            for(i=0;i<len_seg1;i++)
            {
               for(j=0;j<len_seg2;j++)
               {
                  if(c_arr[i]==c_arr1[j])
                  {
                     count++;
                     break;
                  }
               }
            }
         }
         else
         {
            for(i=0;i<len_seg2;i++)
            {
               for(j=0;j<len_seg1;j++)
               {
                  if(c_arr[j]==c_arr1[i])
                  {
                     count++;
                     break;
                  }
               }
            }
         }
                 System.out.println(count);
         T--;
      }      
   }
}
