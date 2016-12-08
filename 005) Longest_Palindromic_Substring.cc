// Brute Force
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

// Dynamic Programming 
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        bool sub[len][len];
        int maxlen = 1;
        int start = 0;
        memset(sub, 0 , sizeof(sub));
        for (int i = 0; i < len; i++) {
            sub[i][i] = true;
        }
        
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                sub[i][i+1] = true;
                start = i;
                maxlen = 2;
            }
        }
        for (int j = 3; j <= len; j++) {
            for(int i = 0; i < len-j+1; i++) {
                int q = i + j - 1;
                if(sub[i+1][q-1] && s[i] == s[q]) {
                    sub[i][q] = true;
                    if (j > maxlen) {
                        start = i;
                        maxlen = j;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
