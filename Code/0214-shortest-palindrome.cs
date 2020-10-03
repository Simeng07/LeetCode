public class Solution {
    // Rolling Hash
    public string ShortestPalindrome(string s) {
        // equals to: find the longest palindrome string from the left most part
        if (s.Length <= 1)
            return s;
        
        int tail = 0;
        long hash1 = 0, hash2 = 0;
        long primeBase = 31, poweredBase = primeBase;
        long mod = 1000000007;
        
        for (int i = 0; i < s.Length; i++)
        {
            hash1 = (hash1 * primeBase + (s[i] - 'a') * primeBase) % mod;
            hash2 = (hash2 + (s[i] - 'a') * poweredBase) % mod;
            
            poweredBase = (poweredBase * primeBase) % mod;
            
            if (hash1 == hash2)
            {
                tail = i;
            }
        }
        
        if (tail == s.Length - 1)
            return s;

        string suffix = s.Substring(tail + 1);
        string prefix = new string(suffix.Reverse().ToArray());
        
        return prefix + s;
        
    }
}