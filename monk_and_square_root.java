import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            int N,M,ans=0,flag=1,i;
            N=sc.nextInt();
            M=sc.nextInt();
            for(i=0;;i++)
            {
                if((i*i)%M==N)
                {
                    
                    flag=i;
                    break;
                }
            }
            if(flag==0)
            {
                System.out.println("-1");
            }
            else
            {
                System.out.println(flag);
            }
        }
    }
}
