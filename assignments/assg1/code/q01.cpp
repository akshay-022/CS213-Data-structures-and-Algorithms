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


using namespace std;

    int PARTITION(vector<int> &A, int p, int r)
    {
        
    int x = A[r];
    int i = p-1;
    int ex;
    for (int j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            ex= A[i];
            A[i]=A[j];
            A[j]=ex;
        }
            
    }
    ex= A[i+1];
    A[i+1]=A[r];
    A[r]=ex;
    return i+1;
}
    
    
    void QUICKSORT(vector<int> &A,int p,int r)
    {
    while(p<r) {
      int q = PARTITION(A, p,r);
          if(p+r/2.0>q)
          {
            QUICKSORT (A, p,q-1);
            p = q + 1;
          }
          else
          {
            
             QUICKSORT (A, q+1,r);
             r = q-1;
          }
    }
    }

int main() 

{
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> a(200005);;
    int input;
    int n=0;
    while(cin>>input)
    {
        a[n]=input;
        n++;
    }
    QUICKSORT(a,0,n-1);
    for(int i=0; i<n; i++) 
    {
        cout << a[i] << ' ';
    }
    return 0;
    
    };

