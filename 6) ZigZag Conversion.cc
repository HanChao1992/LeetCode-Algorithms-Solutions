class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int len = s.length();
        for (int j = 0; j <= numRows; j++) {
        for (int i = 0; i < len; i = i + 4) {
            result = result + s[i];
        }
        for (int i = 1; i < len; i = i + 2) {
            result = result + s[i];
        }
        for (int i = 2; i < len; i = i + 4) {
            result = result + s[i];
        }
        return result;
    }
};
