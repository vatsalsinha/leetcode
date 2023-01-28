class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(st.size() == 0)
            return {};
        vector<vector<int>> v;
        int left = -1, right = -1; // left = lower bound, right = upper bound 
        for(int val : st){
            if(left < 0) // we have no lower bound, so set lower bound as well as upper bound to val;
                left = val, right = val;
            else if(val == right+1) // as soon as val becomes upper bound + 1, increase upper bound by 1;
                right = val;
            else{
                v.push_back({left, right}); // we have found the lower and upper bounds. 
                left = val, right = val; // set both lower and upper bound to val
            }
        }
        v.push_back({left, right});
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
 /* 
 1 2 3 6 7 
 */
