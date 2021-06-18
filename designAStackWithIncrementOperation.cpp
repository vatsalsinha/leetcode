class CustomStack {
public:
    vector<int> stack;
    int maxI;
    CustomStack(int maxSize) {
        maxI = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < maxI)
            stack.push_back(x);
    }
    
    int pop() {
        if(stack.size() == 0)
            return -1;
        int s = stack.back();
        stack.pop_back();
        return s;
        
    }
    
    void increment(int k, int val) {
        k = min(k, (int)stack.size());
        for(int i = 0; i < k; i++)
            stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
