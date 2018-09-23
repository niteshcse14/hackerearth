import java.io.*;
import java.util.*;
import java.math.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int N,i,j,max=0,flag=0;
        //int l=0;
        N=sc.nextInt();
        int arr[]=new int[N+1];
        arr[0]=0;
        int arr_x[]=new int[N+1];
        arr_x[0]=0;
        int arr_y[]=new int[N+1];
        arr_y[0]=0;
        int dup[]=new int[N];
        for(i=1;i<=N;i++)
        {
            arr[i]=sc.nextInt();
        }
      
      /*  
        int ll=0;
        for(i=1;i<=N;i++)
        {
            l=0;
            ll=0;
            flag=0;
            dup=new int[N-1];
            for(j=1;j<=N;j++)
            {
                if(i>arr[j])
                {
                    dup[l]=arr[j];
                    //ll++;
                    l++;
                }
            }
            //System.out.println("duplicate array");
            int arr_dup[]=new int[l];
            for(int ii=0;ii<l;ii++)
            {
                arr_dup[ii]=dup[ii];
                System.out.print(dup[ii]+" ");
            }
            System.out.println();
            
            if(l==0)
            {
                arr_x[i]=-1;
            }
            else
            {
                Arrays.sort(arr_dup);
                System.out.println("length = "+l);
                max=arr_dup[l-1];
                //System.out.println("max = "+max +" length = "+l);
                //l--;
                System.out.println("MAX = "+max+" arr[max] = "+arr[max]);
                int count=0;
                while(l!=0)
                {
                    if(count<1)
                    {
                        l=l-1;
                        count++;
                    }
                    if(arr[max]>arr[i])
                    {
                        flag=1;
                        System.out.println("if max = "+max+" i = "+i);
                        break;
                    }
                    else
                    {
                        l--;
                        max=arr_dup[l];
                        System.out.println("else max = "+max+" i = "+i);
                    }
                }
                if(flag==1)
                {
                    arr_x[i]=max;
                }
                else
                {
                    arr_x[i]=-1;
                }
            }
            System.out.print(arr_x[i]);
            System.out.println();
            System.out.println();
            System.out.println();
        }
       
        System.out.println("output ");
        for(i=1;i<=N;i++)
        {
            System.out.print(arr_x[i]+" ");
        }
        System.out.println();
        
        
        */
        
        
        
        
        
        
        
        int zz=0,min=0;
        flag=0;
         for(i=1;i<=N;i++)
        {
            zz=0;
            //ll=0;
            flag=0;
            dup=new int[N-1];
            for(j=1;j<=N;j++)
            {
                if(i>arr[j])
                {
                    dup[zz]=arr[j];
                    //ll++;
                    zz++;
                }
            }
            System.out.println("duplicate array");
            int arr_dup[]=new int[zz];
            for(int ii=0;ii<zz;ii++)
            {
                arr_dup[ii]=dup[ii];
                System.out.print(arr_dup[ii]+" ");
            }
            System.out.println();
            
            if(zz==0)
            {
                arr_y[i]=-1;
            }
            else
            {
                Arrays.sort(arr_dup);
                System.out.println("length = "+zz);
                min=arr_dup[0];
                
                System.out.println("MIN = "+max+" arr[min] = "+arr[min]);
                int zzz=0;
                while(zzz!=zz)
                {
                    if(arr[min]<arr[i])
                    {
                        flag=1;
                        System.out.println("if min = "+min+" i = "+i);
                        break;
                    }
                    else
                    {
                        //zzz++;
                        min=arr_dup[zzz];
                        zzz++;
                        System.out.println("else min = "+min+" i = "+i);
                    }
                }
                if(flag==1)
                {
                    arr_y[i]=max;
                }
                else
                {
                    arr_y[i]=-1;
                }
            }
            System.out.print(arr_y[i]);
            System.out.println();
            System.out.println();
            System.out.println();
        }
       
        System.out.println("output ");
        for(i=1;i<=N;i++)
        {
            System.out.print(arr_y[i]+" ");
        }
        System.out.println();
    }
}
