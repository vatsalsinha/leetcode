class Solution {
public:
    bool isMatch(string s, string p) {
        //int s_len = s.size();
        //int p_len = p.size();
        /*
        case:
            p[i] = s[j] : check diagonally up
            p[i] != s[j] : False
            p[i] = . : check diagonally up
            p[i] = * : default 2 rows up; if p[i-1] = s[j] || p[i-1] = . : check one column left or 2 rows up(jo bhi true hoga wo select krne ka)
        */
        vector<vector<bool>> A(p.length()+1,vector<bool>(s.length()+1,0));
        A[0][0] = 1;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                // i-> pattern j-> text
                if(j == 0 && i > 0){
                    if(p[i-1] == '*'){
                        A[i][j] = A[i-2][j];
                    }
                    else{
                        A[i][j] == 0;
                    }
                }
                if(i>0 && j>0){
                    if(p[i-1] != s[j-1] && p[i-1] != '*' && p[i-1] != '.'){
                        A[i][j] = 0;
                    }
                    else if(p[i-1] == s[j-1]){
                        A[i][j] = A[i-1][j-1];
                    }
                    else if(p[i-1] == '.'){
                        A[i][j] = A[i-1][j-1];
                    }
                    else if(p[i-1] == '*'){
                        if(p[i-2] == s[j-1] || p[i-2] == '.'){
                            A[i][j] = A[i-2][j] || A[i][j-1];
                        }
                        else{
                            A[i][j] = A[i-2][j];
                        }
                    }
                }
            }
        }
        return A[p.length()][s.length()];
    }
};