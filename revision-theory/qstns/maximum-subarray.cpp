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

class Solution {
public:
    
    int solve(vector<int>&arr,int i,bool cond){
        int n=arr.size();
        if(i==n){
            if(cond){
                return 0;
            }else{
                // cond being false for i==n means that till now there has been
                // no element in the subarray and so this is not valid and hence
                // returning INT_MIN so that this dont add to be a answer
                return INT_MIN;
            }
        }
        // this is important because this is a subarray problem
        // this cond being true means that prev element has been taken
        // and so you have only two option left for this current element
        // either take it and move forward or dont take this current element
        // and stop
        if(cond){
            return max(0,arr[i]+solve(arr,i+1,true));
        }
        // this piece of code which runs if cond is false is pretty obvious
        // this simply tells you that return max of two ans
        // the one is where this current element is taken(so you have to set cond 
        // to true so that next element can know that you have been taken)
        // first option is in sense the subarray which starts with this current 
        // element
        // now the second option is neglecting the current array
        return max(arr[i]+solve(arr,i+1,true),solve(arr,i+1,false));
    }
    
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,false);
       
        
    }
};


// solution 3
// this solution is just the better version of previous solution as prev sol of
// recursion is doing same calculation multiple times so we will memoize the
// answer for diffrent states

class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        return solve(nums, 0, false, dp);
    }
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
        return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
    }
};

// solution 4
// now we do tabulation or dp inspired from the previous one
// simply converting the recursion code into interation format

// dp[1][i] is the state which store the ans for condition in which current
// element is included
// dp[0][i] is the state which store the ans for condition in which current
// element has not been taken
class Solution {
public:
    long mmax(long a,long b){
        if(a>b){
            return a;
        }
        return b;
    }
    int maxSubArray(vector<int>& nums) {
         vector<vector<long>> dp(nums.size(), vector<long>(2));
        dp[0][0]=INT_MIN;
        dp[0][1]=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            dp[i][0]=mmax(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=mmax(nums[i],dp[i-1][1]+nums[i]);
            
        }
        return mmax(dp[n-1][0],dp[n-1][1]);
      
        
    }
};

// Solution 5
// this uses the tabulation and almost the same as previous one
// the thing is we now try to solve the problem just using a one d array
// so for this,we assume that dp[i] store the ans for subarray ending at i
class Solution {
public:
    long mmax(long a,long b){
        if(a>b){
            return a;
        }
        return b;
    }
    int maxSubArray(vector<int>& nums) {
      vector<int>dp(nums.size());
        int ans=nums[0];
        int n=nums.size();
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=mmax(nums[i],dp[i-1]+nums[i]);
            ans=mmax(ans,dp[i]);
        }
        return ans;
        
    }
};

// Solution 6 Divide and Conquer
//We can solve this using divide and conquer strategy. This is the follow-up question
//  asked in this question. This involves modelling the problem by observing that the
//  maximum subarray sum is such that it lies somewhere -


// entirely in the left-half of array [L, mid-1], OR
// entirely in the right-half of array [mid+1, R], OR
// in array consisting of mid element along with some part of left-half and some part 
// of right-half such that these form contiguous subarray
//  - [L', R'] = [L', mid-1] + [mid] + [mid+1,R'], where L' >= L and R' <= R

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for(int i = mid-1, curSum = 0; i >= L; i--)
            curSum += A[i],
            leftSum=max(leftSum, curSum);
        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for(int i = mid+1, curSum = 0; i <= R; i++)
            curSum += A[i],
            rightSum = max(rightSum, curSum);        
		// return max of 3 cases 
        return max({ maxSubArray(A, L, mid-1), maxSubArray(A, mid+1, R), leftSum + A[mid] + rightSum });
    }	
};

// realated problems
// maximum score of spliced array
// maximum absolute sum of any subarray
// maximum subarray sum after one operation
// substring with largest variance
// count subarray with score less than k
// find the substring with max cost
// k items with the maximum sum
// maximum good subarray sum