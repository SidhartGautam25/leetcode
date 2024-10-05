// solution 1
// Boyer–Moore majority vote algorithm 
// here we first select the first element as our majority element
// then every time we get that element we increase the cnt by 1
// and when we get a element other than that we decrease the cnt by 1
// now when we have cnt equal to 0,then that means that at that time,
// our ele is not the one which is in majority,so we change the ele by the 
// other element and repeat the same thing
// lastly,after the interation is over,and if cnt is greater than 0
// then our ele can be our majority elemenet,but since 
// it is given that there is a majority element,so it will be our answer

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                ele=nums[i];
                cnt++;
            }else{
                if(nums[i]==ele){
                    cnt++;
                }else{
                    cnt--;
                }
            }
            
        }
        return ele;
        
    }
};