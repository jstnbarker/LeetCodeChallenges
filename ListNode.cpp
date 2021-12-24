#include <iostream>

using namespace std;

class ListNode
{
public:
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head)
{
	ListNode* current = head;
	while(current != nullptr)
	{
		cout << current->val << " -> ";
		current = current->next;
	}
	cout << "nullptr" << endl;
}

ListNode* buildList()
{
    ListNode* out = new ListNode();
	ListNode* current = out;
	cout << "NODES: ";
	int end;
	cin >> end;
	for (int i = 0; i < end-1; i++)
	{
		current->next = new ListNode;
		cout << "NODE " << i << " VALUE: ";
		cin >> current->val;
		current = current->next;
	}
	cout << "NODE " << end-1 << " VALUE: ";
	cin >> current -> val;
	return out;
}