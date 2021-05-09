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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *odd = new ListNode(0, head);
        ListNode *even= new ListNode(0, head);
        ListNode *Ohead = odd;
        ListNode *Ehead = even;
        int i = 1;
        while(head){
            if(i%2 != 0){
                odd->next = head;
                odd = odd->next;
            }
            else{
                even->next = head;
                even = even->next;
            }
            head = head->next;
            if(head == NULL){
                even->next = NULL;
            }
            i++;
        }
        odd->next = Ehead->next;
        return Ohead->next;
    }
};
