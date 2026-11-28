class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans ;
        map<int, bool > mp ;
        for ( int i = 0 ; i < nums.size() ; i++ ){
            if( mp[nums[i]] == true ){
               ans.push_back(nums[i]) ;
            }
             mp[nums[i]] = true ;
        }
        return ans ;
    }
};