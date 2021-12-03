#include "RBtree.h"
#include <iostream>
using namespace std;

   int main(){

    RBTree tree;
    tree.insert(13);
    tree.insert(44);
    tree.insert(37);
    tree.insert(7);
    tree.insert(22);
    tree.insert(16);
    cout<<endl;
    cout<<"Tree after succesfull Insertion (Preorder Traversal)"<<endl;
    tree.printInOrder();
    cout<<endl;
    tree.printLevelOrder();
    cout<<endl;
    cout<<"Now Deleting the node 16"<<endl;
    tree.deleteByVal(16);
    tree.printInOrder();
    cout<<endl;
    tree.printLevelOrder();
    cout<<endl;
}