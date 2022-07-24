class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            int low = i + 1, high = n - 1, sum = -nums[i];
            while(low < high){
                if(nums[low] + nums[high] == sum){
                    vector<int>temp(3,0);
                    temp[0] = nums[i];
                    temp[1] = nums[low];
                    temp[2] = nums[high];
                    ans.push_back(temp);
                    while(low < high && nums[low] == temp[1]) low++;
                    while(low < high && nums[high] == temp[2]) high--; 
                }
                else if(nums[low] + nums[high] > sum) high--;
                else low++;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};