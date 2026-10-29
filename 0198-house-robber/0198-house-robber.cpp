class Solution {
public:
    int rob(vector<int>& nums) {
        int n =  nums.size() ;

        if ( n==1)  return nums[0] ;
        // intitialize a  DP vector of size n 
        vector<int> dp(n) ;  
        
        // intitialize base condition
        dp[0] = nums[0] ;
        dp[1] = max( nums[0] , nums[1]) ;
        
        //calculate for each house 
        for ( int i = 2 ; i < n ; i++ ){
            dp[i] = max ( dp[i-1] , dp[i-2] + nums[i]) ;
        }
        // maximum amount  will be at the n-1 index 
        return dp[n-1] ;
    }
};