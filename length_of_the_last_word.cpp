// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }
        int count = 0;
        int i = n-1;
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        for(; i>=0; i--) {
            if(s[i] == ' '){
                break;
            }
            count++;
        }
        return count;
    }
};