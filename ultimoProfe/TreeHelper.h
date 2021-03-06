#ifndef TREE_HELPER_H
#define TREE_HELPER_H

#include <iostream>
#include "BNode.h"
#include "BPlusNode.h"
#include "BSTNode.h"
using namespace std;

template <typename Node, typename ValueNode, int Flag>
struct TreeHelper
{
  typedef Node node_t;
  typedef typename node_t::value_t value_t;

  static void insert(node_t **head, const value_t &val, unsigned int order)
  {
    cout << "el tipo de dato no es compatible" << endl;
  }

  static void print(node_t **head, std::ostream &out)
  {
  }
};

template <typename ValueNode>
struct TreeHelper<BSTNode<ValueNode>, ValueNode, BST_NODE_FLAGXX>
{
  typedef BSTNode<ValueNode> node_t;
  typedef typename node_t::value_t value_t;

  static void insert(node_t **head, const value_t &val, unsigned int order)
  {
    auto temp = new node_t(val);

    if ((*head) == nullptr)
    {
      (*head) = temp;
      return;
    }

    if ((*head)->data > val)
    {
      insert(&(*head)->children[0], val, order);
      return;
    }

    if ((*head)->data < val)
    {
      insert(&(*head)->children[1], val, order);
      return;
    }
    cout << "Duplicates not allowed" << endl;
  }

  //BST Print
  static void print(node_t **head, std::ostream &out)
  {
    std::stack<node_t *> nodes;
    node_t *curr = *head;

    while (curr)
    {
      out << "Node: " << curr->data << endl;
      if (curr->children[1])
      {
        nodes.push(curr->children[1]);
      }
      if (curr->children[0])
      {
        curr = curr->children[0];
      }
      else
      {
        if (!nodes.empty())
        {
          curr = nodes.top();
          nodes.pop();
        }
        else
        {
          curr = nullptr;
        }
      }
    }
  }
};

template <typename ValueNode>
struct TreeHelper<BNode<ValueNode>, ValueNode, B_NODE_FLAGXX>
{
  typedef BNode<ValueNode> node_t;
  typedef typename node_t::value_t value_t;

  static void insert(node_t **head, const value_t &val, unsigned int order)
  {
    cout << "Insertando "<< val << endl;
    //(*head)->insert(val,order);
    if ((*head) == nullptr)
    {
      cout<< "no head";
      (*head) = new node_t(order);
      (*head)->data[0] = val;
      (*head)->current_keys++;
      return;
    }
    //print root
    cout << "root:";
    for (auto x : (*head)->data)
    {
      cout << x<<' ';
    }
    cout << endl;
    cout << "kids:";
    for (auto x : (*head)->children)
    {
      cout << (x == nullptr)<<' ';
    }
    cout << endl;
    cout<< "counted keys " <<(*head)->current_keys<< endl;
    //end print root

    if ((*head)->isContainerFull() )
    {
      node_t *overflow = new node_t(order);
      overflow->children[0] = (*head);

      overflow->splitChild((*head), 0);

      if (overflow->data[0] < val)
      {
        (overflow->children[1])->insertToContainer(val);
      }
      else
      {
        (overflow->children[0])->insertToContainer(val);
        
      }
      (*head) = overflow;
    }
    else
    {
      (*head)->insertToContainer(val);
    }
    cout<<"finished insert "<<val<< "\n";
  }

  static void print(node_t **head, std::ostream &out)
  {
    (*head)->printNode();
  }
};

#endif