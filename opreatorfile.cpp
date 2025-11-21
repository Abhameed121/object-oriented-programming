
    
        #include <iostream>
        using namespace std ;

        class Sub{
        private :
        
        int a ;

        public :
        Sub(){};
    
        Sub(int n){
        a = n ;
    }
        void dicrement(){
        a-- ;
    }
        void display(){
        cout<<"the value of x is :" << a << endl ;
    }
    };
        int main(){
                
                Sub obj1(5) ;
                obj1.display();
                obj1.dicrement();
                obj1.display();
                    
                    return 0 ;
        }
      
      
      




