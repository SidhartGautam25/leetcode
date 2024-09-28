// soltuion 1
// two pass
// to begin with,give every child one candy(first condition)
// now move from left to right from index 1,and in any point you get rating 
// higher than the previous one,increase the candy count to prev child candy+1
// in the same way,now move from right to left and get a situation where current
// child has higher rating but less candy,increase his candy count by one more than 
// the right neighbor
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>copy(ratings.size(),1);
        int n=ratings.size();
        if(n==1){
            return 1;
        }
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1] ){
                copy[i]=copy[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] and copy[i]<=copy[i+1]){
                copy[i]=copy[i+1]+1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            count=count+copy[i];
        }
        return count;
        
    }
};

// solution 2
// one pass and O(1) space
// peak and valley approach





class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
        return candy;
    }
};
// related questions
//     1. check if grid satisfies conditions
//     2. minimum number of operations to satisfy conditions
//     3. minimize maximum value in a grid