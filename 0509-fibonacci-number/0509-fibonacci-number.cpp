class Solution {
public:
    int solve(  int n , vector<int>&dp  ){
        // base case 
        if( n <=1  ) return n ;
        //step3 
        if( dp[n] != -1){
            return dp[n] ;
        }
        //step 2
        dp[n] = solve( n-1 ,dp) + solve(n-2,dp) ;
        return dp[n] ;
    }
    int fib(int n) {
       //step 1-> create a dp vector 
        vector<int>dp(n+1 ,-1) ; 
       int ans = solve ( n ,dp) ;
       return ans ;
    }
};