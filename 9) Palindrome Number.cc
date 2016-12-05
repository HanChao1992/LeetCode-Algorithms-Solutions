class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int remain = 0;
        vector <int> help;
        while (x != 0) {
            remain = x % 10;
            x = x/10;
            help.push_back(remain);
        }
        while (!help.empty()) {
            if (help.front() == help.back()) {
                cout << help.front() << " is equal to " << help.back() << endl;
                help.erase(help.begin());
                if (!help.empty()) {
                    help.pop_back();
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};
