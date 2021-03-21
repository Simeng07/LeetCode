class Solution {
    struct TrieNode {
        TrieNode* child[2];
        int count;
        TrieNode() {
            count = 0;
            // why must these 2 lines?
            // Member access within misaligned address
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };
    
    void insert(TrieNode *root, int num) {
        for (int i = 15; i >= 0; i--) {
            int digit = (num >> i) & 1;
            if (!root->child[digit]) {
                root->child[digit] = new TrieNode();
            }
            (root->child[digit]->count)++;
            root = root->child[digit];
        }
    }
    
    int count(TrieNode *root, int num, int top) {
        int result = 0;
        for (int i = 15; i >= 0; i--) {
            int self = (num >> i) & 1;
            int toCompare = (top >> i) & 1;
            if (toCompare == 1) {
                // self ^ node could be 0 or 1
                if (root->child[self]) {
                    // add the node equal to self (thus self ^ node is 0)
                    result += root->child[self]->count;
                }
                root = root->child[1 - self];
            } else {
                // self ^ node must be 0
                // thus node must equal to self
                root = root->child[self];
            }
            if (!root) {
                break;
            }
        }
        return result;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        TrieNode *root = new TrieNode();
        int result = 0;
        for (auto num : nums) {
            result += count(root, num, high + 1) - count(root, num, low);
            insert(root, num);
        }
        return result;
    }
};