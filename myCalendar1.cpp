class MyCalendar {
public:
    vector<pair<int, int>> events;
    MyCalendar() {
       
    }
   
    bool book(int start, int end) {
        for(auto i : events){
            int startI = max(i.first, start);
            int startE = min(i.second, end);
            if(startI < startE)
                return false;
        }
         events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
