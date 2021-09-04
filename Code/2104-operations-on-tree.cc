class LockingTree {
    unordered_map<int, unordered_set<int>> child;
    int par[2000];
    int lockby[2000];
    int n;
    bool checkedChild = false;
public:
    LockingTree(vector<int>& parent) {
        memset(lockby, -1, sizeof(lockby));
        n = parent.size();
        for (int i = 0; i < n; i++) {
            child[parent[i]].insert(i);
            par[i] = parent[i];
        }
    }
    
    bool lock(int num, int user) {
        
        if (lockby[num] != -1) {
            return false;
        } else {
            lockby[num] = user;
            return true;
        }
    }
    
    bool unlock(int num, int user) {
        if (lockby[num] != -1) {
            bool result = false;
            if (lockby[num] == user) {
                result = true;
            }
            if (result) {
                lockby[num] = -1;
            }
            return result;
        } else {
            return false;
        }
    }
    
    bool upgrade(int num, int user) {
        if (lockby[num] == -1) {
            // ancestors
            int tmpNum = num;
            while (tmpNum != -1) {
                if (lockby[tmpNum] != -1) {
                    return false;
                }
                tmpNum = par[tmpNum]; 
            }
            // descendant 
            checkedChild = false;
            check(num);
            if (checkedChild) {
                upgrade(num);
                lockby[num] = user;
            }
            return checkedChild;
        } else {
            return false;
        }
    }
    
    void check(int num) {
        if (checkedChild) {
            return;
        }
        if (lockby[num] != -1) {
            checkedChild = true;
            cout << num << endl;
            return;
        }
        for (auto &c : child[num]) {
            check(c);
            if (checkedChild) {
                return;
            }
        }
    }
    
    void upgrade(int num) {
        lockby[num] = -1;
        for (auto &c : child[num]) {
            upgrade(c);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */