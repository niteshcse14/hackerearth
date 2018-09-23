import java.io.*;
import java.util.*;
class HE
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        int i=0,j=0,k;
        for(k=0;k<str.length();k++)
        {
            if(str.charAt(k)=='L')
            {
                i--;
            }
            else if(str.charAt(k)=='R')
            {
                i++;
            }
            else if(str.charAt(k)=='U')
            {
                j++;
            }
            else if(str.charAt(k)=='D')
            {
                j--;
            }
        }
        System.out.println(i+" "+j);
    }
}
