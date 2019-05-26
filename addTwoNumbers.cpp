/**
*	Add two numbers given in lists
*
* 	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* 	Output: 7 -> 0 -> 8
* 	Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* ans = l1;
	ListNode* ansBuf = l2;
	int buf1, buf2;
	int rest = 0;
	if ((l2->next != NULL) && (l1->next != NULL))
	{
		while ((l2->next != NULL) && (l1->next != NULL))
		{
			buf1 = l1->val;
			buf2 = l2->val;
			l1->val = (buf1 + buf2 + rest) % 10;
			rest = (buf1 + buf2 + rest < 10) ? 0 : 1;
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	if ((l2->next == NULL) && (l1->next == NULL))
	{
		buf1 = l1->val;
		buf2 = l2->val;
		l1->val = (buf1 + buf2 + rest) % 10;
		rest = (buf1 + buf2 + rest < 10) ? 0 : 1;
		if (rest != 0)
		{
			l1->next = l2;
			l1 = l1->next;
			l1->val = rest;
		}
	}
	else if ((l1->next == NULL) && (l2->next != NULL))
	{
		buf1 = l1->val;
		buf2 = l2->val;
		l1->val = (buf1 + buf2 + rest) % 10;
		rest = (buf1 + buf2 + rest < 10) ? 0 : 1;
		l1->next = l2->next;
		l2->next = NULL;
		while (l1->next != NULL)
		{
			l1 = l1->next;
			buf1 = l1->val;
			l1->val = (buf1 + rest) % 10;
			rest  = (buf1 + rest < 10) ? 0 : 1;
		}
		if (rest != 0)
		{
			l1->next = l2;
			l1 = l1->next;
			l1->val = rest;
		}
	}
	else if ((l1->next != NULL) && (l2->next == NULL))
	{
		buf1 = l1->val;
		buf2 = l2->val;
		l1->val = (buf1 + buf2 + rest) % 10;
		rest = (buf1 + buf2 + rest < 10) ? 0 : 1;
		while (l1->next != NULL)
		{
			l1 = l1->next;
			buf1 = l1->val;
			l1->val = (buf1 + rest) % 10;
			rest = (buf1 + rest < 10) ? 0 : 1;
		}
		if (rest != 0)
		{
			l1->next = l2;
			l1 = l1->next;
			l1->val = rest;
		}
	}

	return ans;
}
