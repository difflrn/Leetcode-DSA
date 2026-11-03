class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort( nums.begin() , nums.end());
        int n = nums.size() ;

        int target = nums[n-1] ;

        int ans = 0 ;

        for( int i = 0 ; i< n ; i++ ){
            ans+= abs(target - nums[i]) ;
        }
        return ans ;
    }
};