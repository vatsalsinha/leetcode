class Item{
public:
    int key, val;
    Item(int k, int v){
        key = k;
        val = v;
    }
};
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<list<Item>> mp;
    int len = 349;
    MyHashMap() {
        mp.resize(len);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket = key % len;
        if(mp[bucket].empty()){
            Item i(key, value);
            mp[bucket].push_back(i);
            return;
        }
        else{
            for(auto it = mp[bucket].begin(); it != mp[bucket].end(); it++){
                auto a = *it;
                if(a.key == key){
                    it->val = value;
                    return;
                }
            }
            Item i(key, value);
            mp[bucket].push_back(i);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket = key % len;
        if(mp[bucket].empty())
            return -1;
        else{
            for(auto it = mp[bucket].begin(); it != mp[bucket].end(); it++){
                auto i = *it;
                if(i.key == key)
                    return i.val;
                
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket = key % len;
        if(mp[bucket].empty())
            return;
        else{
            for(auto it = mp[bucket].begin(); it != mp[bucket].end(); it++){
                auto i = *it;
                if(i.key == key){
                    it->val = -1;
                    return;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
