#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;



void toposort( int row, vector<vector<bool>> &adm, stack<int> &S, vector<bool> &V)
{
    V[row] = true;
    for (int i = 0; i < adm.size(); i++)
    {
        if (adm[row][i] && !V[i])
            toposort(i,adm,S,V);
    }
    S.push(row);
}

int main(int argc, char const *argv[])
{
    vector<vector<bool>> A;
    int n;
    bool x;
    cout<<"enter the number of nodes ";
    cin>>n;
    cout<<"fill adj matrix"<<endl;
    for (int i = 0; i < n; i++)
    {
        vector<bool> v1;
        for (int j = 0; j < n; j++)
        {
            cin>>x;
            v1.push_back(x);
        }
        A.push_back(v1);
    }
    stack<int> S;
    vector<bool> V(n,0);
    toposort(0,A,S,V);
    cout<<"topologically sorted order : ";
    while (!S.empty())
    {
        cout<<S.top() + 1<<" ";
        S.pop();
    }
    
    
    return 0;
}



