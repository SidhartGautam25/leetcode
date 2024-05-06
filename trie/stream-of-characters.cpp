//Trie Solution
//time limit exceded


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

// bool search(TrieNode* root,string word){
//     int n=word.size();
//     TrieNode* curr=root;
//     for(int i=0;i<n;i++){
//         char c=word[i];
//         int ind=c-'a';
//         if(curr->children[ind]==NULL){
//             return false;
//         }
//         curr=curr->children[ind];
//         if(curr->isEnd==true){
//             return true;
//         }
//     }
//     return false;
// }

// class StreamChecker {
// public:
//     TrieNode* root;
//     string curr="";
//     StreamChecker(vector<string>& words) {
//         root=new TrieNode();
//         for(int i=0;i<words.size();i++){
//             string word=words[i];
//             reverse(word.begin(),word.end());
//             add(root,word);
//         }

        
//     }
    
//     bool query(char letter) {
//         curr=letter+curr;
//         if(search(root,curr)){
//             return true;
//         }
//         return false;
       


        
//     }
// };

// /**
//  * Your StreamChecker object will be instantiated and called as such:
//  * StreamChecker* obj = new StreamChecker(words);
//  * bool param_1 = obj->query(letter);
//  */


// Accepted Solution

class StreamChecker {
public:

    string str="";

    StreamChecker(vector<string>& words) {
        
    }
    
    bool query(char letter) {
        str=str+letter;
        
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

