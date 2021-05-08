class MyLinkedList {
    ListNode *head;
    ListNode *tail;
    int length;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(length == 0 || index >= length)
            return -1;
        ListNode *tmp = head;
        int i = 0;
        while(tmp != NULL && i++ < index){
            tmp = tmp->next;
        }
        return tmp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val);
        if(length == 0){
            head = newNode;
            newNode->next = NULL;
            tail = head;
        }
        else{
            ListNode *tmp = head;
            head = newNode;
            newNode->next = tmp;
        }
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        if(length == 0){
            head= newNode;
            newNode->next = NULL;
            tail = head;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > length)
            return;
        if(index == 0 || length == 0){
            addAtHead(val);
            return;
        }
        else if(index == length){
            addAtTail(val);
            return;
        }
        else{
            ListNode *tmp = head, *prev = NULL;
            ListNode *newNode = new ListNode(val);
            int i = 0;
            while(i++ < index){
                prev = tmp;
                tmp = tmp->next;
            }
            newNode->next = prev->next;
            prev->next = newNode;
        }
        length++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= length || length == 0)
            return;
        else if(length == 0 || index == 0){
            ListNode *t = head;
            head = head->next;
            delete(t);
        }
        else{
            ListNode *tmp = head, *prev = NULL;
            int i = 0;
            while(i++ < index){
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = tmp->next;
            delete(tmp);
        }
        length--;
        updateTail();
    }
    
    void updateTail(){
        if(length == 0){
            tail = NULL;
            return;
        }
        ListNode *tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tail = tmp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
