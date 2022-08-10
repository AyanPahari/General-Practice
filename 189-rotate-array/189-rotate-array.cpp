class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>temp(n);
        k = k % n;
        for(int i=0;i<n;i++){
            int ind = (i + k % n) % n;
            temp[ind] = nums[i];
        }
        for(int i=0;i<n;i++) nums[i] = temp[i];
    }
};