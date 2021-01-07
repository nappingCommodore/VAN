// https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount = 0;
        bool isInternal = 0;
        for(int i=0;i<word.length();i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                if(i != 0) {
                    isInternal = 1;
                }
                capCount++;
            }
        }
        if(capCount == word.length() || capCount == 0 || (capCount == 1 && isInternal == 0)) {
            return true;
        }
        return false;
    }
};