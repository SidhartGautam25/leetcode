// Solution 1. Using kadane algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
            }
            
        }
        return ans;
        
    }
};

// Solution 2
// Using recursion
// Very ineffective but useful in sense that it will help to get further better 
// solutions and also to understand recursion better
//        -->  At each index i, we can either pick that element or not pick it.
//        -->  If we pick current element, then all future element must also be picked since
//             our array needs to be contiguous.
//        -->  If we had picked any elements till now, we can either end further 
//           recursion at any time by returning sum formed till now or we can choose 
//           current element and recurse further. This denotes two choices of either 
//           choosing the subarray formed from 1st picked element till now or expanding 
//           the subarray by choosing current element respectively.