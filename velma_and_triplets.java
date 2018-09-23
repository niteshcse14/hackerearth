import java.io.*;
import java.util.*;
import java.math.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,i,j,k;
        N=sc.nextInt();
        int arr[]=new int[N];
        BigInteger sum=new BigInteger("0");
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        for(i=0;i<N;i++)
        {
            for(j=i+1;j<N;j++)
            {
                for(k=j+1;k<N;k++)
                {
                    double add=Math.floor((arr[i]+arr[j]+arr[k])/(arr[i]*arr[j]*arr[k]));
                    sum=sum.add(new BigInteger(String.valueOf((int)add)));
                }
            }
        }
        System.out.println(sum);
    }
}
