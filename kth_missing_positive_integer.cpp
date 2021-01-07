// https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int last_element = arr[n-1];
        int result = 0;
        
        vector<int> flagArr(100007, 0);
        int count = 0;
        for(int i=0;i<n;i++) {
            flagArr[arr[i]] = 1;
        }
        int i = 1;
        while(count < k && i < 100007) {
            if(flagArr[i] != 1) {
                count++;
            }
            i++;
            // if(count == k){
            //     result = i;
            //     break;
            // }
        }
        return i-1;
    }
};