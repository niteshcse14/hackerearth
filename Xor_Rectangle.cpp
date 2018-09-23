#include <bits/stdc++.h>
using namespace std;
#define N 100005
void update(int ){
	//
}
void constructAUX(){
	for(int i = 0; i <= N; ++i){
		for(int j = 0; j <= N; ++j){
			aux[i][j] = 0;
		}
	}
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			aux[i][j] = arr[N - j][i - 1];
		}
	}
}
void construct2DBIT(){
	int aux[N + 1][N + 1];
}
int main(){
	//
	return 0;
}