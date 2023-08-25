#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
 
 Akshay Iyer-190070006
 Minor
 Hackerrank id- h190070006

 Honour code-
 I pledge on my honour and the Gita, that I have not used(except assignment 1) and will not use any unfair means( give or receive unauthorised assistance of any kind ) during this examination, or any other future examination or assignment in this course. I shared my code with a friend in assignment 1, which I THOROUGHLY regret, and which I sincerely beg your forgiveness for.


 */

vector<vector<long long>> vect;

int num(int n, int h)
{
    long long k=0;//assume first that tree 1 has height h, and other has less than that
    
    if(h<0 or n<0)
        return 0;
    if(vect[n][h]>0)
        return(vect[n][h]);
    if(h==1 && n>1)
        return 0;
    if(n==0 and h!=0)
        return 0;
    if(h==0 and n!=0)
        return 0;
    if(n==0 and h!=0)
        return 0;
    if(h>n)
        return 0;
    if(h<log2(n+1))
        return(0);
    long long y1=0;
    for(int i=h-1;i<=n-1;i++)//nodes in tree left
    {
        long long xy=num(i,(h-1))%1000000007;
        for(int j=0;j<h-1;j++)//height of tree right
        {
            k=(k+(xy*(num(n-1-i,j)%1000000007))%1000000007)%1000000007;
            
        }
        if(i<=n-h)
            y1=(y1+(xy*(num(n-1-i,h-1)%1000000007))%1000000007)%1000000007;
        
    }
    vect[n][h]=(((2*k)%1000000007)+(y1%1000000007))%1000000007;
    return(vect[n][h]);
    //%1000000007
    
    
}


// Driver Program to test above functions
int main()
{
    // Construct all possible BSTs
    vector<long long> v;
    for(int i=0;i<=50;i++)
    {
        v.push_back((long long)0);
    }
    for(int j=0;j<=50;j++)
    {
        vect.push_back(v);
    }
    long long pr=1;
    for(int j=2;j<=50;j++)
    {
        pr=(2*pr)%1000000007;
        vect[j][j]=pr;
    }
    
      
    int no;
    cin>>no;
    int l;
    cin>>l;
    int r;
    cin>>r;
    int k1=0;
    
    vect[0][0]=1;
    vect[1][1]=1;
    
    for(int i=l;i<=r;i++)
    {
        int y=num(no,i)%1000000007;
        vect[no][i]=y;
        k1=(k1+y)%1000000007;
    }
    cout<<k1%1000000007;
    
    /*for(int i=0;i<=50;i++)
    {
      for(int j=0;j<=50;j++)
    {
        cout<<vect[i][j]<<' ';
    }  cout<<endl;
    }*/
    return 0;
} 
