#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
 Akshay Iyer-190070006
 Minor
 Hackerrank id- h190070006

 Honour code-
 I pledge on my honour and the Gita, that I have not used(except assignment 1) and will not use any unfair means( give or receive unauthorised assistance of any kind ) during this examination, or any other future examination or assignment in this course. I shared my code with a friend in assignment 1, which I THOROUGHLY regret, and which I sincerely beg your forgiveness for.


*/







struct Node
{
   int key;
   Node* left;
   Node* right;
   int f;
   int height;
};

//creating and instantiating a new node
Node *newNode(int k, int y)
{
   Node *temp = new Node;
   temp->key = k;
   temp->left= NULL;
   temp->right= NULL;
   temp->height=1;
   temp->f=y;
   return temp;
}
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}




Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
 
    // Return new root
    return x;
}
 

Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}






Node* add(Node* root, int x1,int x2, int c)
{
    if (root == NULL)
       return root;
    
    if (root->key < x1)
       root->right=add(root->right,x1,x2, c);
    else if (root->key > x2)
       root->left=add(root->left,x1,x2, c);
    else
    {
     (root->f)=(root->f)+c;
     root->left=add(root->left,x1,x2, c);
     root->right=add(root->right,x1,x2, c);
    }
    return(root);
}
Node* search(Node* root, int key)
{
    
    if ((root == NULL)|| root->key == key)
       return root;

    if (root->key < key)
       return search(root->right, key);
    
    return search(root->left, key);
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return (height(N->left) - height(N->right));
}

Node* insert(Node* root, int key, int y)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL)
    {
       return(newNode(key,y));
    }
    // Key is greater than root's key
    if (root->key < key)
       root->right = insert(root->right, key,y);
 
    if (root->key > key)
       root->left = insert(root->left, key,y);
    
    if (root->key == key)
    {
        root->f = y;
        return(root);
    }
    
    
    root->height = 1 + max(height(root->left), height(root->right));
 
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    /* return the (unchanged) node pointer */
    return root;
}





Node* minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

Node* deleteNode(Node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the smallest in the right subtree
        struct Node* temp = minValueNode(root->right);
 
        
        root->key = temp->key;
        root->f = temp->f;
 
        root->right = deleteNode(root->right, temp->key);
    }
     
  
     
    root->height = 1 + max(height(root->left),height(root->right));
  
    int balance = getBalance(root);
  
    // If this node becomes unbalanced, there are 4 cases
  
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
  
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
  
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
  
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
  
    return root;
}








int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    Node* rootm;
    while(true)
    {
        cin>>c;
        if(c=='i')
        {
            int x;
            cin>>x;
            int y;
            cin>>y;
            rootm=newNode(x,y);
            break;
        }
    }
    cin>>c;
    while(c!='e')
    {
        
       
        if(c=='g')
        {
            int x;
            cin>>x;
            Node* y= search(rootm,x);
            if(y!=NULL)
            cout<<y->f<<endl;
        }
        else if(c=='i')
        {
            int x;
            cin>>x;
            int y;
            cin>>y;
            rootm=insert(rootm,x,y);
           
        }
        else if(c=='d')
        {
            int x;
            cin>>x;
            rootm=deleteNode(rootm,x);
            
        }
        else if(c=='a')
        {
            int x1;
            cin>>x1;
            int x2;
            cin>>x2;
            int c1;
            cin>>c1;
            rootm=add(rootm,x1,x2,c1);
        }
        cin>>c;
    }
        return 0;
}


