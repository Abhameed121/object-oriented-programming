
	#include <iostream>
	using namespace std ;
	
	class Car{
		    private :
		    	string name ;
		    	string model ;
			int year ;
			
            public :
		          void set_data(string n1 , string m1 , int y){
		          name = n1 ;
		          model = m1 ;
		          year = y ;
	}
	            string Name(){                // function to return name of car
	            	return name ;
		}
		      string Model(){               // function to return the model 
		      	return model ;
	}
	            int Year(){                  // function to return Year of model 
	            	return year ;
	      }
	};
	      int main(){
	      	Car c1 ;
	      	Car c2  ;
	      	Car c3 ;
	      	  
	      	c1.set_data("Toyota","A6" , 2024);
	      	c2.set_data("Honda","A4" , 2021);
	      	c3.set_data("Oddi","A12" , 2020);
	      	  
	      cout << "Name:" <<c1.Name()<< " Model:" <<c1.Model()<< " Year:" <<c1.Year() <<endl ;
		cout << "Name:" <<c2.Name() << " Model:" << c2.Model()<< " Year:" << c2.Year()<< endl;
		cout << "Name:" <<c3.Name() << " Model:" << c3.Model()<< " Year:" << c3.Year()<< endl ;
		
			return 0 ;
		}
