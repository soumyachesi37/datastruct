#include<bits/stdc++.h>
#include <vector>
using namespace std;

void prim(vector<vector<int>> M,int v0)
{
    vector<bool> visited(M.size(),0);
    int edge_count = 0;
    int x,y;
    visited[v0] = 1;
    while (edge_count < M.size()-1)
    {
        int min = INT_MAX;
        x = 0; y = 0;
        for (int i = 0; i < M.size(); i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < M.size(); j++)
                {
                    if (!selected[j] && M[i][j])
                    {
                        if (min > M[i][j])
                        {
                            min = M[i][j];
                            x = i;
                            y = j;
                        }  
                    }
                }
            }
        }
    }
    visited[y] 
    

}

int main() 
{
    vector<vector<int>> matrix;
    int n,x;
    cout<<"enter the number of nodes ";
    cin>>n;
    cout<<"fill matrix"<<endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        for (int j = 0; j < n; j++)
        {
            cin>>x;
            v1.push_back(x);
        }
        matrix.push_back(v1);
    }
    int starting_vertex = 0;
    prim(matrix,starting_vertex);

}