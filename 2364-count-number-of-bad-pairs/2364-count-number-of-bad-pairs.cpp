class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total_pairs = (long long)n * (n - 1) / 2;
        unordered_map<int,int>mp;
        long long count = 0;
        for(int i=0;i<n;i++){
            if(mp.find(i - nums[i]) != mp.end()) count += mp[i - nums[i]];
            mp[i - nums[i]]++;
        }
        return total_pairs - count;
    }
};