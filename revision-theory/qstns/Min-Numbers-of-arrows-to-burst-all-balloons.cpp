// Solution 1 (i have solved using this idea on my revision round)
// The idea is to first sort the array of intervals so that you can think about
// overlapping of balloons more clearly
// now that you have sorted intervals,think about the first balloon
//    you have to burst it and you need an arrow for it,so why not place that 
//    arrow in such a way that it can burst as many balloons as possible.
//    now we have to get that point,how can we get it??
//    so first,we will select the end point of the first balloon,isn't it the 
//    best one to start with?? because,you can get most balloons there.
//    but after that when you move to next balloon,it is guarranteed that its
//    starting point is always greater than or equal to the previous one,but
//    it may be possible that its ending point can be lesser than the previous
//    one.so now we cant select the end of the previous one because with that
//    we can't burst this balloon with that,so we have to update out arrow point
//    to this balloon end point as we can burst prev one and this one also with that
//    then again we move to next and update the end to min of these so that with that
//    arrow we can hit all these balloons and we will do that until it is possible
//    and it is possible until the end is greater equal to the start of the intervals
//    and after that we need another arrow
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count=0;
        int n=points.size();
        sort(points.begin(),points.end());
        int i=0;
        while(i<n){
            int end=points[i][1];
            int j=i+1;
            while(j<n and points[j][0]<=end){
                end=min(end,points[j][1]);
                j++;
            }
            count++;
            i=j;
            
        }
        return count;
    }
};

// Solution 2
// This solution is based on activity selection algorithm
// So what we will do is we now sort the interval array according to its end time
// and not on starting time
// And now pick the first interval,so for this interval we need an arrow
// now move to next interval and if this interval starting point is lesser than
// the ending point of prev one we dont need a new arrow for this interval as
// there must be a common region in these two,so can use the same arrow to burt these
// two.
// now using this same idea we can use the same arrow for all those intervals 
// whose starting point is smaller than the ending point of first interval,so will
// not increase the number of arrow until we have starting point lesser than the first
// interval ending point
// after that we are unable to find interval with above condition,we then again increase
// the number of arrow size and use the above same logic to hit as many balloons as
// possible with this new arrow.


// Solution 3
// This solution is strictly based on activity selection algorithm
// See in activity selection problem,in one way what we really find is ->
// largest number of intervals such that all of them are totally independent to
// each other
// now i am saying that minimum number of arrows needed is equal to largest number of
// totally independent intervals
// Proof :
// we need one arrow for all those intervals as with one same arrow,we cant burst
// two of them,and all others intervals can be shared to any one of them and hence
// can be hit by the same arrow of the interval.