import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n,q,i,j;
        n=sc.nextInt();
        q=sc.nextInt();
        int arr[]=new int[n];
        for(i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        while(q-->0)
        {
            int type=sc.nextInt();
            if(type==1)
            {
                int l,r,x;
                l=sc.nextInt();
                r=sc.nextInt();
                x=sc.nextInt();
                
                for(i=l-1;i<r;i++)
                {
                    arr[i]=(arr[i])*(x);
                }
            }
            if(type==2)
            {
                int l,r,x,y,count=0;
                l=sc.nextInt();
                r=sc.nextInt();
                x=sc.nextInt();
                y=sc.nextInt();
                
                for(i=l-1;i<r;i++)
                {
                    if(((arr[i])*(x))>=y)
                    {
                        count++;
                    }
                }
                System.out.println(count);
            }
        }
    }
}
