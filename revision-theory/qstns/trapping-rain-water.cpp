// first solution
// the simple logic is -> at any point i the height of water stored is determined
// by this simple formula -> min(max(arr[0]....,arr[i-1]),max(arr[i+1]...arr[n-1]));
// this logic comes with a very simple observation -> left highest block and right 
// side highest block will be responsible for storing water at that point 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    int ans = 0;
    vector<int> l(n);  // l[i] := max(height[0..i])
    vector<int> r(n);  // r[i] := max(height[i..n))

    for (int i = 0; i < n; ++i)
      l[i] = i == 0 ? height[i] : max(height[i], l[i - 1]);

    for (int i = n - 1; i >= 0; --i)
      r[i] = i == n - 1 ? height[i] : max(height[i], r[i + 1]);

    for (int i = 0; i < n; ++i)
      ans += min(l[i], r[i]) - height[i];

    return ans;
    }
};

// previous logic is taking o(n) space
// now we will try to solve it in O(1) space
// here you can see that we just maintaining l and r to get our answer
// and if we observe carefully we are using almost same concept that
// we used in area of histogram question and for exactly same purpose
// we are eliminating the side which is smaller as it is not responsible 
// for getting our answer
// let say l is 5 and r is 10,then we know that between them,chahe kuch bhi ho 5 height
// tk to paani aayega hi chahe kuch bhi ho jae.to ab l ko bdha denge,aisa islie kuki
// 5 wala block apna input to de hi dia,ab agr r ko move kre or l ko rhne de tobhi 
// 5 se jaida height ka paani nhi store kr sakte,kuki l to 5 hi rhega to agr r ka value 
// move hone ke baad bdha bhi tb bhi 5 height tk hi paani store kr payenge,
// or agar l ko bdhaye to ho ho sakta hai ki l ka height kahi 7 bhi mile,to uske or r 
// 10 ke bich me ab height 7 tk paani bhar sakte hai,or agr l ka height or kam mila,
// maanlo 3 to bhi l ko 5 hi rkhenge kuki wo jaida bd hai or hmko pta hai min 5 tk to store
// krega hi 

// so whenever we have to main two arrays of max for left side and right side,we can 
// use this two pointer concept to do that in O(1) time complexity
class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
        int l=height[0];
        int r=height[n-1];
        int storage=0;
        int i=0;
        int j=n-1;
        int p=i;
        while(i<=j){
            l=max(l,height[i]);
            r=max(r,height[j]);
            int temp=min(l,r)-height[p];
            if(temp>0){
                storage=storage+temp;
            }else{
                storage=storage;
            }
            if(l<r){
                i++;
                p=i;
            }else{
                j--;
                p=j;
            }
        }
        return storage;
        
    }
};