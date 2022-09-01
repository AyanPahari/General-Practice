class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        for(int i=0;i<col;i++){
            for(int j=1;j<row;j++){
                if(mat[j][i] != 0 && mat[j - 1][i] != 0) mat[j][i] += mat[j - 1][i];
            }
        }
        int rt=0;
        int res=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++) {
                if (mat[i][j] >0) {
                    rt=mat[i][j];
                    for (int r = j + 1; r < mat[0].size(); r++) {
                        if (mat[i][r] > 0) {
                            rt = min(mat[i][r],rt);
                             mat[i][j]+=rt;
                        } 
                        else break;
                    }
                }
                 res+=mat[i][j];
            }
        }
        return res;
    }
};