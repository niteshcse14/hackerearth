import java.io.*;
import java.util.*;
class HE
{
    public  static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T;
        T=sc.nextInt();
        while(T-->0)
        {
            String str=sc.next(),A="",B="";
            int len=str.length(),i,j;
            if(len%2==0)
            {
                for(i=0,j=len/2;i<len/2 && j<len;i++,j++)
                {
                    A+=String.valueOf(str.charAt(i));
                    B+=String.valueOf(str.charAt(j));
                }
            }
            else
            {
                for(i=0,j=((len/2)+1);i<len/2 && j<len;i++,j++)
                {
                    A+=String.valueOf(str.charAt(i));
                    B+=String.valueOf(str.charAt(j));
                }
            }
            //System.out.println(A+"   "+B);
            if(A.equals(B) && A.length()!=0 && B.length()!=0)
            {
                System.out.println("Yes");
            }
            else
            {
                System.out.println("No");
            }
        }
    }
}
