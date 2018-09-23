import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String s;
        s=sc.next();
        
        int len=s.length();
        int arr[]=new int[len];
        int index[]=new int[len];
        
        String c;
        c=sc.next();
        
        int p,i,j,k=0,count;
        p=sc.nextInt();
        for(i=0;i<len;i++)
        {
            count=0;
            for(j=i;j<len;j++)
            {
                if(s.charAt(j)!=c.charAt(0))
                {
                    break;
                }
                count++;
            }
            i=j;
            if(count!=0)
            {
                arr[k]=count;
                index[k]=j;
                k++;
            }
        }
        int max=arr[k-1],ind=index[k-1];
        for(i=k-1;i>=0;i--)
        {
            if(max<arr[i])
            {
                max=arr[i];
                ind=index[i];
            }
        }
       if(max==0)
       {
            System.out.println("-1");
       }
       else if(max!=0)
       {
             System.out.println(ind+1);
       }
    }
}
