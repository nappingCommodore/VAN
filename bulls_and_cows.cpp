// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bull = 0, cow = 0;
        vector<int> countArr(10, 0);

        for(int i=0;i<n;i++) {
            countArr[secret[i] - '0']++;
        }
        
        for(int i=0;i<n;i++) {
            if(secret[i] == guess[i]) {
                bull++;
                countArr[guess[i] - '0']--;
                guess[i] = 'x';
            }
        }
        
        for(int i=0;i<n;i++) {
            if(guess[i] != 'x' && countArr[guess[i] - '0'] > 0) {
                cow++;
                countArr[guess[i] - '0']--;
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};