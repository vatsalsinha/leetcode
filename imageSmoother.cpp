class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >=0 && j < n;
    }
    int get_avg(int i, int j, vector<vector<int>>& img){
        int sum = img[i][j], count = 1;
        for(int k = 0; k < 8; k++){
            if(isValid(i+directions[k].first, j+directions[k].second, (int)img.size(), (int)img[0].size()))
                sum += img[i+directions[k].first][j+directions[k].second], count++;
        }
        return floor(sum/count);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
        for(int i = 0; i < img.size(); i++){
            for(int j = 0; j < img[0].size(); j++){
                ans[i][j] = get_avg(i, j, img);
            }
        }
        return ans;
    }
};
