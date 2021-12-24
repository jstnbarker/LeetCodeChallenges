#include <iostream>
#include "ListNode.cpp"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* out = new ListNode();
	ListNode* out_ptr = out;
	ListNode* l1_ptr = l1;
	ListNode* l2_ptr = l2;
	int carry = 0;
	
	while(out_ptr != nullptr)
	{
		out_ptr->val += carry;
		
		int operandA = 0;
		int operandB = 0;
		
		if (l1_ptr == nullptr) operandA = 0;
		else 
		{
			operandA = l1_ptr->val;
			l1_ptr = l1_ptr->next;
		}
		
		if (l2_ptr == nullptr) operandB = 0;
		else
		{
			operandB = l2_ptr->val;
			l2_ptr = l2_ptr->next;
		}
		
		out_ptr->val += (operandA + operandB);
		if(out_ptr->val >= 10)
		{
			carry = 1;
			out_ptr->val%=10;
		}
		else carry = 0;

		if(l1_ptr != nullptr || l2_ptr != nullptr || carry != 0)
		{
			out_ptr->next = new ListNode();
		}
		out_ptr = out_ptr -> next;
	}
	return out;
}

int main()
{
	cout << "BUILD LIST 1" << endl;
	ListNode* l1 = buildList();
	cout << "BUILD LIST 2" << endl;
	ListNode* l2 = buildList();
	
	printList(l1);
	printList(l2);
	
	printList(addTwoNumbers(l1, l2));
}
