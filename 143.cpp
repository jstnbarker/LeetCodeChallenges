#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include "ListNode.cpp"

using namespace std;

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
 
int main()
{
	ListNode *head = buildList();

	ListNode *current = head;
	queue<ListNode*> q;
	stack<ListNode*> s;
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