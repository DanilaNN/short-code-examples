
/**
*     Given a linked list, remove the n-th node from the end of list and return its head.
*
*     Example:
*
*     Given linked list: 1->2->3->4->5, and n = 2.
*
*     After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* p_prev;
	ListNode* current;

	if ((n == 1) && (head->next == NULL))
		return NULL;

	if ((n == 1) && (head->next->next == NULL))
	{
		head->next = NULL;
		return head;
	}

	if ((n == 2) && (head->next->next == NULL))
		return head->next;

	int count = 0;
	p_prev = head;
	current = head;
	while (count != n + 1)
	{
		current = current->next;
		count += 1;
		if ((current == NULL) && (count == n))
			return head->next;
	}


	while (current != NULL)
	{
		p_prev = p_prev->next;
		current = current->next;
	}
	p_prev->next = p_prev->next->next;
	return head;
}
