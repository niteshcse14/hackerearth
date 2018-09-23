// C++ program to find number of pairs with
// product less than k in a sorted array
#include <bits/stdc++.h>
using namespace std;
 
// Function to count the pairs
int fun(int A[], int n, int k)
{
    // count to keep count of
    // number of pairs with product
    // less than k
    int count = 0;
    int i = 0;
    int j = n - 1;
 
    // Traverse the array
    while (i < j) {
    	printf("out  %d %d %d %d  %d\n", i, j, A[i], A[j], k);
        if (A[i] * A[j] < k) {
            count += (j - i);
            printf("%d  %d\n", i, j);
            i++;
        }
 
        // Else decrement 'j'
        else {
            j--;
        }
    }
 
    // Return count of pairs
    return count;
}
 
// Driver code
int main()
{
 
    int A[] = { 2, 3, 4, 6, 9 };
    int n = sizeof(A) / sizeof(int);
    int k = 20;
    cout << fun(A, n, k) << endl;
 
    return 0;
}