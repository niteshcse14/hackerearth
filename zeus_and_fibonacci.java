import java.io.*;
import java.util.*;
class HE
{
    int fib(int n)
    {
        int i=0;
        int arr[]=new int[n+1];
        arr[0]=1;
        arr[1]=1;
        for(i=2;i<n;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n-1];
    }
    
    public static void main(String[] args)
    {
        HE he=new HE();
        Scanner sc=new Scanner(System.in);
        int N,i=0,k=0,j=0,type,Q=0,l,r,dif=0,size=0,ii=0,jj=0,ans,sum;

        try
        {
            N=sc.nextInt();
        int arr[]=new int[N];
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        Q=sc.nextInt();
    while(Q-->0)
    {
        type=sc.nextInt();
        l=sc.nextInt();
        r=sc.nextInt();
        
        dif=r-l+1;
        ans=0;
        sum=0;
        int arr1[]=new int[dif];
        if(type==2)
        {
            for(i=l;i<=r;i++)
            {
                for(j=i;j<=r;j++)
                {
                    sum=0;
                    for(k=i;k<=j;k++)
                    {
                        sum+=arr[k-1];
                    }
                    ans+=he.fib(sum);
                }
            }
            
            System.out.println(ans%(1000000000+7));
         }
         else
         {
            arr[l-1]=r;
         }
         /*
         for(i=0;i<N;i++)
         {
         	System.out.print(arr[i]+" ");
         }
         System.out.println();
         */
     }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}
