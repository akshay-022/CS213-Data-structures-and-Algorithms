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


// Structure of a node
struct Node
{
   int key;
   vector<Node *> child;
   
};
  
// Utility function to create a new tree node
Node *newNode(int k)
{
   Node *temp = new Node;
   temp->key = k;
   return temp;
}
  
// Function that will return the depth of the tree
int mindeptht(Node *ptr)
{
    if (ptr==NULL)
        return 0;
    // Check for all children and find
    // the minimum depth
    int mindepth = 1000001;
    int x=0;
    for (vector<Node*>::iterator it = ptr->child.begin(); it != ptr->child.end(); it++)
    {
    x=1;
    mindepth = min(mindepth, mindeptht(*it));
    }
    if(x==0)
        return 1;
    return mindepth + 1 ;
}









// Driver program
int main()
{
    
    
    

    vector<vector<int>> conn;//no 0
    vector<int> ival;
    
    int n;
    cin>>n;
    vector<Node *> vect;//stores all addresses
    vect.push_back(newNode(1));
    ival.push_back(1);
    vector<int> tp;
    tp.push_back(0);
    conn.push_back(tp);
    for(int i=2; i<=n;i++)
    {
        vect.push_back(newNode(i));
        ival.push_back(i);
        conn.push_back(tp);//just to create the vector of vectors
        
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
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
        conn[i-1].erase(conn[i-1].begin());//to remove that 0 we added at the start of every subvector
        /*for(int j=0; j<(int)conn[i-1].size();j++)
        {
            cout<<conn[i-1][j]<<' ';
        }cout<<conn[i-1].size()<<endl;*/
    }
    while(conn.size()!=1)
    {
    for(int i=1; i<=(int)conn.size();i++)
    {
        if(conn[i-1].size()==1  && i!=1)
        {
         for(int xy=0; xy<(int)ival.size();xy++)
        {
             if(ival[xy]==conn[i-1][0])
            (vect[xy]->child).push_back(vect[i-1]);
        }
            for(int j=0; j<(int)conn.size();j++)
            {
               for(int i1=0; i1<(int)conn[j].size();i1++)
            {
                if(conn[j][i1]==ival[i-1])
                {
                   conn[j].erase(conn[j].begin()+i1); //erasing all appearances of that everywhere else
                }
            }
            }
            conn.erase(conn.begin()+i-1);//erasing that vector entry where only one element is present
            vect.erase(vect.begin()+i-1);
            ival.erase(ival.begin()+i-1);//so that the corresponding key vector also changes the same way
            i--;
            //cout<<endl<<endl;
        /*for(int z1=0; z1<(int)conn.size();z1++)
        {
            for(int z=0; z<(int)conn[z1].size();z++)
            {
            cout<<conn[z1][z]<<' ';
            }cout<<conn[z1].size()<<endl;
        }
        }
        cout<<endl<<endl;*/
        }
    }
    }
    
    
    
    
    vect.push_back(newNode(0));
    Node *root = newNode(0);
    (root->child).push_back(vect[0]);
    
   cout << mindeptht(root)-2 << endl;
   return 0;
}


