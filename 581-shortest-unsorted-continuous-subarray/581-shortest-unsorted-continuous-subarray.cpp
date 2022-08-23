class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0, maxL = INT_MIN, minR = INT_MAX;
        for(int i=0;i<n;i++){
            maxL = max(maxL, nums[i]);
            if(maxL > nums[i]) end = i;
        }
        for(int i=n-1;i>=0;i--){
            minR = min(minR, nums[i]);
            if(nums[i] > minR) start = i;
        }
        if(start == 0 && end == 0) return 0;
        else return end - start + 1;
    }
};