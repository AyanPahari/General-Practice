class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<int>res;
        int idx = 0;
        for(int i=0;i<n;i++){
            res.push_back(nums[i]);
            int sum = nums[i];
            for(int j=i+1;j<n;j++){
                sum += nums[j];
                res.push_back(sum);
            }
        }
        sort(res.begin(),res.end());
        int ans = 0;
        for(int i=left-1;i<right;i++) ans = (ans % mod + res[i] % mod) % mod;
        return ans;
    }
};