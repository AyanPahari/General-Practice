class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        long long sum = 0, sum1 = 0, sum2 = 0, mod = 1e9 + 7;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                sum1 = sum1 + nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]){
                sum2 = sum2 + nums2[j];
                j++;
            }
            else{
                sum += max(sum1,sum2) + nums1[i];
                i++, j++;
                sum1 = 0, sum2 = 0;
            }
        }
        while(i < nums1.size()){
            sum1 += nums1[i];
            i++;
        }
        while(j < nums2.size()){
            sum2 += nums2[j];
            j++;
        }
        return (max(sum1, sum2) + sum) % mod;
    }
};