 import java.io.*;
 import java.util.*;
 class HE
 {
    void permute(int n[],int N)
    {
        int i,temp,max=0,z=0,j=0,l=0;
        int arr[]=new int[10000];
        String str;
        if(N==n.length-1)
        {
           str="";
            for(i=0;i<n.length;i++)
            {
                str+=String.valueOf(n[i]);
            }
            arr[j]=Integer.parseInt(str);
            j++;
            for(i=0;i<j;i++)
            {
                System.out.println(arr[i]);
            }
            
        }
        else
        {
            for(i=N;i<n.length;i++)
            {
                temp=n[i];
                n[i]=n[N];
                n[N]=temp;
                
                permute(n,N+1);
                
                temp=n[i];
                n[i]=n[N];
                n[N]=temp;
            }
        }
        //System.out.println("j = "+j);
        
    }
    public static void main(String[] args)
    {
        HE he=new HE();
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            int N,i;
            N=sc.nextInt();
            int arr[]=new int[N];
            for(i=0;i<N;i++)
            {
                arr[i]=i+1;
            }
           he.permute(arr,0);
        }
    }
 }
