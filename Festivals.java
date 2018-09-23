import java.io.*;
import java.util.*;
class node {
	static String str;
	static int val;
	node (String str, int val) {
		node.str = str;
		node.val = val;
	}
}
class Festival {
	static int t, n, val, sz;
	static String str, res;
	public static void main (String args[]) throws Exception{
		Scanner ss = new Scanner (System.in);
		t = ss.nextInt();
		while (t > 0) {
			HashMap <String, ArrayList<Integer> > mp = new HashMap <> ();
			t--;
			n = ss.nextInt ();
			for (int i = 0; i < n; ++i) {
				str = ss.next ();
				val = ss.nextInt ();
				mp.putIfAbsent(str, new ArrayList<Integer>());
				mp.get(str).add(val);
			}
			long ans = 0, sum;
			res = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
			for (Map.Entry entry : mp.entrySet()){
				str = (String)entry.getKey();
				ArrayList<Integer> arr = mp.get(str);
				Collections.sort (arr);
				sum = 0;
				sz = arr.size();
				for(int j = sz - 1; j >= (sz - 3) && j >= 0; --j)
					sum += arr.get(j);
				if(sum > ans){
					ans = sum;
					res = str;
				}
				else if (sum == ans) {
					if (str.compareTo(res) < 0) {
						ans = sum;
						res = str;
					}
				}
				//System.out.println("Result  " + ans + "  " + res + "  "+ arr.size ());
			}
			System.out.println(res + " " + ans);
		}
	}
}