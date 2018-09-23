import java.io.*;
import java.util.*;
class HE
{
    int max(int arr[],int n)
    {
        int m=arr[0],i;
        for(i=0;i<n;i++)
        {
            if(m<arr[i])
                m=arr[i];
        }
        return m;
    }
    
    int min(int arr[],int n)
    {
        int m=arr[0],i;
        for(i=0;i<n;i++)
        {
            if(m>arr[i])
                m=arr[i];
        }
        return m;
    }
    public static void main(String[] args)
    {
        HE he=new HE();
        Scanner sc=new Scanner(System.in);
        int N,K,X,i,j,k;
        N=sc.nextInt();
        K=sc.nextInt();
        X=sc.nextInt();
        
        int arr[]=new int[N];
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        int mx=0,mn=0,count=0,ii=0;
        for(i=0;i<N;i++)
        {
            ii=0;
            int sub_arr[]=new int[K];
            sub_arr[ii]=arr[i];
            ii++;
            for(j=0;j<N;j++)
            {
                ii=1;
                sub_arr[ii]=arr[j];
                ii++;
                for(k=0;k<N;k++)
                {
                    //System.out.println(ii+" i = "+i+" j = "+j+" k = "+k);
                    sub_arr[ii]=arr[k];
                    
                    mx=he.max(sub_arr,K);
                    mn=he.min(sub_arr,K);
                    if(Math.abs(mx-mn)<X)
                    {
                        count++;
                        break;
                        //ii--;
                    }
                    //System.out.print(sub_arr[]);
                }
            }
        }
        System.out.println(count);
    }
}
