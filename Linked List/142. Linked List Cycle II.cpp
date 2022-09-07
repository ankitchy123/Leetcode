ListNode *slow = head, *fast = head;
while (fast && fast->next)
{
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast)
    {
        while (slow != head)
        {
            slow = slow->next;
            head = head->next;
        }
        return slow;
    }
}
return NULL;