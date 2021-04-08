class Solution {
public:
    vector<vector<int>> twosum(vector<int>& nums, int target, int start){
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int low = start, high = nums.size()-1, sum;
        while(low < high){
            sum = nums[low] + nums[high];
            if(sum == target){
                res.push_back({nums[low], nums[high]});
                while(low < high && nums[low] == nums[low+1]) low++;
                while(low < high && nums[low] == nums[high-1]) high--;
                low++;
                high--;
            }
            else if(sum > target){
                high--;
            }
            else{
                low++;
            }
        }
        return res;
    }
    vector<vector<int>> ksum(vector<int>& nums, int start, int k, int target){
        sort(nums.begin(), nums.end());
        if(nums.size() == start ||  nums.size() < k){
            vector<vector<int>> res;
            return res;
        }
        if(k==2){
            return twosum(nums, target, start);
        }
        vector<vector<int>> res;
        for(int i = start; i < nums.size()-k+1; i++){
            if(i == start || nums[i-1] != nums[i]){
                for(auto &set : ksum(nums, i+1, k-1, target-nums[i])){
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
                // vector<vector<int>> currentres = ksum(nums, i+1, k-1, target-nums[i]);
                // for(int j = 0; j < currentres.size(); j++){
                //     currentres[j].push_back(nums[i]);
                //     res.insert(res.end(), currentres.begin(), currentres.end());
                // }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return ksum(nums, 0, 4, target);
    }    
};   
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // if(nums.size() == 0 || nums.size()  < 4){
        //      vector<vector<int>> res = {};
        //     return res;
        // }
        // sort(nums.begin(), nums.end());
        // int sum, high, higher, highest;
        // set<vector<int>> ans;
        // for(int i = 0; i < nums.size()-3; i++){
        //     for(int j = i+1; j < nums.size()-2; j++){
        //         higher = j+1;
        //         highest = nums.size()-1;
        //         while(higher < highest){
        //             sum = nums[i] + nums[j] + nums[higher] + nums[highest];
        //             if (sum == target){
        //                 vector<int> tmp;
        //                 tmp.push_back(nums[i]);
        //                 tmp.push_back(nums[j]);
        //                 tmp.push_back(nums[higher]);
        //                 tmp.push_back(nums[highest]);
        //                 ans.insert(tmp);
        //                 while(higher < highest && nums[higher] == nums[higher+1]) higher++;
        //                 while(higher < highest && nums[higher] == nums[highest-1]) highest--;     
        //                 higher++;
        //                 highest--;
        //             }
        //             else if(sum > target) {
        //                 highest--;
        //             }
        //             else{
        //                 higher++;
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> res(ans.begin(), ans.end());
        // return res;

