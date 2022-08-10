class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) if(nums[i] == 0) nums[i] = -1;
        unordered_map<int,int>mp;
        int maxi = INT_MIN, sum = 0;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mp.find(sum) != mp.end()) maxi = max(maxi, i - mp[sum]);
            else mp[sum] = i;
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};