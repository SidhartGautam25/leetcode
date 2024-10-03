// solution 1
// in this solution,we discuss a unique method (i havent used it previously)
// what we have to do in this qstn is to divide the array into increasing subsequences
// of length greater than or equal to 3
// so for this we will mantain two maps named left and end
// so left is the map which will keep the account of elements which we havent used
// in our subsequence
// and end will keep account abount how many subsequences are ending at that specific
// element
// so for this defination,in beginning left will just keep the frquency count of each
// element

// now in second loop is the place where real things happen
// we will go to each element one by one
// now if left[arr[i]] is 0,it means that element has been used in subsequences
// so we will just move on to next one
// now if it is not zero,we will decrease its frequency in left by 1
// because we are going to use it in our subsequence
// now we have two options --> either we add it to the previous subsequence
// or we can start a new one
// so first we will try to add it in previous one as it will be more helpful for us,
// so for that,we have to check how many subsequence is ending at previous element,
// and reduce it by 1 and now increase the end[arr[i]] by 1
// but if there is subsequence which is ending at previous element,it means you cant be 
// the part of previous subsequence,it means you have to start your own subsequence,
// but the condition is its length should be greater than 3,
// so we will also put two more element in this subsequence --> left[arr[i+1]--
// and left[arr[i+2]]--
// now if these two things are not possible then there is no other option and just 
// return false;
// finally returns true
class Solution {
public:
    bool isPossible(vector<int>& A) {
        unordered_map<int, int> left, end;
        for (int i: A) {
            left[i]++;
        }
        for (int i: A) {
            if (left[i] == 0) continue;
            left[i]--;
            if (end[i - 1] > 0) {   
                end[i - 1]--;
                end[i]++;
            } else if (left[i + 1] > 0 && left[i + 2] > 0) {
                left[i + 1]--;
                left[i + 2]--;
                end[i + 2]++;
            } else {   
                return false;
            }
        }
        return true;
    }
};