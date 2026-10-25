class Solution {
public:
    int m , n ;
    // Applying DFS traversal 
    int dfs( vector<vector<int>>&grid, int r, int c ){
        // base case
        // agr ham out of bound gye to return false 
        if( r >= m || c >= n || r < 0 || c < 0  ) return false ;

        if( grid[r][c] == 1 ){//water
            return true ; //closed hai is side se 
        }
        grid[r][c] = 1 ;//mark visited

        //recursion  
        bool left  = dfs(grid, r, c-1) ;
        bool right     = dfs(grid, r, c+1) ;
        bool up     = dfs(grid, r-1, c) ;
        bool bottom = dfs(grid, r+1, c) ;

        return ( right && left && up && bottom ) ; // agr ek side se bhi hame water nhi  milta hai then we are not closed and hence it`s not Island 
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;
        int count  = 0 ; 

        for( int i = 0; i < m ; i++ ){
            for ( int j = 0 ; j < n ; j++ ){
                if(grid[i][j] == 0){// har index par jayenge and check krnege if it is 0 or 1 . If it is 0 means its    land and we have to check wheather land is surrounded by water or not . so call DFS to check ( also can apply BFS)
                    if(dfs(grid , i , j) == true ){// if we are surrounded by water means we have found a Island, so increase count by 1 ;
                        count++ ;
                    }
                }
            }
        }
        return count ;
    }
};