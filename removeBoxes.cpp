class Solution {
public:
    int removeBoxes(vector<int>& boxes)
    {
        int dp[100][100][100] = {0};    // number of boxes would not exceed 100
        int n = boxes.size();
        return operate(boxes, 0, n-1, 0, dp);   // in the closed interval [0, n-1]
    }

    int operate(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) // i : left, j : right, k : streak
    {
        // [i, j] is the operating closed interval
        // k is the number of adjacent boxes on the left of boxes[i] with the same value
        if (i>j) return 0;
        if (dp[i][j][k]>0) return dp[i][j][k];

        // start with boxes[i] and interval [i+1, j]
        int res = (k+1)*(k+1) + operate(boxes, i+1, j, 0, dp);
        for (int m=i+1; m<=j; m++)
        {
            // if boxes[i]==boxes[m], we can thus eliminate interval [i+1, m-1]
            // to make boxes[i] and boxes[m] adjacent to have a higher score
            if (boxes[i]==boxes[m])
                // if boxes[i] and boxes[m] are adjacent, then
                // there will be k+1 boxes on the left of boxes[m] with the same value
                res = max( res, operate(boxes, i+1, m-1, 0, dp)+operate(boxes, m, j, k+1, dp) );
        }
        dp[i][j][k] = res;
        return res;
    }
};
