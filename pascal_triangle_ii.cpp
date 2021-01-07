// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> resArr(rowIndex+1, 0);
        resArr[0] = 1;
        for(int i=1;i<=rowIndex;i++) {
            int a = resArr[0];
            int b = resArr[1];
            for(int j=1; j<i;j++) {
                resArr[j] = a + b;
                a = b;
                b = resArr[j+1];
            }
            resArr[i] = 1;
        }
        return resArr;
    }
};