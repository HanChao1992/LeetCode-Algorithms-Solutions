class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string result = "";
        bool emp = false;
        if (len == 1) {
            return strs[0];
        }
        else if (strs.empty()) {
            return result;
        }
        while(!emp) {
            for (int i = 1; i < len; i++) {
                if ((strs[i].empty()) || (strs[0].empty())) {
                    return result;
                }
                if (strs[i][0] == strs[0][0]) {
                    strs[i].erase(strs[i].begin());
                }
                else {
                    return result;
                }
            
            }
            result = result + strs[0][0];
            strs[0].erase(strs[0].begin());
        }
        return result;
    }
};
