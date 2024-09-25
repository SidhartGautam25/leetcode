// solution 1. this is the clean code solved using sorting
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        
        int n=intervals.size();
        for(int i=1;i<n;i++){
            // if the present interval intersect with the last interval in ans
            // update the interval in ans with this interval
            if(ans[ans.size()-1][1]>=intervals[i][0]){
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
            // if the current interval is out of the range with the interval in ans
            // then the current one is the new answer's interval    
            }else{
                ans.push_back(intervals[i]);
            }
            
        }
        
        
        
        return ans;
    }
};