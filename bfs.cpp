#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(vector<vector<int>> adj_list,int v1)
{
    queue<int> Q;
    vector<int> B;
    vector<bool> V(adj_list.size()+1, 0);
    V[v1]=1;
    Q.push(v1);
    B.push_back(v1);
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for(int i = 0; i < adj_list[node].size(); i++)
            if(!V[adj_list[node][i]])
            {
                V[adj_list[node][i]]=1;
                Q.push(adj_list[node][i]);
                B.push_back(adj_list[node][i]);
            }
    }
    return B;
}

int main()
{
    int v,e;
    int i,start,end;
    cout<<"Enter number of vertices ";
    cin>>v;
    
    vector<vector<int>> adj_list(v+1);
    
    cout<<"Enter number of edges ";
    cin>>e;
    
    for(i = 0; i < e; i++)
    {
        cin>>start>>end;
        adj_list[start].push_back(end);
        adj_list[end].push_back(start);
    }
    
    vector<int> B = bfs(adj_list, 1);

    cout<<"Breadth First Traversal : ";
    for(int i = 0; i < B.size(); i++)
    {
        cout<<B[i];
        if(i < B.size()-1) 
        cout<<"->";
    }
    return 0;
}