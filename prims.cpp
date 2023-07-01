#include <bits/stdc++.h>
using namespace std;
int minKey(int key[], bool mstSet[], int vert)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < vert; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int graph*, int vert)
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < vert; i++)
		printf("%d - %d \t%d \n", parent[i], i,
			graph[i][parent[i]]);
}

void primMST(int* graph,int vert)
{
	int parent[vert];
	int key[vert];
	bool mstSet[vert];
	for (int i = 0; i < vert; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < vert - 1; count++) {
		int u = minKey(key, mstSet,vert);
		mstSet[u] = true;
		for (int v = 0; v < vert; v++)
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph, vert);
}

int main()
{
    int v;
    cout<<"how many vertices ";
    cin>>v;
    int graph[v][v];
    cout<<"fill adj matrix"<<endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            graph[i][j];
        }
        
    }
	primMST(graph,v);
	return 0;
}


                  