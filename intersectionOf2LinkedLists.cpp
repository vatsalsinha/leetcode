/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode *t1 = headA;
        // ListNode *t2 = headB;
        // while(t1 != t2){
        //     t1 = t1 == NULL ? headB : t1->next;
        //     t2 = t2 == NULL ? headA: t2->next;
        // }
        // return t1;
        int lA= 0, lB = 0;
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        while(t1 != NULL){
            lA++;
            t1 = t1->next;
        }
        while(t2 != NULL){
            lB++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        for(int i = 0; i < abs(lA-lB); i++){
            if(lA < lB) t2 = t2->next;
            if(lA > lB) t1 = t1->next;
        }
        while(t1 != NULL){
            if(t1 == t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
};
