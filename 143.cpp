#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getLength(ListNode* head)
{
	ListNode* current = head; 
	int length = 0;
	while(current != nullptr)
	{
		length++;
		current = current->next;
	}
	return length;
}

void print(ListNode* head)
{
	ListNode* current = head;
	while(current != nullptr)
	{
		cout << current->val << " -> ";
		current = current->next;
	}
	cout << "nullptr" << endl;
}

void buildList(ListNode* head)
{
	ListNode* current = head;
	cout << "NODES: ";
	int end;
	cin >> end;
	for (int i = 0; i < end; i++)
	{
		current->next = new ListNode;
		cout << "NODE " << i << " VALUE: ";
		cin >> current->val;
		current = current->next;
	}
}
 
int main()
{
	ListNode *head = new ListNode(0);
	ListNode *current = head;
	queue<ListNode> q;
	stack<ListNode> s;
	int listLength = getLength(head);

	buildList(head);
	print(head);

	current = head->next;
	for(int i = 1; i <= listLength/2; i++)
	{
		q.push(*current);
		current = current->next;
	}

	for(int i = listLength/2; i < listLength; i++)
	{
		s.push(*current);
		current = current->next;
	}

	ListNode* newHead = head;
	current = newHead;
	while(!(s.empty()) && !(q.empty()))
	{
		current->next = &(q.front());
		q.pop();
		current = current->next;
		current->next = &(s.top());
		s.pop();
		current = current->next;
	}

	print(newHead);
}