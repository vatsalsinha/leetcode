class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
    }
    //Every time we book a new event [start, end), what we actually do is add 1 to the event counts to all time points in the range [start, end)
    
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cur = 0, ans = 0;
        for(auto it : mp){
            cur += it.second;
            ans = max(cur, ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
