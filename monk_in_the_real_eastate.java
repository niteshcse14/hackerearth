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
            int E,x,y,i,j=0,count=0,l=0,flag_x=0,flag_y=0;
            E=sc.nextInt();
            int arr[]=new int[1000];
            for(i=0;i<E;i++)
            {
                x=sc.nextInt();
                y=sc.nextInt();
                for(j=0;j<1000;j++)
                {
                    if(arr[j]!=x && flag_x!=1)
                    {
                        flag_x=0;
                    }
                    else
                    {
                        flag_x=1;
                        break;
                    }
                }
                
                 if(flag_x==0)
                {
                    arr[l]=x;
                    l++;
                }
                
                
                for(j=0;j<1000;j++)
                {
                    
                    if(arr[j]!=y && flag_y!=1)
                    {
                        flag_y=0;
                    }
                    else
                    {
                        flag_y=1;
                        break;
                    }
                }
                
                
                if(flag_y==0)
                {
                    arr[l]=y;
                    l++;
                }
                //l++;
            }
            System.out.println(l);
            
        }
    }
}
