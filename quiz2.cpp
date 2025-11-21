
           
            #include <iostream>
            using namespace std;

          class ScoreCard {
          private:
           
            int totalScore;
            int totalOutPlayers;
            int totalDeliveries;
            
            static const int maxOutPlayers = 11;   // static key word use 

        public:
           
            // constructor  
           
            ScoreCard(int score, int outs, int deliveries)
                : totalScore(score), totalOutPlayers(outs), totalDeliveries(deliveries) {}

            // Copy constructor
          
            ScoreCard(const ScoreCard &obj)
               
                : totalScore(obj.totalScore), totalOutPlayers(obj.totalOutPlayers), totalDeliveries(obj.totalDeliveries) {}

            // function to increment the  score
            
            void incrementScore(int runs) {
                if (totalOutPlayers < maxOutPlayers) {
                    totalScore += runs;
                    totalDeliveries++;
            } 
                else {
                    
                    cout << "no more score can be added. all players are out.\n";
                } }

            // function to increment the number of out players

            void playerOut() {
                if (totalOutPlayers < maxOutPlayers) {
                    totalOutPlayers++;
                    totalDeliveries++;
                } else {
                    cout << "all players are already out.\n";
                }
            }

            // function for total score  
           
            void viewScore() const {
                cout << "total score: " << totalScore << "\n";
                cout << "total outs: " << totalOutPlayers << "\n";
                cout << "total  deliveries: " << totalDeliveries << "\n";
            }

            // function to get outs 
            
            int getTotalOutPlayers() const {
                return totalOutPlayers;
            }
        };

        int main() {
            
            // creating obj1 constructor
            
            ScoreCard object1(0, 0, 0);       // intilaize the (0,0,0)

            // creating obj2 using copy constructor
           
            ScoreCard object2 = object1;

            // creating obj3
           
            ScoreCard object3 = object1;

            // test calls
            
            object1.incrementScore(4);     // increment score
            object1.playerOut();           // player gets out
            object1.viewScore();           // view the total score and outs

            return 0;

        }
