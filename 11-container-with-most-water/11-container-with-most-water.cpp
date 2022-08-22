class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, maxi = INT_MIN;
        while(low < high){
            int val = min(arr[low], arr[high]) * (high - low);
            maxi = max(maxi, val);
            if(arr[low] > arr[high]) high--;
            else low++;
        }
        return maxi;
    }
};