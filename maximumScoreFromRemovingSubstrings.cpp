class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string p1 = x > y ? "ab" : "ba";
        string p2 = p1 == "ab" ? "ba" : "ab";
        int firstScore = max(x, y);
        int secondScore = min(x, y);
        
        // First pass: remove all p1
        stack<char> st;
        int score = 0;
        for (char ch : s) {
            if (!st.empty() && 
                ((p1 == "ab" && st.top() == 'a' && ch == 'b') ||
                 (p1 == "ba" && st.top() == 'b' && ch == 'a'))) {
                st.pop();
                score += firstScore;
            } else {
                st.push(ch);
            }
        }
        
        // Build remainder string in correct order
        string rem = "";
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        
        // Second pass: remove all p2 from the remainder
        for (char ch : rem) {
            if (!st.empty() && 
                ((p2 == "ab" && st.top() == 'a' && ch == 'b') ||
                 (p2 == "ba" && st.top() == 'b' && ch == 'a'))) {
                st.pop();
                score += secondScore;
            } else {
                st.push(ch);
            }
        }
        
        return score;
    }
};
