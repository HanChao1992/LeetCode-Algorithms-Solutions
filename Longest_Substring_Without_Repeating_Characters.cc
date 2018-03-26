class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> help;
        unordered_map<char, int>::iterator it;
        int max = 0;
        for (int j = 0, i = 0; j < s.length(); j++) {
            it = help.find(s[j]);
            if (it != help.end()) {
                i = maxi(help[s[j]], i);    
            }
            max = maxi(max, j - i + 1);
            help[s[j]] = j + 1;
        }
        return max;
    }
    
    int maxi(int a, int b) {
        return a > b ? a : b;
    }
};
