#include <iostream>

struct Node
{
	int value;
	Node* next;
};

void insert(Node*& head, Node*& tail, int value)
{
	Node* temp = new Node;
	temp->value = value;

	if (head == NULL)
	{
		temp->next = NULL;
		head = temp;
		tail = temp;
		tail->next = head;
	}
	else
	{
		temp->next = head;
		tail->next = temp;
		tail = tail->next;
	}
}

int func(Node* head)
{
	while (head->next->next != head)
	{
		head->next = head->next->next;
		head = head->next;
	}
	return head->value;
}

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	int N;
	std::cin >> N;
	if (N == 1 || N == 2)
		std::cout << "1";
	else
	{
		int i;
		if (N % 2 == 0)
		{
			i = 1;
		}
		else
		{
			i = 3;
		}
		for (i; i <= N; i += 2)
		{
			insert(head, tail, i);
		}
		std::cout << func(head);
	}

	return 0;
}