// solution 1 
// this is based on the logic that
// two cases are possible ->
// first the max subarray is in between the array,means that first and last
// element is not included in our answer subarray
// in this case you can find the answer just like max subarray
// in second case,where in answer,first and last element are included
// you can get your answer by this logic = total-minSumSubArray
// so in last you just have to return max(maxsubarraySum,total-minSubarraySum)
// the edge case is when every element in the array become negative
// in this case total-minSubarray sum becomes 0,as both have equal value and maxSum
// is equal to the min element,and hence answer become 0 which means empty array,
// but it cant be the answer,so in this case you will return maxSum
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=nums[0];
        int minSum=nums[0];
        int total=nums[0];
        int currMax=nums[0];
        int currMin=nums[0];
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            currMax=max(nums[i]+currMax,nums[i]);
            currMin=min(nums[i],currMin+nums[i]);
            maxSum=max(maxSum,currMax);
            minSum=min(minSum,currMin);
            total=total+nums[i];  
        }
       
        if(maxSum>0){
            return max(maxSum,total-minSum);
        }
        return maxSum;
        
    }
};


// solution 2
// In this technique we will do a very intutive thing which you can use
// to solve other circular problems
// And the idea is,now we will consider the array a1,a2,a3,.....,an as
// a1,a2,a3,....,an,a1,a2,......,an
// In this newly formed array any subarray of size less than equal to n
// is valid as greater than n will take same element twice which is not
// valid

// in heap,we are storing sum at every stage, so if till i,sum of array is sumi
// we will store heap.push({sumi,i});
// now at every stage,heap will have the min sum pair on top,now if that 
// top sum is behind the current index more than n distance,then that should be
// be popped and hence the while loop
// now after all this we have to update our answer also
// for this,we have two thing,ans should only change when sum till now-(min sum subarray)
// this make the answer greater hence update it.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
      
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, -1}); // (preSum, index)
        
        int preSumSoFar = 0;
        int ans = nums[0]; // Start with the first element as the initial answer
        
        for (int i = 0; i < 2 * n; i++) {
            preSumSoFar += nums[i % n];  // Circular array access
            
            // Remove elements that are out of range greater than `n`
            while (!minHeap.empty() && i - minHeap.top().second > n) {
                minHeap.pop();
            }
            
            // Calculate the subarray sum using preSum
            int preSumPrevious = minHeap.top().first;
            ans = max(ans, preSumSoFar - preSumPrevious);
            
            // Push the current preSum and index into the minHeap
            minHeap.push({preSumSoFar, i});
        }
        
        return ans;
      
        
    }
};





// related problems
// maximum array hopping score 2
// number of ways to wear diffrent hat to each other 
// maximum equal frequency
// frequency of the most frequent element
// parallel courses 3
// 