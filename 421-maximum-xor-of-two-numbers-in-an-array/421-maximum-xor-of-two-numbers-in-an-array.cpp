class Node{
    Node *links[2];
    public: 
        bool containsKey(int bit){
            return links[bit] != NULL;
        }
        Node* get(int bit){
            return links[bit];
        }
        void put(int bit, Node* node){
            links[bit] = node;
        }
};

class Trie{
    Node* root;
    
    public:
        Trie(){
            root = new Node();
        } 
    
        void insert(int num){
            Node *node = root;
            for(int i = 31; i >= 0; i--){
                int temp = (num >> i) & 1;
                if(!node -> containsKey(temp))
                    node -> put(temp, new Node());
                node = node -> get(temp);
                  
            }
        }
        
        int findMax(int num){
            Node *node = root;
            int max_val = 0;
            for(int i = 31; i >= 0; i--){
                int temp = ((num >> i) & 1) ^ 1;
                if(node -> containsKey(temp)){
                    max_val = max_val | (1 << i);
                    node = node -> get(temp);
                }
                else node = node -> get(temp ^ 1);
            }
            return max_val;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();
        for(int i: nums) 
            trie -> insert(i);
        int res = 0;
        for(int i: nums){
            res = max(res, trie -> findMax(i));
        }
        return res;
    }
};