class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        for(int i = 1; i < rating.size()-1; i++){
            int x1 = 0,x2 = 0,y1 = 0,y2 = 0;
            for(int j = 0; j < i; j++){
                if(rating[i] < rating[j])
                    x1++;
                else
                    x2++;
            }
            for(int j = i+1; j < rating.size(); j++){
                if(rating[i] < rating[j])
                    y1++;
                else
                    y2++;
            }
            count += x1*y2 + x2*y1;
        }
        return count;
    }
};

/* O(nlogn) solution. logic not clear yet

class Solution {
    void update(vector<int> &v, int i, const int d) {
        for (; i < v.size();  i += (i & -i)){
            v[i] += d;
            cout<<v[i]<<" ";
        }
    }
    
    int presum(const vector<int> &v, int i) {
        int r = 0;
        for (; i; i -= (i & -i)){
            r += v[i];
            cout<<v[i]<<"u" ";
        }
        return r;
    }
    
public:
    int numTeams(vector<int>& rating) {
        map<int, int> have;
        for (int x : rating) {
            have[x];
        }
        int n = 0;
        vector<int> after(rating.size() + 1);
        for (auto& t : have) { 
            update(after, t.second = ++n, 1);
        }
        vector<int> before(n + 1);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            const int x = have[rating[i]], t1 = presum(before, x), t2 = presum(after, x);
            r += t1 * (n - i - t2) + (i - t1) * (t2 - 1);
            update(after, x, -1);
            update(before, x, 1);
        }
        return r;
        
    }
};
*/