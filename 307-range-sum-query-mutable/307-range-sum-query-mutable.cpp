class BIT {
    vector<int> bit;
public:
    BIT(int size = 0) {
        bit.assign(size + 1, 0);
    }
    
    void add(int val, int index) {
        while(index < bit.size()) {
            bit[index] += val;
            index += index & (-index);
        }
    }
    
    int sum(int index) {
        int res = 0;
        while(index > 0) {
            res += bit[index];
            index -= index & (-index);
        }
        return res;
    }    
};
class NumArray {
    BIT b;
    vector<int> arr; 
public:
    NumArray(vector<int>& nums) {
        this->b = BIT(nums.size());
        this->arr = nums;
        for(int i = 0; i < nums.size(); i++) {
            b.add(arr[i], i + 1);
        }
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        b.add(diff, index + 1);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int lsum = b.sum(left);
        int rsum = b.sum(right + 1);
        return rsum - lsum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */