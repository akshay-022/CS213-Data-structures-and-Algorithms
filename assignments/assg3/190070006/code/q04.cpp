#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>




//Minor
//Akshay Iyer
//190070006
//h190070006 on hackerrank
//Email id on hackerrank- 190070006@iitb.ac.in

//I pledge on my honor that I have not given or received any unauthorized //assistance on this assignment or any previous task.



#include <bits/stdc++.h> 
using namespace std; 

int num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
  
    int n;
    cin>>n;
    int n1;
    cin>>n1;
    vector <int> vect(n);

    

    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    num=n;
    

    
    
    for(int j=0;j<n1;j++)
    {
    char c;
    cin>>c;
    if(c=='I')
    {
      int k;
      cin>>k;
      int k2;
      cin>>k2;
        k--;
      vect.insert(vect.begin() + k, k2); 
      num++;
    }
    if(c=='D')
    {
      int k;
      cin>>k;
      k--;
      vect.erase(vect.begin()+k);
        num--;
    }
    if(c=='R')
    {
      int k;
      cin>>k;
      if(k==1)
      {
      vect.insert(vect.begin(),vect[num-1]);
      vect.pop_back();
    }
        else if(k==-1){
            vect.push_back(vect[0]);
      vect.erase(vect.begin());
        }
    }
    if(c=='P')
    {
      int k;
      cin>>k;
        k--;
      cout<<vect[k];
      cout<<endl;
        
    }
    
    }
}


