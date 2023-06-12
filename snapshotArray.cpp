class SnapshotArray {
public:
    vector<unordered_map<int,int>> arr;
    int count = 0;
    SnapshotArray(int length) {
        arr = vector<unordered_map<int,int>> (length,unordered_map<int,int>());
    }
    
    void set(int index, int val) {
        arr[index][count] = val;
    }
    
    int snap() {
        return count++;
    }
    
    int get(int index, int snap_id) {
        while(snap_id >= 0 and arr[index].find(snap_id) == arr[index].end())
            snap_id--;
        if(snap_id == -1)
            return 0;
        return arr[index][snap_id];
    }
};
