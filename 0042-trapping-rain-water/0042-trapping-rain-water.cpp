class Solution {
public:
    //it will find the tallest building on left side of the ith building
    vector<int> findLeftMax (vector<int> &height, int &n ) {
        vector<int> leftMax(n) ;
        leftMax[0] = height[0] ;
        for( int i = 1 ; i < n ; i++ ){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax ;
    }
    // it will find the tallest building on right side of the ith building
    vector<int> findRightMax (vector<int> &height, int &n ) {
        vector<int> rightMax(n) ;
        rightMax[n-1] = height[n-1] ;
        for( int i = n-2 ; i >= 0 ; i-- ){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax ;
    }
    //-----------------
    int trap(vector<int>& height) {
        int n = height.size() ;
        int ans = 0 ;
        // Tallest building on leftside of the ith building
        vector<int> leftMax  = findLeftMax  ( height, n ) ;
        // Tallest building on rightside of the ith building
        vector<int> rightMax = findRightMax ( height, n ) ;
        
        // calculating the water traped on ith building 
        for ( int i = 0 ; i < n ; i++ ){
            int x =  min(leftMax[i] , rightMax[i]) - height[i];
            ans += x ;
        }
        return ans ;
    }
};