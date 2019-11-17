class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                A++;
                continue;
            }
            s[secret[i] - '0']++;
            g[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            B += min(s[i], g[i]);
        }
        
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};