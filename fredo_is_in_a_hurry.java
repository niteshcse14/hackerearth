import java.io.*;
import java.util.*;
import java.math.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        while(T-->0)
        {
            int N,sum=0,floor=0,count=0,i;
            N=sc.nextInt();
           //int ans=0;
            BigInteger c,n,ans=new BigInteger("0"),two=new BigInteger("2"),one=new BigInteger("1");
            if(N>1)
            {
            for(i=1;i<=N;i++)
            {
                floor+=i;
                count++;
                if(floor==(N-count))
                {
                    ans=((new BigInteger(String.valueOf(floor))).add(new BigInteger(String.valueOf(N)))).subtract(new BigInteger(String.valueOf(count)));//floor+N-count;
                    break;
                }
                else if(floor<(N-count))
                {
                    continue;
                }
                else
                {
                    c=new BigInteger(String.valueOf(count));
                    n=new BigInteger(String.valueOf(N));
                    ans=two.multiply(((n).subtract(c)).add(one));//2*(N-count+1);
                    break;
                }
            }
            System.out.println(ans);
            }
            else
            {
                System.out.println(N);
            }
            
        }
    }
}5
6
