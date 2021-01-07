// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLength = 0;
        string resStr = "";
        
        for(int i=0;i<n;i++) {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r] ) {
                l--;
                r++;
            }
            
            if(maxLength < (r-l-1)) {
                resStr = s.substr(l+1, r-l-1);
                maxLength = (r-l-1);
            }
            
            l = i, r = i+1;
            
            while(l >= 0 && r < n && s[l] == s[r] ) {
                l--;
                r++;
            }
            
            if(maxLength < (r-l-1)) {
                resStr = s.substr(l+1, r-l-1);
                maxLength = (r-l-1);
            }
        }
        
        
        return resStr;
    }
};