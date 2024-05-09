
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int q=queries.size();
        int n=arr.size();
        vector<int>prefix(n);
        prefix[0]=arr[0];
          for(int i=1;i<n;i++){
    prefix[i]=prefix[i-1]^arr[i];
  }
        for(int i=0;i<n;i++){
            cout<<prefix[i]<<" ";
        }
        cout<<endl;
  vector<int>ans(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int a;
              if(l==0){
        a=prefix[r];
    }else{
        a=prefix[r]^prefix[l-1];
    }
  ans[i]=a;

        }
        return ans;

        
    }
};