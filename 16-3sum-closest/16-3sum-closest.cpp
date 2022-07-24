class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans, mindiff = INT_MAX;
        for(int i=0;i<n-2;i++){
            int low = i + 1, high = n - 1, sum = target - nums[i];
            while(low < high){
                int diff = abs(target - (nums[i] + nums[low] + nums[high]));
                if(diff < mindiff){
                    mindiff = diff;
                    ans = nums[i] + nums[low] + nums[high];
                }
                if(nums[low] + nums[high] == sum){
                    return target;
                }
                else if(nums[low] + nums[high] > sum) high--;
                else low++;
            }
        }
        return ans;
    }
};