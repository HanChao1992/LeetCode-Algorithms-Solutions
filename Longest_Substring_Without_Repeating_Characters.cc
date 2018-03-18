class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        map<char, int> mapping;

        int start, end;
        int max = 0;
        start = 0;
        int i = 0;
        int sublen = 0;
         while (i < len) {
           if (mapping.find(s[i]) != mapping.end()) {
             //cout << "Found " << s[i] << " in position " << i << " in map position " << mapping[s[i]] << endl;
             int temp = i;
             i = mapping[s[temp]] + 2;
             start = mapping[s[temp]] + 1;
             char tempchar = s[start];
             mapping.clear();
             mapping[tempchar] = start;
           }
           else {
             mapping[s[i]] = i;
             end = i;
             i++;
            }
            sublen = end - start + 1;
            if (max < sublen) {
                max = sublen;
            }
        }
        return max;
    }
};
