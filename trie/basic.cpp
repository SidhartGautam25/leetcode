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