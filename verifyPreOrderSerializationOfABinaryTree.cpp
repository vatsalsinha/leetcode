class Solution {
public:
    bool isValidSerialization(string preorder) {
        /* 
        // using a stack, scan left to right
        // case 1: we see a number, just push it to the stack
        // case 2: we see #, check if the top of stack is also #
        // if so, pop #, pop the number in a while loop, until top of stack is not #
        // if not, push it to stack
        // in the end, check if stack size is 1, and stack top is #
        */
        stack<string> st;
        preorder += ",";
        vector<string> pre;
        string tmp;
        for(auto c : preorder){
            if(c == ','){
                pre.push_back(tmp);
                tmp = "";
            }
            else
                tmp += c;
        }
        for(auto c : pre){
            while(!st.empty() && st.top() == "#" && c == "#"){
                st.pop();
                if(st.empty())
                    return false;
                st.pop();
            }
            st.push(c);
        }
        return st.size()==1 && st.top() == "#";
    }
};
