class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            arr[i] = arr[i] % k;
            if(arr[i] < 0) arr[i] = arr[i] + k;
            mp[arr[i]]++;
        }
        if(mp[0] % 2 != 0) return false;
        if(k % 2 == 0 && mp[k / 2] % 2 != 0) return false;
        for(int i=0;i<arr.size();i++){
            if(arr[i] != 0){
                if(mp[arr[i]] != mp[k - arr[i]]) return false;
            }
        }
        return true;
    }
};