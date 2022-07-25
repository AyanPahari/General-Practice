class Solution {
public:
    
    bool isValid(string s, string str){
        int i = 0, j = 0;
        while(i < s.length() && j < str.length()){
            if(s[i] == str[j]){
                i++;
                j++;
            }
            else i++;
        }
        return j == str.length();
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        sort(dictionary.begin(), dictionary.end());
        for(auto str: dictionary){
            if(isValid(s, str)){
                if(res.length() < str.length()) res = str;
            }
        }
        return res;
    }
};