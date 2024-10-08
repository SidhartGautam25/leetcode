// solution 1
// overall if you observe,what we have to do is to decrase the range of the array
// so the simple approach to acheive this is to incraese the smaller element by k
// and decrease the larger element by k
// now we can say there are two parts of the array
// now in which we are adding k
// other is where we are subtracting k
// now it is unknown that until with point we increase and from where we
// need to start decreasing
// so let say we assume till i,we are increasing
// and from i to n-1 we are decreasing
// so smallest element in first part is arr[0]+k
// largest ele in first part is arr[i]+k
// smallest ele in second part is arr[i+1]-k
// largest ele in second part is arr[n-1]-k
// now logically largest number in these four will be max(arr[i]+k,arr[n-1]-k)
// smallest among four will be min(arr[o]+k,arr[i+1]-k)
// so we have to decide this i,so we will move from i=0 to i=n-2
// and get the best among them
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int smallest=nums[0]+k;
        int largest=nums[nums.size()-1]-k;
        int ans=nums[nums.size()-1]-nums[0];
        
        for(int i=0;i<nums.size()-1;i++){
            int mini=min(smallest,nums[i+1]-k);
            int maxi=max(largest,nums[i]+k);
            ans=min(ans,maxi-mini);
        }
        
        return ans;
        
    }
};