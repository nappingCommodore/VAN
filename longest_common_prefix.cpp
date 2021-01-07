// https://leetcode.com/problems/longest-common-prefix/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) {
            return "";
        }
        string prefix = strs[0];
        int prefixLength = prefix.length();
        
        for(int i=1;i<n;i++) {
            if(strs[i].length() < prefixLength) {
                prefixLength = strs[i].length();
                string tmp = strs[i];
                strs[i] = prefix;
                prefix = tmp;
                
            }
            
            for(int j=0;j<prefixLength;j++) {
                if(strs[i][j] != prefix[j]) {
                    prefixLength = j;
                    prefix = prefix.substr(0, j);
                    break;
                }
            }
            
        }
        
        if(prefixLength <= 0) {
            return "";
        }
        
        return prefix.substr(0, prefixLength);
    }
};