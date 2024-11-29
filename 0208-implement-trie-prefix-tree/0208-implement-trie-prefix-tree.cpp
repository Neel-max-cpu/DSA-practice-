struct Node {
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }

    Node *get(char ch){
       return links[ch-'a']; 
    }

    void setEnd(){
        flag = true;
    }

    void unsetEnd() {
        flag = false;
    }

    bool isEnd(){
        return flag;
    }

    bool remove(Node* node, string word, int depth) {
        // Base case: if we've processed all characters of the word
        if (depth == word.length()) {
            // If it's the end of the word, unset the flag
            if (node->isEnd()) {
                node->unsetEnd();   // to false
            }
            // If the node has no children, it can be deleted
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr) return false; // Node is still required
            }
            return true; // Node can be deleted
        }

        // Recursive case: move to the next character
        char ch = word[depth];
        Node* nextNode = node->get(ch);

        if (nextNode == nullptr) return false; // Word not found in Trie

        bool shouldDeleteCurrentNode = remove(nextNode, word, depth + 1);

        // If the child node can be deleted, unset its link
        if (shouldDeleteCurrentNode) {
            node->put(ch, nullptr);

            // Check if the current node can also be deleted
            if (!node->isEnd()) {
                for (int i = 0; i < 26; i++) {
                    if (node->links[i] != nullptr) return false; // Node still has children
                }
                return true; // Node can be deleted
            }
        }

        return false; // Node cannot be deleted
    }
};

class Trie {
private:
    Node *root;
public:

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                // doesn't contain so create one, 
                // eg apple , pass, a and a new empty node
                node->put(word[i], new Node());
            }
            // move to the reference trie
            node = node->get(word[i]);
        }
        // last reference node
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }   
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }


    // extra delete
    void deleteWord(string s){
        Node *node = root;
        node->remove(node, s, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */