class MyCircularDeque {
    vector<int> arr;
    int size ;
    int front ;
    int rear;
    int count ;

public:

    MyCircularDeque(int k) {
        size = k ;
        arr.resize(size);
        front = rear = -1 ;
        count = 0 ;

    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false ;
        }
        
        if(isEmpty()){
            front = rear = 0 ;
        }
        else{
            front =  ( front - 1 + size ) % size ;

        }
        arr[front] = value ;
        count++ ;
        return true ;
    }
    
    bool insertLast(int value) {
        if( isFull()){
            return false ;
        }
        if( isEmpty()){
            front = rear  = 0 ;
        }
        else {
            rear = (rear+1  )%size ;
        }

        arr[rear] = value ;
        count++ ;
        return true ;
    }
    
    bool deleteFront() {
        // Q empty hai
        if( isEmpty()){
            return false ;
        }
        // Q me ek hi element hai 
        if( front == rear ){
            front = rear = -1 ;
        }
        else {
            front =  (front +1 ) % size ;
        }
        
        count--;
        return true ;
    }
    
    bool deleteLast() {
        // Q empty hai
        if ( isEmpty()){
           return false ;
        }
        // Q me ek hi element hai
        if( front == rear ){
            front = rear = -1 ;
        }
        else {
            rear = (rear - 1 +size) % size ;
        }
       count--;
       return true ;
    }
     
    int getFront() {
        if( isEmpty() ){
           return -1 ;
        } 
       return arr[front] ; 
    }
    
    int getRear() {
        if( isEmpty() ){
          return -1 ;
        } 
       return arr[rear] ; 
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size ;
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