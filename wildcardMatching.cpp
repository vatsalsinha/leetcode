class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> A(p.length()+1,vector<bool>(s.length()+1,0));
        A[0][0] = 1;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                if(j==0 && i > 0){
                    if(p[i-1] == '*'){
                        A[i][j] = A[i-1][j];
                    }
                    else{
                        A[i][j] = 0;
                    }
                }
                if(j>0 && i>0){
                    if(p[i-1] != s[j-1] && p[i-1] != '*' && p[i-1] != '?'){
                        A[i][j] = 0;
                    }
                    else if(p[i-1] == s[j-1]){
                        A[i][j] = A[i-1][j-1];
                    }
                    else if(p[i-1] == '?'){
                        A[i][j] = A[i-1][j-1];
                    }
                    else if(p[i-1] == '*'){
                        A[i][j] = A[i-1][j] || A[i][j-1] || A[i-1][j];
                    }
                }
            }
        }
        return A[p.length()][s.length()];
    }
};
