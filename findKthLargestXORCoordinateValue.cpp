class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        vector<vector<int>> prefixXOR(matrix.size(), vector<int>(matrix[0].size()));
        prefixXOR[0][0] = matrix[0][0];
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0 && j == 0) 
                    prefixXOR[i][j] = matrix[0][0];
                else if(i == 0 && j != 0) 
                    prefixXOR[i][j] = prefixXOR[i][j-1] ^ matrix[i][j];
                else if(i != 0 && j == 0) 
                    prefixXOR[i][j] = prefixXOR[i-1][j] ^ matrix[i][j];
                else 
                    prefixXOR[i][j] = prefixXOR[i-1][j] ^ prefixXOR[i][j-1] ^ prefixXOR[i-1][j-1] ^ matrix[i][j];
                pq.push(prefixXOR[i][j]);
            }
        }        
        while(pq.size()>k){
            pq.pop();
        }
        return pq.top();   
    }
};
