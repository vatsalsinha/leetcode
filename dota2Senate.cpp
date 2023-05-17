class Solution {
public:
    string predictPartyVictory(string senate) {
        int d = 0, r = 0;
        queue<char> q;
        for(char c : senate){
            q.push(c);
            if(c == 'D')
                d++;
            else
                r++;
        }
        int d_ban = 0, r_ban = 0; // d_ban -> how many chances D has to ban R, how many chances R has to ban D
        while(r && d){
            char curr = q.front();
            q.pop();
            if(curr == 'D'){
                if(d_ban){
                    d_ban--;
                    d--;
                }
                else{
                    r_ban++;
                    q.push('D'); // since D has banned R, pushing D again as we had popper out.
                }
            }
            else{
                if(r_ban){
                    r_ban--;
                    r--;
                }
                else{
                    d_ban++;
                    q.push('R');
                }
            }
        }
        return r > 0 ? "Radiant" : "Dire";
    }
};
