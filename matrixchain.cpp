#include<bits/stdc++.h>
using namespace std;

int matrixChainMul(vector<int> const &V, int start, int end)
{
    if (end <= start + 1) {
        return 0;
    }
    int min = INT_MAX;
    for (int i = start + 1; i <= end - 1; i++)
    {
        int cost = matrixChainMul(V, start, i);
        cost += matrixChainMul(V, i, end);
        cost +=    V[start] * V[i] * V[end];
        if (cost < min) 
        {
            min = cost;
        }
    }
}

int main(){
    int n;
    cout<<"enter number of matrices ";
    cin>>n;
    vector<int> mat(n);
    cout<<"enter dimensions "<<endl;
    for (int start = 0; start < n; start++)
    {
        int m;
        cin>>m;
        mat.push_back(m);
    }
    cout<<"minimum number of multiplications - ";
    cout<<matrixChainMul(mat, 1, n-1);
    return 0;
}
