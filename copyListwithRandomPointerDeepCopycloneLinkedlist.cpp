/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // unordered_map<Node*, Node*> mp;
        // Node *ogPointer = head;
        // Node *copyPointer = NULL;
        // Node *copyHead = NULL;
        // while(ogPointer){
        //     Node *tmp = new Node(ogPointer->val);
        //     mp[ogPointer] = tmp;
        //     if(copyHead == NULL){
        //         copyHead = tmp;
        //         copyPointer = copyHead;
        //     }
        //     else{
        //         copyPointer->next = tmp;
        //         copyPointer = copyPointer->next;
        //     }
        //     ogPointer = ogPointer->next;
        // }
        // ogPointer = head;
        // copyPointer = copyHead;
        // while(ogPointer){
        //     copyPointer->random = mp[ogPointer->random];
        //     ogPointer = ogPointer->next;
        //     copyPointer = copyPointer->next;
        // }
        // return copyHead;
        unordered_map<Node*, Node*> mp;
        Node *p = head;
        while(p){
            mp[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while(p){
            mp[p]->next = mp[p->next];
            mp[p]->random = mp[p->random];
            p = p->next;
        }
        return mp[head];
    }
};
