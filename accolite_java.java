import java.io.*;
import java.util.*;
class HE
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,M,i,j;
      N=sc.nextInt();
      M=sc.nextInt();
      
      int monk[]=new int[N];
      int monk1[]=new int[M];
       int f_i[]=new int[N];
      int g_i[]=new int[M];
      
      for(i=0;i<N;i++)
      {
         monk[i]=sc.nextInt();
      }
      
      for(i=0;i<M;i++)
      {
         monk1[i]=sc.nextInt();
      }
      
      Arrays.sort(monk);
      Arrays.sort(monk1);
      
      int mk;
      for(i=0;i<N;i++)
      {
         mk=0;
         for(j=0;j<M;j++)
         {
            if(monk[i]>monk1[j])
            {
               mk++;
            }
         }
         f_i[i]=mk;
      }
      
      int mk1,ans=0;
      for(i=0;i<N;i++)
      {
         mk1=0;
         for(j=0;j<M;j++)
         {
            if(monk[i]<monk1[j])
            {
               mk1++;
            }
         }
         g_i[i]=mk1;
      }
      for(i=0;i<N;i++)
      {
         ans=ans+f_i[i]*g_i[i];
      }    
      
      
      
      int mk_1;
      for(i=0;i<M;i++)
      {
         mk_1=0;
         for(j=0;j<N;j++)
         {
            if(monk1[i]>monk[j])
            {
               mk_1++;
            }
         }
         f_i[i]=mk_1;
      }
      
      
      int mk1_1,ans_1=0;
      for(i=0;i<M;i++)
      {
         mk1_1=0;
         for(j=0;j<N;j++)
         {
            if(monk1[i]<monk[j])
            {
               mk1_1++;
            }
         }
         g_i[i]=mk1_1;
      }
      for(i=0;i<N;i++)
      {
         ans_1=ans_1+f_i[i]*g_i[i];
      }    
      
      if(ans==ans_1)
         System.out.println("Tie");
      else if(ans>ans_1)
         System.out.println("Monk "+(ans-ans_1));
      else
         System.out.println("!Monk "+(ans_1-ans));
     
   }
}
