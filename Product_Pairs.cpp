#include <bits/stdc++.h>
using namespace std;
 
vector<long long > bits;
vector<vector<long long > > Edges;
long long N, K;
 
long long read(long long index)
{
	index++;
	long long ans = 0;
	if(index >= bits.size())
		index = bits.size() - 1;
	while(index > 0)
	{
		ans += bits[index];
		index -= index&(-index);
	}
	return ans;
}
 
void update(long long index, long long val)
{
	index++;
	while(index <= bits.size()-1)
	{
		bits[index] += val;
		index += index&(-index);
	}
	return ;
}
 
long long dfs(long long parent)
{
	
	long long ans = read(K/parent);
	update(parent, 1);
	for(int i = 0; i < Edges[parent].size(); i++) {
		int vertex = Edges[parent][i];
		ans += dfs(vertex);
	}
	update(parent, -1);
	return ans;
}
 
int main() 
{
 long long i, root;
 
 cin >> N >> K;
 bits.resize(N+3, 0);
 Edges.resize(N+1);
 
 long long s, d;
 vector<bool> present(N+1, false);
 present[0] = true;
 
 for(i = 0; i < N -1 ; i++)
 {
 	cin >> s >> d;
 	Edges[s].push_back(d);
 	present[d] = true;
 }
 
 root = find(present.begin(), present.end(), false) - present.begin();
 cout << dfs(root) << endl;
 return 0;
}