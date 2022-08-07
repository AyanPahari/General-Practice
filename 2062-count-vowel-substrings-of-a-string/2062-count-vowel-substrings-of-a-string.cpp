class Solution {
public:
    
    bool isValid(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    int countVowelSubstrings(string word) {
        unordered_map<char, int> mp;
        int count = 0;
        for (int i = 0; i < word.length(); ++i) {
            mp.clear();
            for (int j = i; j < word.length() && isValid(word[j]); ++j) {
                mp[word[j]]++;
                if(mp.size() == 5) count++;
            }
        }
        return count;
    }
};