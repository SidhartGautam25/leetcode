class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() {
        isEnd = false;
        children.resize(26, nullptr);
    }
};
void insert(TrieNode* node,string& word, int i) {
        if (i == word.length()) {
            node->isEnd = true;
            return;
        }

        char c = word[i];
        int idx = c - 'a';

        if (!node->children[idx]) {
            node->children[idx] = new TrieNode();
        }

        insert(node->children[idx], word, i + 1);
}

 bool search(TrieNode* node,string& word, int i) {
        if (i == word.length()) {
            return node->isEnd;
        }

        char c = word[i];

        if (c == '.') {
            for (auto child : node->children) {
                if (child && search(child, word, i + 1)) {
                    return true;
                }
            }

            return false;
        } else {
            int idx = c - 'a';

            if (!node->children[idx]) {
                return false;
            }

            return search(node->children[idx], word, i + 1);
        }
}
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {  
        TrieNode* root;
        root = new TrieNode();
        for(int i=0;i<dictionary.size();i++){
            string s=dictionary[i];
            insert(root,s,0);

        }
        string t="cat";
        if(search(root,t,0)==true){
            cout<<"yes"<<endl;
        }
        //int i=0;
        string ans="";
        vector<string>sen;
        int s=sentence.size();
        int i=0;
        while(i<s){
            int j=i;
            
            while(j<s){
                char c=sentence[j];
                if(c==' '){
                    break;
                }
                j++;
            }
            string temp=sentence.substr(i,j-i);
            sen.push_back(temp);
            j++;
            i=j;
        }
        int n=sen.size();
        // cout<<"sen "<<endl;
        // for(int x=0;x<n;x++){
        //     cout<<sen[x]<<endl;
        // }
        bool ins=false;
        for(i=0;i<n;i++){
            string temp=sen[i];
            int ss=temp.size();
            bool done=false;
            for(int j=0;j<ss;j++){
                string tt=temp.substr(0,j+1);
                if(search(root,tt,0)){
                    done=true;
                    if(ins){
                         ans=ans+" "+temp.substr(0,j+1);
                        //cout<<"added string is "<<temp.substr(0,j+1)<<endl;
                        break;

                    }else{
                        ins=true;
                         ans=ans+temp.substr(0,j+1);
                        //cout<<"added string is "<<temp.substr(0,j+1)<<endl;
                        break;
                    }
                    
                    
                }
            }
            if(done==false){
                if(ins){
                     ans=ans+" "+temp;

                }else{
                    ins=true;
                     ans=ans+temp;
                }
               
            }
           

        }

        return ans;
    }
};