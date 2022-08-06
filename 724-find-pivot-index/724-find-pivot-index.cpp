class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>suff = nums;
        vector<int>pref = nums;
        int i = 1, j = nums.size() - 2;
        while(i < nums.size()){
            pref[i] += pref[i - 1];
            i++;
        }
        while(j >= 0){
            suff[j] += suff[j + 1];
            j--;
        }
        for(int i=0;i<nums.size();i++){
            if(pref[i] == suff[i]) return i;
        }
        return -1;
    }
};