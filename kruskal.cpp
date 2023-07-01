#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
struct Graph
{
	int V, E;
	vector< pair<int, iPair> > edges;
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}
	void addEdge(int u, int v, int w)
	{
		edges.push_back({w, {u, v}});
	}
	int kruskalMST();
};

struct DisjointSets
{
	int *parent, *rnk;
	int n;
	DisjointSets(int n)
	{

		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;
			parent[i] = i;
		}
	}
	int find(int u)
	{
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}
	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else 
			parent[x] = y;
		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};

int Graph::kruskalMST()
{
	int mst_wt = 0; 
    sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	vector< pair<int, iPair> >::iterator it;
	for (it=edges.begin(); it!=edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);
		if (set_u != set_v)
		{
			cout << u << " - " << v << endl;
			mst_wt += it->first;
			ds.merge(set_u, set_v);
		}
	}
	return mst_wt;
}

int main()
{
	

    int n,e,e1,e2,w;
	cout<<"how many nodes - ";
	cin>>n;
	cout<<"how many edges - ";
	cin>>e;
	Graph g(n,e);
    for (int i = 0; i < e; i++)
	{
		cin>>e1>>e2>>w;
		g.addEdge(e1,e2,w);
	}
	cout << "Edges of MST are \n";
	int mst_wt = g.kruskalMST();

	cout << "\nWeight of MST is " << mst_wt;

	return 0;
}


    0 1 4
    0 7 8
    1 2 8
    1 7 11
    2 3 7
    2 8 2
    2 5 4
    3 4 9
    3 5 14
    4 5 10
    5 6 2
    6 7 1
    6 8 6
    7 8 7
  