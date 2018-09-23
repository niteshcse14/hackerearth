import java.io.*;
import java.util.*;
import java.math.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            int i=0;
            BigInteger two=new BigInteger("2"),n=sc.nextBigInteger(),rem=new BigInteger("0"),sum=new BigInteger("0");
            while(!(String.valueOf(n)).equals("0"))
            {
                rem=n.remainder(two);
                n=n.divide(two);
                i++;
                sum=sum.add(rem);
            }
            BigInteger ii=new BigInteger(String.valueOf(i));
            System.out.println(ii.subtract(sum));
        }
    }
}
