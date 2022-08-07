class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char, int> mp;
        int count = 0;
        for (int i = 0; i < word.length(); ++i) {
            mp.clear();
            for (int j = i; j < word.length(); ++j) {
                if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') mp[word[j]]++;
                else break;
                if(mp.size() == 5) count++;
            }
        }
        return count;
    }
};