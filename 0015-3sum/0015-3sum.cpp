class Solution {
public:
    vector<vector<int>> result;

    int twoSum ( vector<int> &nums , int target , int i , int j ){
        // two pointer appraoch se 2 sun find krenge jo sub array bacha hai
        while ( i<j ){
            int sum = nums[i]+nums[j] ;
            if( sum > target ){
                j--;
            }
            else if (sum < target){
                i++;
            }
            else{// sum == target 
              // agr lower side duplicate hai sub-array me to use remove krenge 
               while ( i < j && nums[i] ==  nums[i+1]) i++ ;
              // agr higher side duplicate hai sun-array me to use remove krenge
               while ( i < j && nums[j] ==  nums[j-1]) j-- ;
               // jo ans mila hame usko result me push krenge
               result.push_back({-target, nums[i], nums[j]}) ;
               // fir next other sum ko find krne ke  liye i++ and j-- kr denge 
               i++;
               j--;
            }
        }
        // agr ans nhi mila to epmty return kr denge 
        return{} ;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =  nums.size() ;
        //agr nums me  3 se kam element hai to not possible sum find krna , return {}
        if ( n < 3 ) return {};
        result.clear() ;// jo kuch v tha yha tak result me clear kr do 
       
        // given nums ko sort kr liya 
        sort(nums.begin() , nums.end() ) ;
        // duplicate jo eleminate kr do
        for ( int i = 0 ; i < n ; i++ ){
            if( i>0 && nums[i]== nums[i-1]){
                continue ;
            }
            // ek element ko fix ke do baki 2 ke liye 2 sum function find kr lega 
            int n1 = nums[i] ;
            int target = -n1 ;
            // function call
            twoSum ( nums, target , i+1 , n-1 ) ;
        }  
        
      return result ;
    }
};