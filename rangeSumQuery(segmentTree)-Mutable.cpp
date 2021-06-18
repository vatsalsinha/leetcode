struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
};
class NumArray {
    SegmentTreeNode* root;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        root = buildTree(nums,0,n-1);
    }
   
    void update(int i, int val) {
        modifyTree(i,val,root);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, root);
    }
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
        if(start > end) return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        if(start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) {
            diff = modifyTree(i,val,root->right);
        } else {
            diff = modifyTree(i,val,root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    int queryTree(int i, int j, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(i > mid) return queryTree(i,j,root->right);
        if(j <= mid) return queryTree(i,j,root->left);
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }
};

//APPROACH 2
/*
struct SegmentTreeNode {
        int start, end;
        SegmentTreeNode *left, *right;
        int sum;
        
        SegmentTreeNode(int _start, int _end)
            :start(_start),end(_end),left(NULL),right(NULL),sum(0) {}
};
class NumArray {
public:
    SegmentTreeNode* root;
    SegmentTreeNode* buildTree(const vector<int>& nums, int start, int end) {
        if(start > end) {
            return NULL;
        } else {
            SegmentTreeNode* ret = new SegmentTreeNode(start,end);
            if(start == end) {
                ret->sum = nums[start];
            } else {
                int mid=start+(end-start)/2;
                ret->left = buildTree(nums,start,mid);
                ret->right = buildTree(nums,mid+1,end);
                ret->sum = ret->left->sum + ret->right->sum;
            }
            return ret;
        }
    }
    void update(SegmentTreeNode* root, int pos, int val) {
        if(root->start == root->end) {
            root->sum = val;
        } else {
            int mid = root->start+(root->end-root->start)/2;
            if(pos <= mid) {
                update(root->left, pos, val);
            } else {
                update(root->right, pos, val);
            }
            root->sum = root->left->sum + root->right->sum;
        }
    }
    
    int sumRange(SegmentTreeNode* root, int start, int end) {
        if (root->end == end && root->start == start) {
            return root->sum;
        } else {
            int mid=root->start+(root->end-root->start)/2;
            if (end <= mid) {
                return sumRange(root->left, start, end);
            } else if (start >= mid+1) {
                return sumRange(root->right, start, end);
            }  else {    
                return sumRange(root->left, start, mid)+sumRange(root->right, mid+1, end);
            }
        }
    }
    NumArray(vector<int> nums) {
        root = buildTree(nums, 0, nums.size()-1);    
    }
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
};


*/
