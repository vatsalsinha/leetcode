class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
            return "";
        auto it = mp[key].lower_bound(timestamp);
        if(it->first == timestamp)
            return mp[key][timestamp];
        if(it == mp[key].begin())
            return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
