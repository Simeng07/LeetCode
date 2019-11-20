class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        int count[26] = {0};
        bool isVisited[26] = {false};
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i]-'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i]-'a']--;
            if ((isVisited[s[i]-'a']) || (!stk.empty() && stk.top() == s[i]))
                continue;
            while (!stk.empty() && stk.top() > s[i] && count[stk.top()-'a'] != 0) {
                isVisited[stk.top()-'a'] = 0;
                stk.pop();
            }
            stk.push(s[i]);
            isVisited[s[i]-'a'] = true;
        }
        
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
    }
};