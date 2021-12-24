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
	for (int i = 0; i < end-1; i++)
	{
		current->next = new ListNode;
		cout << "NODE " << i << " VALUE: ";
		cin >> current->val;
		current = current->next;
	}
	cout << "NODE " << end << " VALUE: ";
	cin >> current -> val;
}
 
int main()
{
	ListNode *head = new ListNode(0);
	ListNode *current = head;
	queue<ListNode*> q;
	stack<ListNode*> s;

	buildList(head);
	int listLength = getLength(head);
	
	if(head = nullptr) 
	{
		return nullptr;
	}
	
	if(listLength = 1) 
	{
		print(head);
		return 0;
	}
	print(head);

	ListNode* temp;
	current = head;
	for(int i = 0; i < (listLength/2)+1; i++)
	{
		q.push(current);
		temp = current;
		current = current->next;
		temp->next = nullptr;
	}

	for(int i = ((listLength/2)+1); i < listLength; i++)
	{
		s.push(current);
		temp = current;
		current = current->next;
		temp->next = nullptr;
	}

	current = head;
	while(1)
	{
		current -> next = q.front();
		q.pop();
		current = current->next;
		if(q.empty()) { break; }
		if(s.empty()) 
		{ 
			current->next = q.front();
			break; 
		}
		current -> next = s.top();
		s.pop();
		current = current->next;
	}

	print(head);
}