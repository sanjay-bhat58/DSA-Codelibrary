/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* t1, ListNode* t2) {
        if(!t1)
            return t2;
        if(!t2)
            return t1;
        ListNode *head = NULL;
        if (t1->val > t2->val)
        {
            head = t2;
            t2 = t2->next;
        }
        else
        {
            head = t1;
            t1 = t1->next;
        }
        ListNode *temp = head;
        while(t1 && t2)
        {
            if(t1->val < t2->val)
            {
                temp->next = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        if(!t1)
            temp->next = t2;
        else
            temp->next = t1;
        return head;
    }
};