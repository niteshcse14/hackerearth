import java.io.*;
import java.util.*;
class HE
{
	public static void main(String[] args)
	{
	    Scanner sc=new Scanner(System.in);
	    int n,i,j,odd=0,even=0;
	    n=sc.nextInt();
	    int arr[]=new int[n];
	    for(i=0;i<n;i++)
	    {
	        arr[i]=sc.nextInt();
	    }
	    for(i=0;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            if((arr[i]+arr[j])%2==0)
	            {
	                even++;
	            }
	            else
	            {
	                odd++;
	            }
	        }
	    }
	    System.out.println(Math.abs(odd-even));
	}
}
