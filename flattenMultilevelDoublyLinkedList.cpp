/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // Node *ans = new Node;
        // if(head == NULL)
        //     return head;
        // ans->val = head->val;
        // if(head->child){
        //     ans->next = flatten(head->child);
        //     ans->next->prev = ans;
        // }
        // Node *tmp = ans;
        // while(tmp->next){
        //     tmp = tmp->next;
        // }
        // if(head->next){
        //     tmp->next = flatten(head->next);
        //     tmp->next->prev = tmp;
        // }
        // return ans;
        Node *p = head, *l = NULL;
        while(p){
            if(p->child){
                l = p->child;
                l->prev = p;
                while(l->next){
                    l = l->next;
                }
                l->next = p->next;
                if(l->next){
                    l->next->prev = l;
                }
                p->next = p->child;
                p->child = NULL;
            }
            p = p->next;
        }
        return head;
    }
};
