class Node{
    Node *link[26];
    bool flag = false;
    
    public:
        bool isPresent(char ch){
             return (link[ch - 'a'] != NULL);
        }
    
        void put(char ch, Node *node){
            link[ch - 'a'] = node;
        }
        Node* set( char ch){
            return link[ch - 'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch: word){
            if(!(node -> isPresent(ch)))
                node -> put(ch, new Node());
            node = node -> set(ch);
        }
        node -> setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(char ch: word){
            if(!node -> isPresent(ch)) return false;
            node = node -> set(ch);
        }
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(char ch: prefix){
            if(!node -> isPresent(ch)) return false;
            node = node -> set(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */