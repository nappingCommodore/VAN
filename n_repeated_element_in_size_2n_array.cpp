// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A.size();
        int num = 0;
        int i=0, j=1, k=n-1;
        while(j < n-1 && k >= 0) {
            if(A[i] == A[j]) {
                num = A[i];
                break;
            } else if(A[i] == A[k]) {
                num = A[i];
                break;
            } else if(A[j] == A[k]) {
                num = A[j];
                break;
            }
            i++,j++,k--;
        }
        return num;
    }
};