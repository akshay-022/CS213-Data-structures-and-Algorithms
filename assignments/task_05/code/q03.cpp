#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


//Minor
//Akshay Iyer
//190070006
//h190070006 on hackerrank
//Email id on hackerrank- 190070006@iitb.ac.in

//I pledge on my honour and the Gita, that I have not used(except assignment 1) //and will not use any unfair means( give or receive unauthorised assistance //of any kind ) during this examination, or any other future examination or //assignment in this course. I shared my code with a friend in assignment 1, //which I THOROUGHLY regret, and which I sincerely beg your forgiveness for.




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> conn;//no 0, our main 2D vector
vector<int> tp;//just a temporary vector to push back a 0 vector
vector<int> xy; //stores only those elements which have candy shops at them
vector <bool> vis;
long long sum=0;
long long mini=0;
long long minind=0;

void DFS(int v, int h)
{
    // Mark the current node as visited and
    // print it
    vis[v-1] = true;
    
    if(xy[v-1]==1)
    {
        
        sum=sum+h;
        
    }
    // Recur for all the vertices adjacent
    // to this vertex
    for (int i = 0; i != (int)conn[v-1].size(); i++)
        if (!vis[conn[v-1][i]-1])
            DFS(conn[v-1][i], h+1);
}





// Driver program
int main()
{
    int n;
    cin>>n;
    int cn;
    cin>>cn;
    
    
    
    for(int i=0;i<n;i++)
    {
        vis.push_back(false);
    }
    
    
    
    
    
    
    tp.push_back(0);
    conn.push_back(tp);
    for(int i=2; i<=n;i++)
    {
        conn.push_back(tp);//just to create the vector of vectors
        
    }
    
    
    
    for(int i=0; i<n; i++)
    {
        xy.push_back(0);
    }
    for(int i=0; i<cn; i++) //candy shop vector
    {
        xy[i-1]=1;
    }
    
    
    
    
    //if(n==1)
    //{
    //    cout<<0;
    //    return 0;
    //}
    
    for(int i=1; i<n;i++)
    {
        int a;
        cin>>a;
        int b;
        cin>>b;
        conn[a-1].push_back(b);
        conn[b-1].push_back(a);
    }
    for(int i=1; i<=n;i++)
    {
        conn[i-1].erase(conn[i-1].begin());
    }
    sum=0;
    DFS(1,0);
    mini=sum;
    minind=1;
    for(int i=2; i<=n;i++)
    {
        sum=0;
        DFS(i,0);
        if(sum<mini)
        {
            mini=sum;
            minind=i;
        }
        for(int i=0;i<n;i++)
        {
        vis[i]=0;
        }
    
        sum=0;
      
    }
    cout<<minind;
    
    
    
   return 0;
} 
