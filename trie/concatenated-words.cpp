
//Trie Solution


// class TrieNode {
// public:
//     bool isEnd;
//     vector<TrieNode*> children;

//     TrieNode() {
//         isEnd = false;
//         children.resize(26, nullptr);
//     }
// };

// void add(TrieNode* node,string& word){
//     TrieNode* curr=node;
//     for(int i=0;i<word.size();i++){
//         int ind=word[i]-'a';
//         if(curr->children[ind]==NULL){
//             curr->children[ind]=new TrieNode();
//         }
//         curr=curr->children[ind];
//     }
//     curr->isEnd=true;
// }

// bool dfs(TrieNode* root,string& word,int ind,int count){
//     if(ind>=word.size()){
//         if(count>1){
//             return true;
//         }
//         return false;
//     }
//     TrieNode* curr=root;
//     for(int i=ind;i<word.size();i++){
//         int c=word[i]-'a';
//         if(curr->children[c]==NULL){
//             return false;
//         }
//         curr=curr->children[c];
//         if(curr->isEnd==true){
//             if(dfs(root,word,i+1,count+1)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// class Solution {
// public:
//     vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//         TrieNode* root = new TrieNode();
//         int n=words.size();
//         for(int i=0;i<n;i++){
//             add(root,words[i]);
//         }
//         vector<string>ans;
//         for(int i=0;i<n;i++){
//             if(dfs(root,words[i],0,0)){
//                 ans.push_back(words[i]);
//             }

//         }
//         return ans;

        
//     }
// };

// fast solution 

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> ms;
        for (string word : words) ms.insert(word);
        vector<string> ans;
    
        for (string word : words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && ms.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};