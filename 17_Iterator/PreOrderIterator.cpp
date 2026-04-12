#include <string>
#include <iostream>

template<typename T>
struct BinaryTree;

template<typename T>
struct Node
{
    T val = T();
    Node<T>* left{nullptr};
    Node<T>* right{nullptr};
    Node<T>* parent{nullptr};
    BinaryTree<T>* tree{nullptr};

    Node(const T& value):val(value){}
    Node(const T& value,const Node<T>* left,const Node<T>* right):val(value),left(left),right(right)
    {
        this->left->tree = this->right->tree = tree;
        this->left->parent = this->right->parent = this;
    }

    void SetTree(BinaryTree<T>* t)
    {
        tree = t;
        if (left)
            left->SetTree(t);
        if(right)
            right->SetTree(t);
    }
    ~Node()
    {
        if(left)
            delete left;
        if (right)
            delete left;
    }
};

// a wrapper around Node
template<typename T>
struct BinaryTree
{
    Node<T>* root;

    BinaryTree(Node<T>* root):root(root),PreOrder(*this)
    {
        root->SetTree(this);
    }
    ~BinaryTree()
    {
        if(root) delete root;
    }

    template<typename U>
    struct PreOrderIterator
    {
        Node<U>* current;
        PreOrderIterator(const Node<U>& current):current(current){}
        bool operator!=(const PreOrderIterator& other)
        {
            return current != other.current;
        }
        // operator ++
        PreOrderIterator<U>& operator++()
        {
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
                Node<U>* p = current->parent;
                while (p && current == p->right)
                {
                    current = p;
                    p = current->parent;
                }
                current = p;
            }
            return *this;
        }
        // operator * 
        Node<U>& operator*()
        {
            return *current;
        }
    }; // PreOrderiterator

    typedef PreOrderIterator<T> Iterator;

    Iterator Begin()
    {
        Node<T>* n = root;
        if(n)
            while (n->left)
                n = n->left;
        return Iterator{n};
    }
    Iterator End()
    {
        return Iterator{nullptr};
    }

    // Traversal PreOrder
    class PreOrderTraversal
    {
        BinaryTree& tree;
        public:
            PreOrderTraversal(BinaryTree& tree): tree(tree){}
            Iterator begin(){return tree.Begin();}
            Iterator end(){return tree.End();}
    };
    PreOrderTraversal PreOrder;
};

int main()
{
    /*
            prince
            /  \
       queen    king
       /  \
    Lord  Dansel
    */
    BinaryTree<std::string> Company
    {
        new Node<std::string>{"Prince",
            new Node<std::string>{"Queen",
                        new Node<std::string>{"Lord"},
                        new Node<std::string>{"Dansel"}
            },
            new Node<std::string>{"King"}}
    };
    for(auto it = Company.Begin(); it != Company.End();++it)
    {
        std::cout << (*it).val << "\n";
    }

    // Using PreOrderTraversal
    std::cout << "Using PreOrder Traversal\n"; 
    for(const auto& it : Company.PreOrder)
    {
        std::cout << it.val << "\n";
    }
};
