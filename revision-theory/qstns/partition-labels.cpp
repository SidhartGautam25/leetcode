// solution 1
// store the end index of every character
// now whenever a charater comes,its end index should be in that partition also
// so end of that partition is updated with elemenets end index every time

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            mp[c]=i;
        }
        int count=1;
        int end=0;
        int prev=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            end=max(end,mp[c]);
            if(end==i){
                ans.push_back(end-prev+1);
                prev=end+1;
            }
            
        }
        return ans;
        
    }
};