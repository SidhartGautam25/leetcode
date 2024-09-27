// All three solution of min number of arrow is applicable to this problem and with 
// exactly same code and logic

// Solution 4:
// Can be solved by dp using the same idea which we use in LIS(longest increasing subseq)
// the logic is,we maintain a table which indicates the largest possible chain possible
// ending at that interval.
// At every index,we traverse the all previous intervals,and take the highest answer from
// those indexes at which we can chain this current interval and store that max+1 for this
// interval.Like this we will do till last and then return that value.