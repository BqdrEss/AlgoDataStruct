#include <iostream>
using namespace std;
#include <bits/stdc++.h>

template<class T>
class Linkedlist{
protected:
  struct list { // linked list
  T data;
  list * next;
  };
   list * top; // top of stack
public:
    Linkedlist()
    {
        this->top = NULL;
    }
    void push(T x){  // if size set, check for overflow
    // Create new node temp and allocate memory
    list * temp=new list;    // Check if stack (heap) is full.
    temp->data=x;    // Initialize data into temp data field
    temp->next = this->top;   // Put top pointer reference into temp link
    this->top = temp;   // Make temp as top of Stack
    }
    void reverse()
    {
        struct list *prev = NULL;
        struct list *nnext = NULL;
        struct list *temp = this->top;
        while (temp != NULL)
        {
            nnext = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nnext;
        }
        this->top = prev;
    }
    void display(){
    struct list* temp;
    // Check for stack underflow
    if (top == NULL){cout << "\nUnderflow";exit(1);}
    else
    {
        temp = this->top;
        while (temp != NULL)
        {
            // Print node data
            cout << temp->data << "\t";
            // Assign temp link to temp
            temp = temp->next;
        }
        cout<<endl;
    }
  }
};
template<class T>
class Binary_Tree{
    // Linked list node
    struct ListNode
    {
      int data;
      ListNode* next;
    };
    ListNode * head;
    ListNode** hhead;
    struct BinaryTreeNode
        {
            T data;
            BinaryTreeNode *left, *right;
        };
    public:
    BinaryTreeNode * root;
        Binary_Tree()
    {
        this->root = NULL;
    }
    void push( T ndata)
{
    // allocate node and assign data
    struct ListNode* nnode = new ListNode;
    nnode->data = ndata;
  
    // link the old list off the new node
    nnode->next = (*this->hhead);
  
    // move the head to point to the new node
    (*this->hhead)    = nnode;
}
    // method to create a new binary tree node from the given data
    BinaryTreeNode* newBinaryTreeNode(T ndata)
    {
        BinaryTreeNode *temp = new BinaryTreeNode;
        temp->data = ndata;
        temp->left = temp->right = NULL;
        return temp;
    }
    // converts a given linked list representing a complete binary tree into the
// linked representation of binary tree.
void convertList2Binary()
{
    // queue to store the parent nodes
    queue<BinaryTreeNode *> q;
  
    // Base Case
    if (this->head == NULL)
    {
        this->root = NULL; // Note that root is passed by reference
        return;
    }
  
    // 1.) The first node is always the root node, and add it to the queue
    this->root = newBinaryTreeNode(head->data);
    q.push(root);
  
    // advance the pointer to the next node
    head = head->next;
  
    // until the end of linked list is reached, do the following steps
    while (head)
    {
        // 2.a) take the parent node from the q and remove it from q
        BinaryTreeNode* parent = q.front();
        q.pop();
  
        // 2.c) take next two nodes from the linked list. We will add
        // them as children of the current parent node in step 2.b. Push them
        // into the queue so that they will be parents to the future nodes
        BinaryTreeNode *leftChild = NULL, *rightChild = NULL;
        leftChild = newBinaryTreeNode(this->head->data);
        q.push(leftChild);
        this->head = this->head->next;
        if (this->head)
        {
            rightChild = newBinaryTreeNode(this->head->data);
            q.push(rightChild);
            this->head = this->head->next;
        }
  
        // 2.b) assign the left and right children of parent
        parent->left = leftChild;
        parent->right = rightChild;
    }
  }
    // Utility function to traverse the binary tree after conversion
    void inorderTraversal(BinaryTreeNode* root)
    {
       if (this->root)
     {
        inorderTraversal( this->root->left );
        cout << this->root->data << " ";
        inorderTraversal( this->root->right );
    }
}
};



// Driver Code
int main()
{    
    Linkedlist<int> L;
    L.push(10);
    L.push(20);
    L.push(30);
    cout<<"the list is: "<<endl;
    L.display();
    L.reverse();
    cout<<"reversed list: "<<endl;
    L.display();

    Binary_Tree<int> tree ;
          
        /* Last node of Linked List */
        tree.push(36); 
        tree.push(30);
        tree.push(25);
        tree.push(15);
        tree.push(12);
          
        /* First node of Linked List */
        tree.push(10); 
        tree.convertList2Binary();
        tree.inorderTraversal(tree.root);

    return 0;
}