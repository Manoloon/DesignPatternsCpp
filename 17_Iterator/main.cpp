/*
	Iterator Exercise 
*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void preorder_traversal(vector<Node<T>*>& result)
    {
      Node<T>* current = this;
      if(current->right)
      {
        current = current->right;
        while (current->left)
        {
          current = current->left;
        }
      }
      else
      {
        Node<T>* p = current->parent;
        while (p && current == p->right)
        {
          current = p;
          p = current->parent;
        }
        current = p;
        result.emplace_back(this);
      }
    }
};

int main()
{
  vector<Node<string>*> result;
  vector<Node<string>*> input{new Node<string>{"a"},new Node<string>{"b"},new Node<string>{"c"},new Node<string>{"d"}};
  for(auto n : input)
  {
    cout << (*n).value <<  '\n';
    (*n).preorder_traversal(result);
  }
  cout << "print results\n";
  if(result.empty())
  {
    cout << "result is empty\n";
  }
  else
  {
    for(const auto& n : result)
    {
        cout << n->value << '\n';
    }
  }
}