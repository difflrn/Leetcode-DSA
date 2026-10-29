class Solution {
public:
    int solve( vector<int> &nums , int start , int end ) {
        int n =  nums.size() ;
       
        vector <int> dp (n-1) ;
        dp[0] = nums[start] ;
        dp[1] = max(nums[start],nums[start+1]) ;

        for ( int i = start+2 , j = 2  ; i<= end ; i++ , j++ ){
            dp[j]= max(dp[j-1], dp[j-2]+nums[i] ) ;
        }
        return dp[n-2] ;
    }
    
    int rob(vector<int>& nums) {
        int n =  nums.size() ;

        if ( n==1 )  return nums[0] ;
        if ( n==2 )  return max(nums[0] , nums[1]) ;

     return max ( solve( nums , 0 , n-2 ) , solve(nums , 1 , n-1) ) ;
    }
};