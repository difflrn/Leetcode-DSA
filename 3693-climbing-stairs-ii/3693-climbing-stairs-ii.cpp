class Solution {
public:
// tabulation method 
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp (n+1 , 0) ; // intitialise dp vector 

        for ( int i = n-1 ; i >= 0 ; i-- ){
            int cost = INT_MAX ;

            int j = i+1 ;
            if( j <= n ) // jump +1 
                cost = dp[j] + costs[j-1] + (j-i)*(j-i) ;
            j = i+2 ;
            if( j <= n ){  // jump +2 
                cost = min(cost,dp[j]+costs[j-1] + (j-i)*(j-i)) ;
            }
            j = i +3 ;
            if( j<= n ) {   // jump +3
                cost = min(cost,dp[j]+costs[j-1] + (j-i)*(j-i)) ;

            }
            dp[i] = cost ;
        }
        return dp[0] ;
    }
};