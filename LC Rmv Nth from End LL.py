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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int cnt = 0,tar;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        if(n>cnt)
            return head;
        else if(n==cnt)
            return head->next;
        else
        {
            tar = cnt - n - 1;
            temp = head;
            while(tar--)
                temp = temp->next;
            temp->next = temp->next->next;
            return head;
        }
    }
};