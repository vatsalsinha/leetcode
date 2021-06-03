class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxi = 0, maxj = 0;
        for(int i = 0; i < horizontalCuts.size()-1; i++){
            maxi = max(maxi, horizontalCuts[i+1] - horizontalCuts[i]);
        }
        for(int j = 0; j < verticalCuts.size()-1; j++){
            maxj = max(maxj, verticalCuts[j+1] - verticalCuts[j]);
        }     
        const long long int modulo = pow(10,9) + 7;
        return ((long)maxi * maxj) % 1000000007;
    }
};
