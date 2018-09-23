import java.util.*;
import java.io.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n,N,i,j=0;
        N=sc.nextInt();
        n=N;
        String arr[]=new String[n*4];
        while(n-->0)
        {
            for(i=0;i<4;i++)
            {
                arr[j]=sc.next();
                j++;
            }
        }
        System.out.println("OUTPUT");
        for(i=0;i<N-1;i++)
        {
            for(j=i+4;j<4*N-4;j=j+4)
            {
                if(arr[i].equals(arr[i+j]) || arr[i+1].equals(arr[i+j+1]) || arr[i+2].equals(arr[i+j+2]) || arr[i+3].equals(arr[i+j+3]))
                {
                    System.out.println(i+" "+j);
                }
            }
        }
    }
}
