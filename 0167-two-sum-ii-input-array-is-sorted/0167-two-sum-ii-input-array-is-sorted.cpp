class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =  nums.size() ;
        int s = 0 ; 
        int e = n -1 ;

        while ( s<e ){
            int sum = nums[s]+nums[e] ;
            if( sum == target){
                return { s+1, e+1} ;
            }
            else if ( sum < target ){
                s++ ;
            }
            else{
                e--;
            }
        }
        return {} ;
    }
};