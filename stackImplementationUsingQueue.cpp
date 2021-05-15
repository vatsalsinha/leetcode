class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    int currSize;
    MyStack() {
        currSize = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        currSize++;
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q1.front();
        q1.pop();
        currSize--;
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return currSize ? false : true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
