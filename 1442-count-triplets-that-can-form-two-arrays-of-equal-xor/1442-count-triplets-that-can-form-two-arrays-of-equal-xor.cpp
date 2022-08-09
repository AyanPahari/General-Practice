class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        vector<int>pref;
        pref.push_back(0);
        for(auto it:arr) pref.push_back(it);
        int i = 1;
        while(i < pref.size()){
            pref[i] ^= pref[i - 1];
            i++;
        }
        int count = 0;
        for(int i=0;i<pref.size()-1;i++){
            for(int j=i+1;j<pref.size();j++){
                for(int k=j;k<pref.size()-1;k++){
                    int a = pref[j] ^ pref[i];
                    int b = pref[k + 1] ^ pref[j];
                    if(a == b) count++;
                }
            }
        }
        return count;
    }
};