#include <iostream>

using namespace std;

template<typename Type>
struct node{
    typedef node<Type> node_type;
	Type data;
	node_type *left;
	node_type *right;
};

template<typename Type>
class BinaryTree{
public:
	BinaryTree()
	{
	    root = NULL;
	}
	~BinaryTree()
	{
	    delete_tree();
	}
	void insert(float value)
	{
	    if(root != NULL)
	    {
		    insert(value, root);
	    }
	    else
	    {
		    root = new node<Type>;
		    root -> data = value;
		    root -> left = NULL;
		    root -> right = NULL;
	    }
	}
	void delete_tree()
	{
	    delete_tree(root);
	}
	void print()
	{
	    print(root);
	}
private:
	void delete_tree(node<Type> *leaf)
	{
	    if(leaf != NULL)
	    {
		    delete_tree(leaf -> left);
		    delete_tree(leaf -> right);
		    delete leaf;
	    }
    }
	void insert(float value, node<Type> *leaf)
	{
	    if(value < leaf -> data)
	    {
		    if(leaf -> left != NULL)
		    {
			    insert(value, leaf -> left);
		    }
		    else
		    {
			    leaf -> left = new node<Type>;
			    leaf -> left -> data = value;
			    leaf -> left -> left = NULL;
			    leaf -> left -> right = NULL;
		    }
	    }
	    else if(value >= leaf -> data)
	    {
		    if(leaf -> right != NULL)
		    {
			    insert(value, leaf -> right);
		    }
		    else
		    {
			    leaf -> right = new node<Type>;
			    leaf -> right -> data = value;
			    leaf -> right -> right = NULL;
			    leaf -> right -> left = NULL;
		    }
	    }
    }
    void print(node<Type> *leaf)
	{
	    if(leaf != NULL)
	    {
		    print(leaf -> left);
		    cout << leaf -> data << endl;
		    print(leaf -> right);
	    }
	}
	node<Type> *root;
};

int main(){
	BinaryTree<float> *tree = new BinaryTree<float>();
	tree -> insert(234.33);
	tree -> insert(23.1);
	tree -> insert(65.9);
	tree -> insert(77.6);
	tree -> insert(1.0);
	tree -> print();
	delete tree;
}
