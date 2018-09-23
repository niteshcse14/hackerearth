import java.io.*;
import java.util.*;
class HR
{
    long long int gcd(long long int a,long long int b)
    {
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }
    public static void main(String[] args)
    {
        HR hr=new HR();
        Scanner sc=new Scanner(System.in);
        long long int N,i,j,flag,temp,min=0;
        N=sc.nextInt();
        long long int arr[]=new long long int[N];
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        long long int index=0;
        for(i=0;i<N;i++)
        {
            temp=0;
            flag=0;
            min=0;
            for(j=0;j<N;j++)
            {
                if(i!=j && hr.gcd(arr[i],arr[j])>1)
                {
                    if(temp==0)
                    {
                        min=Math.abs(i-j);
                        index=j;
                        temp++;
                        
                    }
                    else if(min>Math.abs(i-j))
                    {
                        min=Math.abs(i-j);
                        index=j;
                    }
                    flag=1;
                }
            }
            if(flag==1)
            {
                System.out.print((index+1)+" ");
            }
            else
            {
                System.out.print("-1 ");
            }
        }
        System.out.println();
    }
}
