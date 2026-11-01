class Solution {
public:
    
    int minMoves(vector<int>& nums) {
        int cnt = 0  ;
        int n = nums.size() ;
        sort(nums.begin(),  nums.end() ) ;
        for( int i = 0 ; i < n ; i++ ){
            cnt += abs(nums[i] - nums[0]) ;
        }
        return cnt ;
    }
};