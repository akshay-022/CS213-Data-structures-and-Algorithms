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



#include <bits/stdc++.h> 
using namespace std; 

// Link list node
class Node { 
public: 
    int value; 
    Node* next; 
};
/* You Should NOT Modify Anything Above This */

/* 
headPtr is a reference to the head node(i.e. pointer to pointer) and
deleteNodePtr is the node which is to be deleted. You can see the Node definition above.
It is guaranteed that deleteNodePtr will not point to the last element.
*/ 
void deleteNode(Node** headPtr, Node* deleteNodePtr) {

    // Write your code here
    if(*headPtr==NULL)
        return;
    deleteNodePtr->value = deleteNodePtr->next->value;
    deleteNodePtr->next->value= NULL;
    Node *a = deleteNodePtr->next;
    deleteNodePtr->next = deleteNodePtr->next->next;
    a->next= NULL;
    free(a);
}

/* You Should NOT Modify Anything Below This */
int main() {
    Node* head = NULL;

    int n;
    cin>>n;

    vector <int> values(n);
    vector <Node*> pointers(n);

    for(int i=0;i<n;i++){
        cin>>values[i];
    }

    for(int i=n-1;i>=0;i--){
        
        // creating the node in the linkedList
        Node* newNode = new Node();
        newNode->value = values[i];
        newNode->next = head;
        head = newNode;

        pointers[i] = newNode;
    }

    for(int i=n-2;i>=0;i--){
        deleteNode(&head, pointers[i]);
        if(i>=n-6){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
}


