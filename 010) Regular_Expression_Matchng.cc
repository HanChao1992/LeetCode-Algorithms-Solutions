class Solution {
public:
    bool isMatch(string s, string p) {
        vector <pair <char, int>> s1;
        vector <char> mem;
        int slen = s.length();
        char spre = NULL;
        for (int i = 0; i < slen; i++) {
            if (s[i] != spre) {
                s1.push_back(make_pair(s[i], 1));
                mem.push_back(s[i]);
            }
            else {
                s1.back().second++;
            }
            spre = s[i];
        }
        for(int j = 0; j < s1.size(); j++) {
            cout << s1[j].first << ":" << s1[j].second << endl;
        }
        for(int j = 0; j < mem.size(); j++) {
            cout << mem[j] << endl;
        }
        vector <pair <char, int>> p1;
        int plen = p.length();
        char ppre = NULL;
        for (int i = 0; i < plen; i++) {
            if (p[i] != '*' && p[i] != '.') {
                if (i+1 < plen && p[i+1] != '*' || i+1 >= plen){
                    if (find(mem.begin(), mem.end(), p[i]) != mem.end()) {
                    }
                    else {
                        cout << "member diff" << endl;
                        return false;
                    }
                }
            }
            if (p[i] == '*') {
                p1.back().second = -1;
            }
            else if (p[i] != ppre) {
                p1.push_back(make_pair(p[i], 1));
            }
            else {
                p1.back().second++;
            }
            ppre = p[i];
        }
        for(int j = 0; j < p1.size(); j++) {
            cout << p1[j].first << ":" << p1[j].second << endl;
        }
        int s11 = 0;
        int p11 = 0;
        while (s11 < s1.size() && p11 < p1.size()) {
            if (s1[s11].first == p1[p11].first) {
                if (s1[s11].second == p1[p11].second || p1[p11].second == -1) {
                    s11++;
                    p11++;
                }
                if (s1[s11].second != p1[p11].second) {
                    if (p11+1 < p1.size() && p1[p11+1].first != '.' || p11+1 >= p1.size()) {
                        return false;
                    }
                }
            }
            else if (p1[p11].first == '.') {
                if (p1[p11].second == -1) {
                    break;
                }
                s1[s11].second--;
                p1[p11].second--;
                if (s1[s11].second == 0) {
                    s11++;
                }
                if (p1[p11].second == 0) {
                    p11++;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};
