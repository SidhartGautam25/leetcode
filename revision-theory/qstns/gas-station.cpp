// solution 1
// start with a random station,let say 0
// at any index i,if total gas becomes negative,this means now we cant move forward,
// means we cant go from i to i+1
// now if this happens i state 
// no station between start and i can become the new start and from no where between 
// them you can reach i+1,so there is no point to make them the new start
// why ??
// at any index between i and start, you reach with some positive gas,only then
// you have moved forward,now if you make them the new start,you start with 0 extra
// gas,means less than the previous condition,hence you will will have less
// gas at i than previous condition,hence you cant move forward
// so to deal with it,make the i+1 the new start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int curr_gas = 0, total_gas = 0;
        for(int i = 0; i < n; i++)
        {
            curr_gas += gas[i]-cost[i];
            total_gas += gas[i]-cost[i];
            if(curr_gas < 0)
            {
                start = i+1;
                curr_gas = 0;
            }
        }
        if(total_gas >= 0) return start;
        else return -1;
        
    }
};


