#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Nodes
{
	vector<int> *adj;
	int V;
public:
	Nodes(int V);
	void addEdge(int index, int u);
	void possible();
};
Nodes::Nodes(int V)
{
	this->V = V;
	adj = new vector<int>[V];
}
Nodes::addEdge(int index, int u)
{
	adj[index].push_back();
}
Nodes::possible()
{
	vector<bool> check(V, false);
	vector<int>::iterator itr;
	for(itr = adj[0].begin(), itr != adj[0].end(); itr++)
}
int main()
{
	ll N, P;
	cin >> N >> P;
	return 0;
}
//Divisible_Digits.cpp