class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1, st2;
        for(auto c : s){
            if(c == '#' && st1.empty())
                continue;
            else if(c == '#' && !st1.empty())
                st1.pop();
            else
                st1.push(c);
        }
        for(auto c : t){
            if(c == '#' && st2.empty())
                continue;
            else if(c == '#' && !st2.empty())
                st2.pop();
            else
                st2.push(c);
        }
        while(!st1.empty() && !st2.empty() && st1.top() == st2.top()){
            //cout<<st1.top()<<":"<<st2.top();
            st1.pop();
            st2.pop();
        }
        return st1.empty() && st2.empty();
    }
};
