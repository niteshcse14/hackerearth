import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,K,count=0,sum=0,i;
        N=sc.nextInt();
        K=sc.nextInt();
        
        int arr[]=new int[N];
        
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        i=0;
        for(i=0;i<N;i++)
        {
            sum=sum+arr[i];
           if(sum<=K)
           {
                count++;
           }
           else
           {
                break;
           }
        }
        System.out.println(count);
    }
}
