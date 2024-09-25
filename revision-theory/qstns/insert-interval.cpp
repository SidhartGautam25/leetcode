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