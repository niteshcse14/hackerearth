import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt(),i,min=0,sum=0;
        int arr[]=new int[N];
        for(i=0;i<N;i++)
        {
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        min=arr[0];
        for(i=0;i<N;i++)
        {
            sum=sum+(arr[i]-min);
        }
        System.out.println(min+sum);
    }
}
