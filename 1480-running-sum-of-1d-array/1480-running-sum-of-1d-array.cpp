class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>pref = nums;
        int i = 1;
        while(i < nums.size()){
            pref[i] += pref[i - 1];
            i++;
        }
        return pref;
    }
};