import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        int K,i=0;
        K=sc.nextInt();
        char ch[]=str.toCharArray();
        while(K-->0)
        {
            if(str.charAt(i)=='9')
            {
                K++;
            }
            else if(str.charAt(i)!='9')
            {
                ch[i]='9';
            }
            i++;
        }
        System.out.println(new String(ch));
    }
}
