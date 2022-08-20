class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0, i = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        while(i < n - 1){
            if(binary_search(nums.begin() + i + 1, nums.end(), nums[i] + k)) count++;
            while(nums[i] == nums[i + 1] && i != n - 2) i++;
            i++;
        }
        return count;
    }
};