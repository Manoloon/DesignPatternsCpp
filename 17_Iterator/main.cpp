/*
	Iterator Exercise 
*/
#include <iostream>
#include <vector>
#include <assert.h>
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
      result.emplace_back(this);
      if(left)
      {
        left->preorder_traversal(result);
      }
      if(right)
      {
        right->preorder_traversal(result);
      }
    }
};

int main()
{
    Node<string> n4("a");
    Node<string> n5("b");
    Node<string> n2("c", &n4, &n5);
    Node<string> n3("d");
    Node<string> root("e", &n2, &n3);

    vector<Node<string>*> result;
    root.preorder_traversal(result);

    vector<string> expected{"a", "b", "c","d", "e"};
    for(auto r : result)
    {
      cout << r->value << "\n";
    }
    assert(result.size() == expected.size());

    for (size_t i = 0; i < expected.size(); ++i)
        assert(result[i]->value == expected[i]);
}