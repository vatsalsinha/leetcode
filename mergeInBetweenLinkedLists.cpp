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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //approach 1
        // ListNode* prev = NULL, *tojoin = NULL;
        // ListNode* tmp = list1;
        // int ia = 0, ib = 0;
        // while(tmp != NULL){
        //     if(ia == a-1)
        //         prev = tmp;
        //     tmp = tmp->next;
        //     ia++;
        // }
        // tmp = list1;
        // while(tmp != NULL){
        //     if(ib == b)
        //         tojoin = tmp->next;
        //     tmp = tmp->next;
        //     ib++;
        // }
        // prev->next = list2;
        // ListNode* t = list2;
        // while(t->next != NULL)
        //     t = t->next;
        // t->next = tojoin;
        // return list1;
        
        //approach 2
        ListNode* tmp = list1;
        ListNode* prev = NULL;
        for(int i = 0; i < b; i++){
            if(i == a-1)
                prev = tmp;
            tmp = tmp->next;
        }
        prev->next = list2;
        ListNode* t = list2;
        while(t->next)
            t = t->next;
        t->next = tmp->next;
        return list1;
    }
};
