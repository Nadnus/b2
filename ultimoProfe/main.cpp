#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <chrono> 
#include <stdio.h>
#include <unistd.h>
 
#include "Tree.h"




int main() {
  typedef BSTNode<float> bst_node;
  typedef BNode<int> b_node;
  typedef Tree<b_node> b_tree;

  b_tree tree(4); 
  tree.insert(30);

  tree.insert(10);
  
  tree.insert(60);
  
  tree.insert(50);
  
  tree.insert(150);
  
  tree.insert(200);
  tree.insert(210);
  tree.insert(300);
  tree.insert(310);
  tree.insert(400);
  tree.insert(410);
  tree.insert(500);
    tree.insert(5000);
    tree.insert(5);
  tree.print(std::cout);
  
  //cout << tree << endl;
}


