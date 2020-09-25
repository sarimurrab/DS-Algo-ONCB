#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};
void insertAthead(node *&head, int d)
{
	if (head == NULL)
	{
		head = new node(d);
		return;
	}
	node *temp = new node(d);
	temp->next = head;
	head = temp;
	return;
}

void display(node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

node *midpoint(node *head)
{
	node *slow = head;
	node *fast = head->next;

	while (fast != NULL and fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node *merge(node *a, node *b)
{
	if (a == NULL)
	{
		return b;
	}
	if (b == NULL)
	{
		return a;
	}

	node *c;
	if (b->data < a->data)
	{
		c = b;
		c->next = merge(a, b->next);
	}
	else
	{
		c = a;
		c->next = merge(a->next, b);
	}

	return c;
}

node *merge_sort(node *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	node *mid = midpoint(head);
	node *a = head;
	node *b = mid->next;
	mid->next = NULL;

	a = merge_sort(a);
	b = merge_sort(b);

	node *c = merge(a, b);

	return c;
}
void detect_cylce(node *head)
{
	node *fast = head;
	node *slow = head;
	int var = 0;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
		{
			cout << "Yes Present" << endl;
			var = 1;
			slow = head;
			break;
		}
	}

	node *prevoffast;
	if (var == 1) // if cycle was detected
	{
		while (fast != slow)
		{
			prevoffast = fast;
			fast = fast->next;
			slow = slow->next;
		}
		cout << endl
			 << "Removing...link at value: ";

		cout << prevoffast->next->data;
		prevoffast->next = NULL;
		cout << endl
			 << "DONE" << endl;
	}
	else
	{
		cout << "Not Detected" << endl;
	}
}

int main()
{
	node *head = NULL;
	insertAthead(head, 3);
	insertAthead(head, 17);
	insertAthead(head, 1);
	insertAthead(head, 0);
	insertAthead(head, 90);
	insertAthead(head, 34);
	insertAthead(head, 12);
	display(head);
	cout << endl;

	// 12  34 90 0 1 17 3

	// node * merge_out = merge_sort(head);
	// display(merge_out);

	node *tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = head->next->next; // making cycle ourselves
	//display(head);
	detect_cylce(head);
	detect_cylce(head); // checking again

	display(head);

	return 0;
}
