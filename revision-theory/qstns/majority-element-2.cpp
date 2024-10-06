// solution 1
// here since we have to see elements greater than n/3,and 
// there can be two answers so we maintain two ele
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
int ele1,ele2,cnt1=0,cnt2=0;
// ele1=nums[0];
// ele2=nums[1];
// cnt1++;
// cnt2++;
        vector<int>ans;

for(int i=0;i<nums.size();i++){
    if(nums[i]==ele1){
        cnt1++;

    }else if(nums[i]==ele2){
        cnt2++;

    }else if(cnt1==0){
        ele1=nums[i];
        cnt1++;

    }else if(cnt2==0){
        ele2=nums[i];
        cnt2++;

    }else{
        cnt1--;
        cnt2--;

    }
   
}
         int count=0;
        int n=nums.size();
        // cout<<"ele 1 "<<ele1<<endl;
        // cout<<"count "<<cnt1<<endl;
        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i]){
                count++;
            }
        }
        if(count>(n/3)){
           ans.push_back(ele1);
        }
        count=0;
        if(ele1 != ele2){
             for(int i=0;i<nums.size();i++){
            if(ele2==nums[i]){
                count++;
            }
        }
         if(count>(n/3)){
           ans.push_back(ele2);
        }
            
        }
       
        return ans;
        
        
    }
};