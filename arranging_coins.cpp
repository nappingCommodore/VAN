// https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    long arrangeCoins(long n) {
        long res = sqrt(1+8*n);
        res = res - 1;
        res = res/2;
        return res;
    }
};