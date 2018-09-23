import java.io.*;
import java.util.*;
class TRY
{
    public static void main(String[] args)
    {
       ArrayList<Integer> arrayList = new ArrayList<Integer>();

    arrayList.add(new Integer("3"));
    arrayList.add(new Integer("1"));
    arrayList.add(new Integer("8"));
    arrayList.add(new Integer("3"));
    arrayList.add(new Integer("5"));

    Object obj = Collections.max(arrayList);
    System.out.println(obj);
	  
    }
}
