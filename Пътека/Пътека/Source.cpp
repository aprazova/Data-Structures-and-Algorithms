#include <iostream>
#include <string>
#include <vector>
#include <climits>

struct Node
{
	long long value;
	Node* next;
};

class stack
{
	Node* head;

public:
	stack()
	{
		head = NULL;
	}

	void push(long long value)
	{
		Node* temp = new Node;
		temp->value = value;
		if (head == NULL)
		{
			temp->next = NULL;
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}

	void pop()
	{
		head = head->next;
	}

	long long top()
	{
		return head->value;
	}
	bool empty()
	{
		return head == NULL;
	}
};
int main()
{
	stack myStack;
	int n;
	std::string operation;
	std::cin >> n;
	long long number;
	long long sum = 0;
	long long max = INT_MIN;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> operation;
		if (operation == "white")
		{
			std::cin >> number;
			myStack.push(number);
		}
		else if (operation == "blue")
		{
			std::cin >> number;
			while (number > 0)
			{
				if (max < myStack.top())
					max = myStack.top();

				myStack.pop();
				number--;
			}
			myStack.push(max);
			max = INT_MIN;
		}
		else if (operation == "green")
		{
			std::cin >> number;
			while (number > 0)
			{
				sum += myStack.top();
				myStack.pop();
				number--;
			}
			myStack.push(sum);
			sum = 0;
		}
	}
	std::vector<long long> result;
	while (!myStack.empty())
	{
		result.push_back(myStack.top());
		myStack.pop();
	}
	for (int i = result.size() - 1; i >= 0; i--)
	{
		std::cout << result[i] << " ";
	}
	return 0;
}