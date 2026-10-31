class Solution {
public:
    int m;
    int n;
    int LEFT = 0;
    int UP = 1;
    int MOD = 1e9 + 7;

    int solve(vector<vector<int>>& grid, int i, int j,int cameFrom, vector<vector<array<int, 2>>>& t) {

        if(i >= m || j >= n) return 0; // agr i ya j grid se bahr hai to return 0 
        if(i == m-1 && j == n-1) return 1; // agr i and j last grid me hai to return 1 
        // memoization
        // agr value pahle se hi calculated hai to us value ko return kr do
        if(t[i][j][cameFrom] != -1)
            return t[i][j][cameFrom];

        if(grid[i][j] == 1) { // agr grid ka value 1 hai to
            if(cameFrom == LEFT) { // agr aur present geid me left se aaye hai to
                return t[i][j][cameFrom] = solve(grid, i+1, j, UP, t); // niche jayenge 
            }
            else {    // agr upr se aaye hai to 
                return t[i][j][cameFrom] = solve(grid, i, j+1, LEFT, t); // right side jayenge 
            }
        }

        int totalPathCount = 0;

        totalPathCount = (totalPathCount + solve(grid, i, j+1, LEFT, t)) % MOD;

        totalPathCount = (totalPathCount + solve(grid, i+1, j, UP, t)) % MOD;

        return t[i][j][cameFrom] = totalPathCount;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int, 2>>> t( m, vector<array<int, 2>>(n, {-1, -1}));

        return solve(grid, 0, 0, LEFT, t);
    }
};