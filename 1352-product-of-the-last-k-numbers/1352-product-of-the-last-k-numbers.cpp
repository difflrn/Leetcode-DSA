class ProductOfNumbers {
public:
    vector<int>nums ;
    int n ; 
    
    // constructor...
    ProductOfNumbers() {
       nums.clear() ;
       n = 0 ;  
    }
    
    // function 1 
    void add(int num) {
       if( num == 0 ) {
        nums = {} ;
        n = 0 ;
       } 
       else{
        if ( nums.empty() ){
            nums.push_back(num) ;
        }
        else{// nums me push kr lo and last vale se multiply ke lo so that till current index tk ka mil jaye product
            nums.push_back(nums[n-1] * num) ;
        }
        // nums ka size bdha do +1 se ...
        n++ ;

       }
    }
    
    // function 2 ....
    int getProduct(int k) {
        // k hai size jo sub-array ka size bta rha hia to calculate the product of k elements...
        // so if k > n  then its not possible to calculate the product 
        if( k > n ){
            return 0 ;
        }

        else if( k == n ) {
            return nums[n-1] ;
        }
        // last element uthao and n- k elements ko hta do by dividing the last element 
        return nums[n-1] / nums[n-k-1] ;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */