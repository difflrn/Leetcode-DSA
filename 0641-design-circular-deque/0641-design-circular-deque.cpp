class MyCircularDeque {
    vector<int> arr;
    int size ; // capacity of the queue ,means maximum kitne elements ko queue sotre kr skta hai
    int front ;
    int rear;
    int count ; // it will count current me kitne element present hai queue me 

public:

    MyCircularDeque(int k) {
        size = k ;
        arr.resize(size);
        front = rear = -1 ;
        count = 0 ;

    }
    
    bool insertFront(int value) {
        if(isFull()){  // agr queue FULL hai to NO insertion , and return false
            return false ;
        }      
        if(isEmpty()){  // agr queue empty hai to front and rear both were =  -1 , then set it to front = rear = 0, means 1st index that is 0
            front = rear = 0 ;
        }
        else{ //more than 1 elements are present 
            front =  ( front - 1 + size ) % size ; // size add kiya hai taaki front = 0 hone par index -1 na ho, aur % size se index circularly last index par rotate ho jaye.
        }

        arr[front] = value ; // now you have got the position to insert the newer element
        count++ ;  // 1 element is added then increase count by 1
        return true ;
    }
    
    bool insertLast(int value) {
        if( isFull()){ // agr queue FULL hai to NO insertion , and return false
            return false ;
        }
        if( isEmpty()){ // agr queue empty hai to front and rear both were =  -1 , then set it to front = rear = 0, means 1st index that is 0
            front = rear  = 0 ;
        }
        else {
            rear = (rear+1  )%size ;// size add isliye nhi kiya kyuki rear never will be 0 coz it`s always increasing ,  aur % size se index circularly last index par rotate ho jaye.
        }

        arr[rear] = value ; // now you have got the position to insert the newer element at last 
        count++ ;  // 1 element is added then increase count by 1
        return true ;
    }
    
    bool deleteFront() {
        if( isEmpty()){ // queue empty hai , so return false 
            return false ;
        }
        if( front == rear ){ // queue me ek hi element hai and it`s index is 0 , and after deleting the element the index will be -1
            front = rear = -1 ;
        }
        else {
            front =  (front +1 ) % size ; // yha  size isliye add nhi kiya coz yha front is increasing and it will never be -ve 
        }
        
        count--; // 1 element is deleted so decrease count by 1
        return true ;
    }
    
    bool deleteLast() {
        if ( isEmpty()){ // queue empty hai , so return false 
           return false ;
        }
        if( front == rear ){ // queue me ek hi element hai and it`s index is 0 , and after deleting the element the index will be -1
            front = rear = -1 ;
        }
        else {
            rear = (rear - 1 +size) % size ; // yha size isliye add kiys hai coz yha rear decreasing hai and jb jb ye -1 hoga isliye size ko add kiya hai , aur %size isliye kiya hai taki rotate liya ja ske
        }
       count--; //1 element is deleted so decrease count by 1
       return true ;
    }
     
    int getFront() {
        if( isEmpty() ){ // if queue is empty ,then there isn`t any element so return -1
           return -1 ;
        } 
       return arr[front] ; // othewisem return the front element  
    }
    
    int getRear() {
        if( isEmpty() ){ // if queue is empty ,then there isn`t any element so return -1
          return -1 ;
        } 
       return arr[rear] ; // othewisem return the rear element  
    }
    
    bool isEmpty() { 
        return count == 0;  // agr current elements 0  hai to queue empty hai 
    }
    
    bool isFull() {
        return count == size ; // agr current element size ke equal hai to queue full hai 
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */