class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, low = 0, high = nums.size() - 1;
        while(low < high){
            ans = max(ans, nums[low] + nums[high]);
            low++;
            high--;
        }
        return ans;
    }
};