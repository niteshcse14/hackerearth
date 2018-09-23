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
            int N,i,j;
            N=sc.nextInt();
            int track1[]=new int[N];
            int track2[]=new int[N];
            
            int track_1_to_2[]=new int[N-1];
            int track_2_to_1[]=new int[N-1];
            for(i=0;i<N;i++)
            {
                track1[i]=sc.nextInt();
            }
            for(i=0;i<N;i++)
            {
                track2[i]=sc.nextInt();
            }
            
            for(i=0;i<N-1;i++)
            {
                track_1_to_2[i]=sc.nextInt();
            }
            for(i=0;i<N-1;i++)
            {
                track_2_to_1[i]=sc.nextInt();
            }
            
            int amount=0,k=0;
            while(k<(N-1))
            {
                if(track1[k]<track2[k])
                {
                    amount+=track1[i];
                    if(k==N-1)
                    {
                        break;
                    }
                    else if(track1[k+1]<track2[k+1])
                    {
                        amount+=track_1_to_2[k]+track2[k+1];
                        k++;
                    }
                    else
                    {
                        amount+=track1[k+1];
                        k++;
                    }
                    k++;
                }
                else
                {
                    amount+=track2[k];
                    if(track1[k+1]<track2[k+1])
                    {
                        amount+=track_2_to_1[k]+track1[k+1];
                        k++;
                    }
                    else if(track1[k+1]>track2[k+1])
                    {
                        amount+=track2[k+1];
                        k++;
                    }
                }
            }
            System.out.println(amount);
        }
    }
}
