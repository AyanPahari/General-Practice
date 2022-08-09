class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>pref;
        pref.push_back(0);
        for(auto it: gain) pref.push_back(it);
        int i = 1;
        while(i < pref.size()){
            pref[i] += pref[i-1];
            i++;
        }
        return *max_element(pref.begin(),pref.end());
    }
};