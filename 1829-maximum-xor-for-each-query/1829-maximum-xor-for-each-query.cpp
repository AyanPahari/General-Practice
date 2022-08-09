class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>pref = nums;
        int i = 1;
        while(i < nums.size()){
            pref[i] ^= pref[i - 1];
            i++;
        }
        reverse(pref.begin(), pref.end());
        vector<int>ans;
        int bit = pow(2, maximumBit) - 1;
        for(int i=0;i<nums.size();i++) ans.push_back(bit - pref[i]);
        return ans;
    }
};