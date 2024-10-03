// solution 1
// check every bit of num elements and incraese the count 
// if after all count ,at any index the count of bit is not divisible by 3,
// thats mean this is the bit of that single element
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<32;i++){
            int bit=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)){
                    bit++;
                }
            }
            //cout<<"bit count on i "<<i<<" "<<bit<<endl;
            if(bit%3==1){
                //cout<<i<<" th bit of answer is set"<<endl;
                //cout<<"num is "<<(1<<i)<<endl;
                sum=sum|(1<<i);
                
            }
            
        }
        return sum;
        
    }
};

// solution 2
// this is bit diffrent
