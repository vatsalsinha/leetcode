class Solution {
public:
    int countSubstrings(string s, string t) {
        //keep i pointer on s and iterate through all j in t and check for exact difference of one 
//continue the loop until you reach the length or get difference more than one 
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < t.size(); j++){
                int s_i = i;
                int t_j = j;
                int diff = 0;
                while(s_i < s.size() && t_j < t.size() && diff <= 1){
                    if(s[s_i] != t[t_j])
                        diff++;
                    if(diff == 1)
                        count++;
                    s_i++;
                    t_j++;
                }
            }
        }
        return count;
    }
};
