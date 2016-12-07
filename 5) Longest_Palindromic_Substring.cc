class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int j = len -1 ;
        for (int i = 0; i < len; i++) {
            if (s[i] != s[j]) {
                return false;
            }
            if (i == j) {
                break;
            }
            j--;
            
        }
        return true;
    }
    string longestPalindrome(string s) {
        int len = s.length();
        int max = 1;
        int start = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                //cout << s.substr(i, j - i + 1) << endl;
                if(isPalindrome(s.substr(i, j - i + 1))) {
                    //cout << s.substr(i, j - i + 1) << " is pa." << endl;
                    if ((j - i + 1) > max) {
                        max = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        string result = s.substr(start, max);
        return result;
    }
};
