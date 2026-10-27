class Solution {
public:
    int solve(int n , vector<int>&dp ){
        if( n == 1 ) return 1 ;
        if( n == 2 ) return 2 ;
        // step 3 
        if( dp[n]!=-1){
            return dp[n]  ;
        }
        // step 2 
        dp[n] =solve(n-1 ,dp) + solve(n-2 ,dp) ;
        return dp[n] ;  
    }
    int climbStairs(int n) {
        //step 1 
        vector<int> dp( n+1 , -1) ;
       int ans = solve(n ,dp) ;
       return ans ;
    }
};