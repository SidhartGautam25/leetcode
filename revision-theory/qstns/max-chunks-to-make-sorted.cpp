// soltuion 1
// like partition,whenever the maxvalue becomes equal to i,we increase our 
// chunk value
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
         int maxChunk = 0;
        int maxValue = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxValue = max(maxValue, arr[i]);

            if (i == maxValue) {
                maxChunk++;
            }
        }

        return maxChunk;
        
    }
};

// solution 2
// using stack
// here what we are doing is that we pushing our elements in stack if it is greater
// than the top element of our stack
// now if we get a element which is smaller than the top element of our stack
// then it means that this element chunks should be before all those whose value is
// greater than that,so we pop until it becomes the largest one

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int num : arr) {
            if(! st.empty() && num < st.top()){
                int top = st.top();
                while (!st.empty() && num < st.top()) {
                    st.pop();
                }
                st.push(top);
            }
            else{
                st.push(num);
            }
        }
        return st.size();
    }
};