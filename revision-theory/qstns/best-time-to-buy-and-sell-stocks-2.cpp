//solution 1
// here we have two variables- lastbuy and 

// lastBuy --> this variable represents the amount which we have with us 
// after our last buy

// lastSold --> this variable represents the amount which we have with us 
// after our last stock's sold

// now initial value of lastsold is 0 as we have assumed that till the first element 
// we have not sold anything

// for initial value of lastBuy our initial value is -prices[0] as when we buy it 
// amount with which we are left with is -prices[0]. we have taken it because for size 1,it is the best
// buy as we have no other better option.

// now,we start our loop with index 1,as for 0 we have solved it with our initial definations,
// now,on every index,we have three options - buy it,sell it or do nothing

// now when we will buy the current option,so we can only buy it when it is better option
// than the lastbuy,so if we buy the current stock,amount with which we are left with is
// lastsold-prices[i] , so now we have two amounts --> lastbuy -> amount with which we 
// are left if we buy the last stock,and lastsold-prices[i]-> amount left when we buy the
// current stock,in this two amount,we will select the greater one as that will be 
// beneficial for us and we saved it in cb variable with represents currentBuy

// now same thing happens for lastsold,if we sold the current stock, we are left with
// lastBuy+prices[i], and if we dont sell it,we are left with lastsold amount,so
// whichever is greater one,we will select that

// now cb will become the lastbuy and cs will become the lastsold


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lastBuy=-prices[0];
        int lastSold=0;
        int n=prices.size();    
        for(int i=1;i<n;i++){
            int cb=max(lastBuy,lastSold-prices[i]);
            int cs=max(lastSold,lastBuy+prices[i]);
            
            lastBuy=cb;
            lastSold=cs;
            
        }
        
        return lastSold;
        
    }
};