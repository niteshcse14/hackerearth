import java.io.*;
import java.util.*;
class HE
{
    int max(int arr[][],int row,int N)
    {
        int i=0,max=arr[row][0];
        for(i=0;i<N;i++)
        {
            if(max<arr[row][i])
            {
                max=arr[row][i];
            }
        }
        return max;
    }
    
    
    
    int check_avail(int arr[][],int K,int N,int row)
    {
        int i=0,flag=0;//=arr[row][0];
        for(i=0;i<N;i++)
        {
            if(K==arr[row][i])
            {
                flag=i;
            }
        }
        return flag;
    }
    
     int max_index(int arr[][],int max,int N,int row)
    {
        int i=0,flag=0;
        for(i=0;i<N;i++)
        {
            if(max==arr[row][i])
            {
                flag=i;
            }
        }
        return flag;
    }
    
    public static void main(String[] args)
    {
        HE he=new HE();
        Scanner sc=new Scanner(System.in);
        int N,K,L,R,i,j;
        N=sc.nextInt();
        K=sc.nextInt();
        L=sc.nextInt();
        R=sc.nextInt();
        
        int arr_1[][]=new int[N][N];
        int arr[][]=new int[N][N];
        
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                arr_1[i][j]=sc.nextInt();
            }
        }
        
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                arr[i][j]=sc.nextInt();
            }
        }
        
        int count=0,ii=0,max=0,K_avail=0,index=0;
        
        for(i=N-1;i>=0;i--)
        {
                K_avail=he.check_avail(arr,K,N,i);
                max=he.max(arr,i,N);
                //System.out.println("i = "+i+" K_avail "+K_avail+" max = "+max);
                if(K_avail!=0)
                {
                    count++;
                }
                else if(max>K)
                {
                    count++;  
                }
            
        }
        System.out.println(count);
        
        for(i=N-1;i>=0;i--)
        {
                K_avail=he.check_avail(arr,K,N,i);
                max=he.max(arr,i,N);
                index=he.max_index(arr,max,N,i);
                //System.out.println("i = "+i+" K_avail "+K_avail+" max = "+max);
                //System.out.println("MAX index = "+index);
                if(K_avail!=0)
                {
                    System.out.println((i+1)+" "+(K_avail+1));
                    //count++;
                }
                else if(max>K)
                {
                    System.out.println((i+1)+" "+(index+1));
                    //count++;  
                }
            
        }
        /*
        int arr3[]=new int[2*count];
        for(i=N-1;i>=0;i--)
        {
                K_avail=he.check_avail(arr,K,N,i);
                max=he.max(arr,i,N);
                
                if(K_avail!=0)
                {
                    arr3[ii]=i+1;
                    ii++;
                    arr3[ii]=K_avail+1;
                    ii++;
                    
                }
                else if(max>K)
                {
                    index=he.max_index(arr,max,N,i);
                    arr3[ii]=i+1;
                    ii++;
                    arr3[ii]=index+1;
                    ii++;
                    
                }
            
        }
        */
        //System.out.println(count);
       /*
        for(i=0;i<K;i++)
        {
            for(j=0;j<2;j++)
            {
                System.out.print(arr3[j]+" ");
            }
            System.out.println();
        }
        */
    }
}
