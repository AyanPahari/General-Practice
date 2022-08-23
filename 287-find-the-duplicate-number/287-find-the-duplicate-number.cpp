class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n){
            if(i == nums[i] - 1 || nums[i] == nums[nums[i] - 1]){
                i++;
                continue;
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i=0;i<n;i++){
            if(i != nums[i] - 1) return nums[i];
        }
        return n;
    }
};