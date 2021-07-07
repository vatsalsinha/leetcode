class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //brute force
        // vector<int> m(matrix[0].begin(), matrix[0].end());
        // for(int i = 1; i < matrix.size(); i++){
        //     for(auto c : matrix[i]){
        //         m.push_back(c);
        //     }
        // }
        // sort(m.begin(), m.end());
        // return m[k-1];
        
        //binary search
        if(matrix.empty())
            return 0;
        int low = matrix[0][0];
        int high = matrix[matrix.size()-1][matrix.size()-1];
        while(low < high){
            int mid = (low + high)/2;
            int count = 0;
            for(int i = 0; i < matrix.size(); i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if(count < k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};
