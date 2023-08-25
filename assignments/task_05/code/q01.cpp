
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



using namespace std;


int main() {
    int m;
    int n;
    cin>>m;
    cin>>n;
    int c;
    int k=0;
    vector<int> consta;
    consta.push_back(0);
    vector <vector<int>> v;
    vector <vector<int>> v1;
    for(int i=0;i<m;i++)
    {
        v.push_back(consta);
        for(int j=0;j<n;j++)
        {
            cin>>c;
            v[i].push_back(c);
        }
        v[i].erase(v[i].begin());
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=0)
            {
            if(v[i][j]==1)
            {
                v[0][j]=1;
                v[i][0]=1;
            }
            }
            else
            {
                if(v[i][j]==1)
                {
                    k=1;
                }
            }
        }
        
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=0)
            {
            if(v[i][0]==1 or v[0][j]==1)
            {
                cout<<1<<' ';
            }
            else
                cout<<0<<' ';
            }
            else
            {
                if(k==1)
                {
                    cout<<1<<' ';
                }
                else
                    cout<<v[i][j]<<' ';
            }
        }
        cout<<endl;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

