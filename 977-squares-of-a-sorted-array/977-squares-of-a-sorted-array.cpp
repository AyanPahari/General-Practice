class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        vector<int>ans(nums.size(), 0);
        int ind = nums.size() - 1;
        while(low <= high){
            if(abs(nums[low]) > abs(nums[high])){
                ans[ind--] = nums[low] * nums[low];
                low++;
            }
            else if(abs(nums[low]) < abs(nums[high])){
                ans[ind--] = nums[high] * nums[high];
                high--;
            }
            else if(low == high && abs(nums[low]) == abs(nums[high])){
                ans[ind--] = nums[low] * nums[low];
                low++;
                high--;
            }
            else{
                ans[ind--] = nums[low] * nums[low];
                ans[ind--] = nums[high] * nums[high];
                low++;
                high--;
            }
        }
        return ans;
    }
};