class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, pos_sum = INT_MIN, neg_sum = INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            pos_sum = max(pos_sum, sum);
            if(sum < 0) sum = 0;
        }
        sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            neg_sum = min(neg_sum, sum);
            if(sum >= 0) sum = 0;
        }
        return max(abs(pos_sum), abs(neg_sum));
    }
};