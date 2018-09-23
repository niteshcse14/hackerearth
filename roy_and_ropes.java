import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        while(T-->0)
        {
            int L,i,j,count_u=0,sum=0;
            L=sc.nextInt();
            int arr[]=new int[L];
            int arr_u[]=new int[L-1];
            int arr_l[]=new int[L-1];
            
            for(i=0;i<L;i++)
            {
                arr[i]=1;
            }
            for(i=0;i<L-1;i++)
            {
                arr_u[i]=sc.nextInt();
            }
            for(i=0;i<L-1;i++)
            {
                arr_l[i]=sc.nextInt();
            }
            for(i=0;i<L-1;i++)
            {
                if(arr_u[i]!=0)
                    arr_u[i]=arr_u[i]-1;
                    
                if(arr_l[i]!=0)
                    arr_l[i]=arr_l[i]-1;
                    
                if(arr[i+1]!=0)
                    arr[i+1]=arr[i+1]-1;
            }
            for(i=0;i<L-1;i++)
            {
                sum+=arr_u[i]+arr_l[i];
            }
            System.out.println(sum+L-1);
        }
    }
}
