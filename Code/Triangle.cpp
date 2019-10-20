class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // from bottom to top
        if (triangle.size()==0 || triangle[0].size()==0) return 0;
        if (triangle.size()==1) return triangle[0][0];
        vector<int> tmp = triangle[triangle.size()-1];
        vector<int> result;
        for (int i = triangle.size() - 2; i >= 0; i--) {
            result.clear();
            for (int j = 0; j <= i; j++) {
                // could have only use one vector
                result.push_back(triangle[i][j] + min(tmp[j], tmp[j+1]));
            }
            tmp = result;
        }
        return result[0];
    }
};