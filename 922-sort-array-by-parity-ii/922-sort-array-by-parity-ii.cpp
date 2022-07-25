class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n, 0);
        int id_e = 0, id_o = 1;
        for(int i=0;i<n;i++){
            if(nums[i] % 2 == 0){
                res[id_e] = nums[i];
                id_e += 2;
            }
            else{
                res[id_o] = nums[i];
                id_o += 2;
            }
        }
        return res;
    }
};