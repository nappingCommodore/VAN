// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> alphaArr(256, -1);
        int l=0,r=0,maxLen = 0;
        while(r<n) {
            if(alphaArr[s[r]] != -1 && alphaArr[s[r]] >= l) {
                l = alphaArr[s[r]] + 1;
                // cout<<"l = "<<l<<" r= "<<r<<endl;
            }
            alphaArr[s[r]] = r;
            int tmpLen = r-l+1;
            // cout<<"l = "<<l<<" r= "<<r<<endl;
            if(tmpLen > maxLen) {
                maxLen = tmpLen;
            }
            r++;
        }
        return maxLen;
    }
};