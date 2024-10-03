// solution 1
// here first we take the xor of whole array
// every element whose frequency is 2 dont contribute,hence if b and c are 
// single elements,xor will be equal to b^c
// now we have to extract b and c from this
// for this,we will find the rsb of this xor 
// at that ith bit,both b and c have diffrent bit.
// now we make two variable,x and y
// x will take xor of all those elements whose ith bit is set
// y will take xor of all those elements whose ith bit is 0
// at last,x will become b or c,and y will become the remaining one 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>result;
        long long total_xor=0;
        for(int i=0;i<nums.size();i++){
            total_xor=total_xor^nums[i];
        }
        //cout<<total_xor<<endl;
        long long rsb=((total_xor)&(-total_xor));
        //cout<<rsb<<endl;
        int x=0;
        int y=0;
        for(int i=0;i<nums.size();i++){
            if((rsb&(nums[i]))==0){
                x=x^nums[i];
            }
            else{
               y=y^nums[i]; 
            }
        }
        if(x<y){
            result.push_back(x);
            result.push_back(y);
        }
        else{
            result.push_back(y);
            result.push_back(x);
        }
        return result;
    }
};