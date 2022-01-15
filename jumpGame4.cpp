class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1)
            return 0;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < arr.size(); i++){
            graph[arr[i]].push_back(i); // building graph
        }
        queue<int> q; // queue of indexes
        q.push(0);
        vector<bool> visited(arr.size(), 0);
        visited[0] = 1;
        int count = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front(); // curr is index
                q.pop();
                if(curr == arr.size()-1)
                    return count;
                vector<int>& vec = graph[arr[curr]];
                vec.push_back(curr-1);
                vec.push_back(curr+1);
                for(auto i : vec){
                    if(i >= 0 && i < arr.size() && !visited[i]){ // checking out of range exception
                        visited[i] = 1;
                        q.push(i);
                    }
                }
                vec.clear(); // so that no time is wasted again in checking for the same index.
            }
            count++;
        }
        return -1;
    }
};
