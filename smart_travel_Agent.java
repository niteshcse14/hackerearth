import java.io.*;
import java.util.*;
class HR
{
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      int N,R,i,j,S,D,wt;
      N=sc.nextInt();
      R=sc.nextInt();
      
      int arr[][]=new int[N][N];
      
      for(i=0;i<R;i++)
      {
         S=sc.nextInt();
         D=sc.nextInt();
         wt=sc.nextInt();
         arr[S-1][D-1]=arr[D-1][S-1]=wt;
      }
      
      source=sc.nextInt();
      dest=sc.nextInt();
      max_wt=sc.nextInt();
      
      
   }
}
