class Solution {
public:
    int kadane(vector<int> vt,int k){
        set<int> st;
        int sum=0;
        int result=INT_MIN;
        st.insert(0);
        for(int i=0;i<vt.size();i++){
            sum+=vt[i];
            auto it=st.lower_bound(sum-k);
            
            if(it!=st.end()){
                result=max(result,sum-(*it));
            }
            
            st.insert(sum);
        }
        
        return result;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        vector<int> dp(mat.size());
        int maxSum = INT_MIN;
        //int l = 0, r = 0;
        //int maxUp = INT_MIN, maxDown = INT_MIN, maxLeft = INT_MIN, maxRight = INT_MIN;
        for(int left = 0; left < mat[0].size(); left++){
            for(int i = 0; i < mat.size(); i++){
                dp[i] = 0;
            }
            for(int right = left; right < mat[0].size(); right++){
                for(int i = 0; i < mat.size(); i++)
                    dp[i] += mat[i][right];
                int kadaneResult = kadane(dp,k);
                maxSum = max(maxSum, kadaneResult);
            }
        }
        return maxSum;
    }
};
