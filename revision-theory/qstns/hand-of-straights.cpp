//solution 1
// very simple approach,first we store every number frequency
// then what we need to do is pick the smallest number
// then reduce its frequency count from every next k elements
// if not possible,return false
// then if things gone right, return true
class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int k) {
         map<int,int>mp;
        int groupSize=k;
        int n=hand.size();
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        if(n%groupSize != 0){
            //cout<<"he"<<endl;
            return false;
        }
        for(auto it:mp){
            if(it.second>0){
                for(int i=1;i<groupSize;i++){
                    if(mp.find(it.first+i) != mp.end()){
                        if(mp[it.first+i]<=0){
                            cout<<"yha"<<endl;
                            return false;
                        }
                        mp[it.first+i]=mp[it.first+i]-it.second;
                        if(mp[it.first+i]<0){
                            return false;
                        }
                    }else{
                        cout<<"ooo"<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};