#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define MAXLEN 100

using namespace std;

void printAdjMatrix(vector<vector<bool>>& A)
{
    cout<<"Adj Matrix"<<endl;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}
void printGraphStruct(vector<vector<bool>>& A)
{
    cout<<"Graph Structure : "<<endl;
    for (int i = 0; i < A.size(); i++) 
    {
        cout<<i+1<<"->";
        for (int j = 0; j < A[i].size(); j++)
        {
            if(A[i][j] == 1)
            {
                cout<<j+1<<" ";
            }
        }
        cout << endl;
    }
}
void printIO(vector<vector<bool>>& A)
{
    int x=0;
    cout<<"Indegree : "<<endl;
    for (int i = 0; i < A.size(); i++) 
    {
        cout<<i+1<<"->";
        for (int j = 0; j < A[i].size(); j++)
        {
            if(A[j][i] == 1)
                x++;
        }
        cout<< x << endl;
        x = 0;
    }
    cout<<"Outdegree : "<<endl;
    for (int i = 0; i < A.size(); i++) 
    {
        cout<<i+1<<"->";
        for (int j = 0; j < A[i].size(); j++)
        {
            if(A[i][j] == 1)
                x++;
        }
        cout<< x << endl;
        x = 0;
    }
}
void checkIO(vector<vector<bool>>& A)
{
    int x,m,n,i=0;
    cout<<"Enter node to be checked ";
    cin>>x;
    cout<<"Enter Indegree ";
    cin>>m;
    cout<<"Enter Outdegree ";
    cin>>n;
    for (int j = 0; j < A[x-1].size(); j++)
    {
        if(A[j][x-1] == 1)
            i++;
    }
    if(m != i)
    {
        cout<<"no";
        return;
    }
    i = 0;
    for (int j = 0; j < A[x-1].size(); j++)
    {
        if(A[x-1][j] == 1)
            i++;
    }
    if(i != n)
    {
        cout<<"no";
        return;
    }
    cout<<"yes";
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
    printAdjMatrix(A);
    printGraphStruct(A);
    printIO(A);
    checkIO(A);
    return 0;
}

