#include <bits/stdc++.h>
using namespace std;
 int main()
 {
 	int N, K, Q;
 	cin >> N;
 	int arr[N];
 	for(int i = 0; i < N; i++)
 	{
 		cin >> arr[i];
 	}
 	cin >> Q;
 	while(Q--)
 	{
 		cin >> K;
 		for(int i = 0; i < N; i++)
 		{
 			if(arr[i] > K)
 			{
 				arr[i] -= 1;
 			}
 		}
 	}
 	for(int i = 0; i < N; i++)
 	{
 		cout << arr[i] << " ";
 	}
 	printf("\n");
 	return 0;
 }
//Little_Deepu_and_Array.cpp