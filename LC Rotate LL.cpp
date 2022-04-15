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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        
        ListNode* last = head;
        if(last == NULL)
            return head;
        while(last->next != NULL)
        {
            len ++;
            last = last->next;
        }
        len ++;
        ListNode* temp = head;
        k = k % len;
        k = len - k;
        while ( --k > 0)
            temp = temp->next;
        last->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};