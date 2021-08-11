class Solution {
public:
    bool static cmp(int a, int b){
        return abs(a) < abs(b);
    }
    bool canReorderDoubled(vector<int>& a) {
        // approach 1
//         int n=a.size(),i;
//         multiset<float> s;
//         for( auto no : a )
//         {
//             s.insert(no);
//         }
//         for( auto ele=s.begin();ele!=s.end();ele++)
//         {
//             float val;
//             if(*ele<0)
//             {
//                 val=(*ele/2);
//             }
//             else
//             {
//                 val=2*(*ele);
//             }
//             auto id=s.find(val);
//             if(id==ele)
//                 id++;
//             if(id==s.end())
//                 return 0;
//             s.erase(id);
//             s.erase(ele);
//         }
        
//         return 1 ;
        //approach 2
        unordered_map<int, int> dict;
        for(auto s : a)
            dict[s]++;
        vector<int> keys;
        for(auto it : dict)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), cmp);
        for(auto x : keys){
            if(dict[x] > dict[2*x])
                return false;
            dict[2*x] -= dict[x];
        }
        return true;
    }
};
