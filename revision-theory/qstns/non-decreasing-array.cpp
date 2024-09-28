// solution 1
// first thing is we can modify only one element
// so when we get the condition nums[i]< nums[i-1],we need to modify
// during modification,we can do two things
//    either increase the nums[i] so that it can become more or equal to nums[i-1]
//    so that array can become increasing
//    now second thing we can do is to decrease the nums[i-1] element so that
//    it can become smaller than the nums[i] so that the array becomes increasing
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                count++;
                if(count>1){
                    return false;
                }
                // agr last element ho to kuch nhi krenge
                // yha tk aa gye iska mtlb sb sahi hai sirf last elemet gadbad hai
                // to isko aise bhi hmlog koi bhi bda value de sakte hai sahi krne
                // ke lie
                if(i+1==n){
                    continue;
                }
                // ab modification me sbse pahle hmlog current element
                // ko bdhane ka sochenge
                // to maximum hmlog isko nums[i+1] ka value de sakte hai
                // usse bda dene pe fir agla element hi chota ho jayega isse
                // to array increasing nhi rhega
                if(i+1<n && nums[i+1]>=nums[i-1]){
                    nums[i]=nums[i+1];
                }else{
                    // agr usko bda nhi kr paye to ab hmlog nums[i-1] ko
                    // chota krne pe focus krenge
                    // jis trah se nums[i] ko nums[i+1] se bda nhi kr sakte
                    // usi trah nums[i-1] ko nums[i-2] se chota nhi kr skate
                    // nhi to array increasing nhi rah jayega
                    // agr utna chota krne ke baad bhi nums[i] bda nhi hua to
                    // false return kr denge
                   if(i-2>=0){
                       nums[i-1]=nums[i-2];
                       if(nums[i]<nums[i-1]){
                           return false;
                       }
                   }else{
                    // agr i-2 element exist hi nhi krta iska mtlb ye nums[i]
                    // second element hi hai to yha hmlog bahut aaram se
                    // nums[i-1] ko nums[i] ke barabar kr skate hai jisse
                    // array incraesing ho jayega bina i-2 ka tnsn lie
                       nums[i-1]=nums[i];
                   }
                }
            }
        }
        return true;
    }
};