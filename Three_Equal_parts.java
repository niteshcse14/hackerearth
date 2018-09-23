import java.util.*;
 
class Three_Equal_parts {
    
    public static int strip(int[] array, int start, int limit) {
        int result = start;
        while(result < limit && array[result] == 0)
            result += 1;
        return result;
    }
    
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        
        int tests = s.nextInt();
        while(tests-- > 0) {
            
            int counter = 0;
            int n = s.nextInt();
            int[] array = new int[n];
 
            for(int i = 0; i < n; i++) {
                array[i] = s.nextInt();
                counter += array[i];
            }
            
            if(counter == 0) {
                System.out.println(0);
            } else if(counter % 3 == 0) {
                int i = n - 1;
                while(i >= 0 && array[i] == 0) i--;
                int j = 0;
                for(int k = counter / 3; k > 0; k -= array[j], j++);
                int firstLimit = j - 1 + n - i;
            	System.out.println(i+" "+j+" "+firstLimit);
                int firstStart = strip(array, 0, firstLimit);
                int secondStart = strip(array, firstLimit, n);
                System.out.println(firstStart+"  "+secondStart);
                while(firstStart < firstLimit && secondStart < n && array[firstStart] == array[secondStart]) {
                    firstStart++;
                    secondStart++;
                }
                
                if(firstStart == firstLimit) {
                    int thirdStart = strip(array, secondStart, n);
                    firstStart = strip(array, 0, firstLimit);
                    while(firstStart < firstLimit && array[firstStart] == array[thirdStart]) {
                        firstStart++;
                        thirdStart++;
                    }
                    if(firstStart == firstLimit) {
                        long result = 0;
                        long coeff = 1;
                        for(int k = firstLimit - 1; k >= 0; k--) {
                            result += (array[k] * coeff);
                            result %= 1000000007L;
                            coeff *= 2;
                            coeff %= 1000000007L;
                        }
                        System.out.println(result);
                    } else {
                        System.out.println(-1);
                    }
                } else {
                    System.out.println(-1);
                }
            } else {
                System.out.println(-1);
            }
        }
        
        s.close();
    }
}