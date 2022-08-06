class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref = nums;
        vector<int>suff = nums;
        int i = 1, j = n - 2;
        while(i < n){
            pref[i] *= pref[i - 1];
            i++;
        }
        while(j >= 0){
            suff[j] *= suff[j + 1];
            j--;
        }
        vector<int>ans(n);
        ans[0] = suff[1];
        ans[n - 1] = pref[n - 2];
        for(int i=1;i<n-1;i++){
            ans[i] = pref[i - 1] * suff[i + 1];
        }
        return ans;
    }
};