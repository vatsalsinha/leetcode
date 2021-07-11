class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> large; // maxheap
    priority_queue<int, vector<int>, greater<int>> small; //smallheap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(large.empty() || large.top() > num){
            large.push(num);
        }
        else{
            small.push(num);
        }
        if(large.size() > small.size()+1){
            small.push(large.top());
            large.pop();
        }
        else if(small.size() > large.size()+1){
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(large.size() == small.size()){
            if(large.empty()){
                return 0;
            }
            else{
                double avg = (large.top() + small.top()) / 2.0;
                return avg;
            }
        }
        else{
            return large.size() > small.size() ? large.top() : small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
