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
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *tmp = head;
        //ListNode *prev;
        int count = 1;
        while(tmp->next){
            count++;
            tmp = tmp->next;
        }
        tmp->next = head;
        k = k%count;
        k = count - k;
        while(k--){
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};
