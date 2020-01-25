class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        
        if (size == 1) {
            return "";
        }
        
        for (int i = 0; i < size / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[size - 1] = 'b';
        
        return palindrome;
    }
};