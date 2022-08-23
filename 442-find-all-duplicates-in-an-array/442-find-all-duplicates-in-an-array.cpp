class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(i == nums[i] - 1 || nums[i] == nums[nums[i] - 1]){
                i++;
                continue;
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(i != nums[i] - 1) res.push_back(nums[i]);
        }
        return res;
    }
};