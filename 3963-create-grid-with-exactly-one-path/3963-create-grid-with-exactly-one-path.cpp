class Solution {
public:
    vector<string> createGrid(int m, int n) {
        //sare grids ko # se bhar do 
        vector<string> grid(m,string(n,'#')) ;

        // first row ko . bna do 
        for ( int i = 0 ; i< n ; i++ ){
            grid[0][i] = '.' ;
        }
        
        // last column ko . bna do 
        for ( int i = 0 ; i< m ; i++ ){
            grid[i][n-1] = '.' ;
        }

        return grid;
    }
};