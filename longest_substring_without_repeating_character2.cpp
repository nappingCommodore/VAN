// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s[0] == ' ') {
            return 1;
        }
        vector<int> countArr(256, -1);
        int i = 0;
        int len = 0, maxLen = 0;
        int left = 0;
        while(s[i] != '\0') {
            if(countArr[s[i]] == -1) {
                countArr[s[i]] = i;
                len++;
            } else {
                int tmpLeft = countArr[s[i]] + 1;
                if(left < tmpLeft) {
                    left = tmpLeft;
                }
                len = i-left+1;
                countArr[s[i]] = i;
            }
            if(maxLen < len) {
                maxLen = len;
            }
            i++;
        }
        return maxLen;
    }
};
