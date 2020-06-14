class TreeAncestor {
public:
    int n;
    int lca[50050][22];
    TreeAncestor(int N, vector<int>& A) {
        memset(lca, 0xff, sizeof(lca));
        n = N;
        for(int i = 0;i < n;++i) {
            lca[i][0] = A[i];
        }
        
        for(int j = 1;j < 20;++j) {
            for(int i = 1;i < n;++i) {
                int p = lca[i][j - 1];
                if(p != -1) {
                    lca[i][j] = lca[p][j - 1];
                }
            }
        }

//         for(int i = 0;i < n;++i) {
//             cout << "i: " << i << "\n";
//             for(int j = 0;j < 3;++j) {
//                 cout << lca[i][j] << "  ";
//             }
//             cout << "\n\n";
//         }
        
    }
    
    int getKthAncestor(int node, int k) {
        int st = 19;
        int ans = node;
        while(k) {
            while((1 << st) > k) {
                --st;
            }
            ans = lca[ans][st];
            k -= (1 << st);
            if(ans == -1) {
                return -1;
            }
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */