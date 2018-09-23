import java.io.*;
import java.util.*;
class HE
{
        public static void main(String[] args)
        {
            Scanner sc=new Scanner(System.in);
            int T,j=-1,i;
            T=sc.nextInt();
            while(T-->0)
            {
                String str=sc.next();
                
                for(i=0;i<(str.length());i++)
                {
                    if((int)(str.charAt(i))>96)
                    {
                        System.out.print(str.charAt(i));;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(j==-1)
                 {
                    j++;
                    System.out.println();
                    continue;
                 }
                 else
                 {
                    System.out.print(j);
                    System.out.println();
                 }
                 j++;
            }
        }
}
