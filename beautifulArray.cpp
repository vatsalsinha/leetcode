class Solution {
public:
    vector<int> beautifulArray(int n) {
        /* Approach 1
        if(n == 1)
            return {1};
        vector<int> even = beautifulArray(n/2);
        vector<int> odd = beautifulArray(n - n/2);
        vector<int> ans;
        for(auto e : even)
            ans.push_back(2*e);
        for(auto o : odd)
            ans.push_back(2*o-1);
        return ans;
        */
        vector<int> ans = {1};
        if(n == 1)
            return ans;
        while(ans.size() < n){
            vector<int> tmp;
            for(int i : ans)
                if(i*2 - 1 <= n)
                    tmp.push_back(i*2-1);
            for(int i : ans)
                if(i*2 <= n)
                    tmp.push_back(i*2);
            ans = tmp;
        }
        return ans;
    }
};
