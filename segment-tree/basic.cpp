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

