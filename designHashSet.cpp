struct Bucket{
    vector<int> bucket = {};
    void add(int val){
        if(!contains(val))
            bucket.push_back(val);
    }
    bool contains(int val){
        return find(bucket.begin(), bucket.end(), val) != bucket.end();
    }
    void remove(int val){
        auto pos = find(bucket.begin(), bucket.end(), val);
        if(pos != bucket.end())
            bucket.erase(pos);
    }
};
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<Bucket> buckets;
    int hashSize;
    MyHashSet(int keySpace = 137) {
        hashSize = keySpace;
        buckets.resize(keySpace);
    }
    
    void add(int key) {
        buckets[key % hashSize].add(key);
    }
    
    void remove(int key) {
        buckets[key%hashSize].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return buckets[key%hashSize].contains(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
