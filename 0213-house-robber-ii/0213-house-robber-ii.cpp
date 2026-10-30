class Solution {
public:
    int solve( vector<int> &nums , int start , int end ) {
        int n =  nums.size() ;
       
        //space optimised method after memoisation , tabulation 
       // vector <int> dp (n-1) ;
       int  prev2 = nums[start] ;
       int  prev1 = max(nums[start],nums[start+1]) ;

        for ( int i = start+2 , j = 2  ; i<= end ; i++ , j++ ){
           int curr = max(prev1, prev2+nums[i] ) ;

            prev2 = prev1 ;
            prev1 = curr ;
        }
        return prev1 ;
    }
    
    int rob(vector<int>& nums) {
        int n =  nums.size() ;

        if ( n==1 )  return nums[0] ;
        if ( n==2 )  return max(nums[0] , nums[1]) ;

     return max ( solve( nums , 0 , n-2 ) , solve(nums , 1 , n-1) ) ;
    }
};

///
// Space complexity = O(1)
// Time complexity = O(n)