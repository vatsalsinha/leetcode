class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> rotated_box(n, vector<char>(m,'.'));
        
        //rotated
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rotated_box[i][j] = box[m-1-j][i];
            }
        }
        //gravity effect
        for(int j = 0; j < m; j++){
            int last = n-1;
            for(int i = n-1; i > 0; i--){
                if(rotated_box[i-1][j] == '#' && rotated_box[last][j] == '.' && rotated_box[i][j] != '*'){
                    swap(rotated_box[i-1][j], rotated_box[last][j]);
                    last--;
                }
                else if(rotated_box[i][j] == '*')
                    last = i-1;
                else if(rotated_box[i][j] == '#')
                    last--;
            }
        }
        
        return rotated_box;
    }
};
