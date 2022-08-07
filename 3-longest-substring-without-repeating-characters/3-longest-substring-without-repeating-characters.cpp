class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int i = 0, j = 0, maxi = 0;
        while(j < s.length()){
            mp[s[j]]++;
            if(j - i + 1 == mp.size()) maxi = max(maxi, j - i + 1);
            else if(j - i + 1 > mp.size()){
                while(j - i + 1 > mp.size()){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                if(j - i + 1 == mp.size()) maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
};