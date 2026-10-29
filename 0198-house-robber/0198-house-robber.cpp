class Solution {
public:
    int rob(vector<int>& nums) {
        int n =  nums.size() ;

        if ( n==1)  return nums[0] ;
        // intitialize a  DP vector of size n 
        vector<int> dp(n) ;  
        
        // intitialize base condition
        int prev2 = nums[0] ;
        int prev1 = max( nums[0] , nums[1]) ;
        
        //calculate for each house 
        for ( int i = 2 ; i < n ; i++ ){
            int curr = max ( prev1 , prev2 + nums[i]) ;

            prev2 =  prev1 ;
            prev1 = curr ;
        }
        // maximum amount  will be at the n-1 index 
        return prev1 ;
    }
};

// Optimised space complexity 
//  space complexity = O(n) 
// time complexity = O(N) ;
