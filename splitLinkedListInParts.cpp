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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp){
            tmp = tmp->next;
            n++;
        }
        int maxSize = n/k;
        int extraSize = n%k;
        tmp = head;
        vector<ListNode*> ans;
        while(tmp){
            ans.push_back(tmp);
            int count = 1;
            while(count < maxSize){ // normal operation for n/k
                tmp = tmp->next;
                count++;
            }
            if(extraSize > 0 && n > k){ // special case for n%k
                tmp = tmp->next;
                extraSize--;
            }
            ListNode* x = tmp->next;
            tmp->next = NULL;
            tmp = x;
        }
        int len = ans.size();
        while(len < k){
            ans.push_back(NULL);
            len++;
        }
        return ans;
    }
};
