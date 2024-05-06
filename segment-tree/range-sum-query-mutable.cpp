 void buildTree(vector<int>& seg,vector<int>&nums, int pos, int left, int right){
        if (left == right){
            seg[pos] = nums[left]; 
            return;
        }
        int mid = (left+right)/2;
        buildTree(seg,nums, 2*pos+1, left, mid);
        buildTree(seg,nums, 2*pos+2, mid+1, right);
        seg[pos]=seg[2*pos+1]+ seg[2*pos+2];
    }

void updateUtil(vector<int>&seg,int pos,int left,int right,int index,int val){
     if(index <left || index >right) return;
        
        // total overlap
        if(left==right){
            if(left==index)
                seg[pos]=val;
            return;
        }

        // partial overlap
        int mid=(left+right)/2;
        updateUtil(seg,2*pos+1,left,mid,index,val); // left child
        updateUtil(seg,2*pos+2,mid+1,right,index,val); // right child
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}



 int rangeUtil(vector<int>&seg,int qlow, int qhigh, int low, int high, int pos){
        if (qlow <= low && qhigh>= high){ // total overlap
            return seg[pos];
        }
        if (qlow > high || qhigh < low) { // no overlap
            return 0;
        }
        // partial overlap
        int mid = low+(high-low)/2;
        return (rangeUtil(seg,qlow, qhigh, low, mid, 2*pos+1) + rangeUtil(seg,qlow, qhigh, mid+1, high, 2*pos+2));
    }



class NumArray {
public:
    vector<int>seg;
    int n;
    NumArray(vector<int>& nums) {
         if(nums.size() > 0){
            n = nums.size();
            seg.resize(4*n,0);  // Maximum size of a segment tree for an array of size n is 4n
            buildTree(seg,nums, 0, 0, n-1); // Build the segment tree
            // Print Segment Tree
            // for(int i=0;i<4*n;i++)
            //     cout<<seg[i]<<" ";
            // cout<<endl;
        }
        
    }
    
    void update(int index, int val) {
        updateUtil(seg,0,0,n-1, index, val);
        
    }
    
    int sumRange(int left, int right) {
         return rangeUtil(seg,left, right, 0, n-1, 0); 
        
    }
    
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */