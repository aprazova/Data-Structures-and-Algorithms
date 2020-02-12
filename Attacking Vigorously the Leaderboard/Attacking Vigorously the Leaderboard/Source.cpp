

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	Node* insertKey(Node* root, double val)
	{
		if (root == NULL)
		{
			return new Node(val, NULL, NULL);
		}
		else
		{
			Node* cur;
			if (val < root->value)
			{
				cur = insertKey(root->left, val);
				root->left = cur;
			}
			if (val > root->value)
			{
				cur = insertKey(root->right, val);
				root->right = cur;
			}
			if (val == root->value)
			{
				std::cout << val << " already added\n";
			}
		}
		return root;
	}


	void add(double value)
	{
		root = insertKey(root, value);
	}

	Node* maxValue(Node* root)
	{
		Node* temp = root;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp;
	}

	Node* deleteNode(Node* root, double key, bool& flag)
	{
		if (root == NULL)
		{
			return root;
		}
		else if (root->value < key)
		{
			root->right = deleteNode(root->right, key, flag);
		}
		else if (root->value > key)
		{
			root->left = deleteNode(root->left, key, flag);
		}
		else
		{
			flag = true;
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
			}
			else if (root->left == NULL)
			{
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL)
			{
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			else
			{
				Node* temp = maxValue(root->left);
				root->value = temp->value;
				root->left = deleteNode(root->left, temp->value, flag);
			}
		}
		return root;
	}

	void remove(double value)
	{
		bool flag = false;
		root = deleteNode(root, value, flag);
		if (flag == false)
		{
			std::cout << value << " not found to remove\n";
		}
	}

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}