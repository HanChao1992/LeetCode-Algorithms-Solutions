class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                q.push(s[i]);
            }
            if(s[i] == ')') {
                if(!q.empty() && q.top() == '(') {
                    q.pop();
                }
                else {
                    return false;
                }
            }
            if(s[i] == ']') {
                if(!q.empty() && q.top() == '[') {
                    q.pop();
                }
                else {
                    return false;
                }
            }
            if(s[i] == '}') {
                if(!q.empty() && q.top() == '{') {
                    q.pop();
                }
                else {
                    return false;
                }
            }
            
        }
        if(q.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
