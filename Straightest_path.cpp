#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
char s[MAX][MAX];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dis[MAX][MAX][4];
bool valid(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= m){
		return false;
	}
	if(s[x][y] == '*'){
		return false;
	}
	return true;
}
struct node{
	int x;
	int y;
	int dir;
	node() { }
	node(int x, int y, int dir){
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
};
int main(){
	int sx, sy, ex, ey;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++ ){
        scanf("%s", s[i]);
        for(int j = 0; j < m; j++ ){
            for(int k = 0; k < 4; k++ ) 
            	dis[i][j][k] = -1;
            if ( s[i][j] == 'V' ) {
                sx = i;
                sy = j;
            }
            else if ( s[i][j] == 'H' ) {
                ex = i;
                ey = j;
            }
        }
    }
    queue < node > q;
    for(int i = 0; i < 4; ++i){
    	dis[sx][sy][i] = 0;
    	q.push(node(sx, sy, i));
    }
    while(!q.empty()){
    	node f = q.front();
    	q.pop();
    	for(int i = 0; i < 4; ++i){
    		int new_x = f.x + dx[i];
    		int new_y = f.y + dy[i];
    		if(valid(new_x, new_y)){
    			if(dis[new_x][new_y][i] == -1 || dis[new_x][new_y][i] > dis[f.x][f.y][f.dir] + (f.dir != i)){
    				dis[new_x][new_y][i] = dis[f.x][f.y][f.dir] + (f.dir != i);
    				q.push(node(new_x, new_y, i));
    			}
    		}
    	}
    }
    int ans = -1;
    for(int i = 0; i < 4; ++i){
    	if(dis[ex][ey][i] == -1){
    		continue;
    	}
    	if(ans == -1 || dis[ex][ey][i] < ans){
    		ans = dis[ex][ey][i];
    	}
    }
    printf("%d\n", ans);
    return 0;
}