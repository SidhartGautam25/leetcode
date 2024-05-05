class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() {
        isEnd = false;
        children.resize(26, nullptr);
    }
};

// iterative version of insert function
void add(TrieNode* node,string& word){
    TrieNode* curr=node;
    for(int i=0;i<word.size();i++){
        int ind=word[i]-'a';
        if(curr->children[ind]==NULL){
            curr->children[ind]=new TrieNode();
        }
        curr=curr->children[ind];
    }
    curr->isEnd=true;
}

bool search(TrieNode* root,string& word){
    int n=word.size();
    TrieNode* curr=root;
    for(int i=0;i<n;i++){
        char c=word[i];
        int ind=c-'a';
         curr=curr->children[ind];
        //cout<<"word is "<<word<<" amd c is "<<c<<" and is end is "<<curr->isEnd<<endl;
        if(curr->isEnd==false){
            return false;
        }
       

    }
    return true;
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        int n=words.size();
        for(int i=0;i<n;i++){
            add(root,words[i]);
        }
        bool found=false;
        string ans="";
        for(int i=0;i<n;i++){
            string word=words[i];
            if(search(root,word)){
               
                    if(word.size()>ans.size()){
                        ans=word;
                    }else if(word.size()==ans.size()){
                        ans=min(ans,word);
                    }
                

            }
        }
        return ans;
        
    }
};