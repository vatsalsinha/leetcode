class MyCircularQueue {
public:
    vector<int> q;
    int capacity;
    int head;
    int tail;
    MyCircularQueue(int k) {
        q.resize(k,0);
        capacity = k;
        head = -1;
        tail = -1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(isEmpty())
            head = 0;
        tail = (tail+1)%capacity;
        q[tail]=value;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(head == tail)
            head = -1, tail = -1;
        else
            head = (head+1) % capacity;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return q[head];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return q[tail];
    }
    
    bool isEmpty() {
        return head == -1 && tail == -1;
    }
    
    bool isFull() {
        return head == (tail + 1) % capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
