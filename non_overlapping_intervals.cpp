// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length <= 1) {
            return 0;
        }
        Arrays.sort(intervals, Comparator.comparingInt(o -> o[1]));
        int count = 0;
        int prev[] = intervals[0];
        for(int[] arr: intervals) {
            if(arr[0] < prev[1]) {
                count++;
            } else {
                prev = arr;
            }
        }
        return --count;
    }
}