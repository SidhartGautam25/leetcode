// solution 1. In this solution we apply this simple logic
// in given array of intervals,there are three types of intervals
//        1. intervals which do not collapse with the given interval
//        2. intervals which do collapse with the given interval
//        3. intervals which do not collapse like first one but are diffrent
//           in way that there ranges values are greater than the given interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;
        int i=0;
        int s=intervals.size();
        // this loop put the intervals in result which have nothing to do with the
        // given interval to intersect
        while(i<s && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        // this loop updates all those interval who are related to given intervals
        while(i<s && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        // now the updated interval has been pushed to our result
        result.push_back(newInterval);
        // now just like first type of intervals,these 3rd types are also pussed to
        // result with any updates
        while(i<s){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

// Solution 2. Can be solved with binary search
// The thing is you can search the intervals which can be merged with given interval
// and then you can just update them and leave remaining of the intervals as usual
// https://leetcode.com/problems/insert-interval/discuss/21815/Two-Easy-O(n)-C%2B%2B-Solutions-with-Explanations

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size(), leftEnd, rightEnd, l, r;
        vector<Interval> res;
        // Find the rightmost interval with start smaller than that of newInterval
        for (l = 0, r = n - 1; l <= r; ) {
            int mid = l + ((r - l) >> 1);
            if (intervals[mid].start > newInterval.start)
                r = mid - 1;
            else l = mid + 1;
        } 
        leftEnd = r;
        // Find the leftmost interval with end larger than that of newInterval
        for (l = 0, r = n - 1; l <= r; ) {
            int mid = l + ((r - l) >> 1);
            if (intervals[mid].end < newInterval.end)
                l = mid + 1;
            else r = mid - 1;
        }
        rightEnd = l;
        // Merge newInterval with intervals[leftEnd] and intervals[rightEnd] if necessary
        if (leftEnd >= 0 && intervals[leftEnd].end >= newInterval.start)
            newInterval.start = intervals[leftEnd--].start;
        if (rightEnd < n && intervals[rightEnd].start <= newInterval.end)
            newInterval.end = intervals[rightEnd++].end;
        // Save the intervals sequentially
        for (int i = 0; i <= leftEnd; i++)
            res.push_back(intervals[i]);
        res.push_back(newInterval);
        for (int i = rightEnd; i < n; i++)
            res.push_back(intervals[i]);
        return res;
    }
};