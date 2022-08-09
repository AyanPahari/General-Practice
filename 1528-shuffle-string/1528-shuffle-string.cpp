class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string st = s;
        for(int i=0;i<s.length();i++) st[indices[i]] = s[i];
        return st;
    }
};