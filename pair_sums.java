import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,K,i,j,flag=0;
        N=sc.nextInt();
        K=sc.nextInt();
        int arr[]=new int[N];
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        for(i=0;i<N;i++)
        {
            for(j=i;j<N;j++)
            {
                if((arr[i]+arr[j])==K)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        
        if(flag==1)
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }
}
