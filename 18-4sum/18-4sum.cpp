class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int low = j + 1, high = n - 1;
                long long sum = (long long)target - nums[i] - nums[j];
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        vector<int>temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        while(low < high && nums[low] == temp[2]) low++;
                        while(low < high && nums[high] == temp[3]) high--; 
                    }
                    else if(nums[low] + nums[high] > sum) high--;
                    else low++;
                }
                while(j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};