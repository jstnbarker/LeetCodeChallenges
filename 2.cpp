#include <iostream>
#include "ListNode.cpp"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* out = new ListNode();
	ListNode* out_ptr = out;
	ListNode* l1_ptr = l1;
	ListNode* l2_ptr = l2;
}

int main()
{
	cout << "BUILD LIST 1" << endl;
	ListNode* l1 = buildList();
	cout << "BUILD LIST 2" << endl;
	ListNode* l2 = buildList();
	
	printList(l1);
	printList(l2);
}
