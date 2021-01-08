#include <iostream>
#include <vector>
#include <chrono>  
#define MAX 20
#define MIN 0

using namespace std;

class FootballPlayer{
    public:
        int striker_rating;
        int protection_rating;

        FootballPlayer(int str, int prt){
            if(str > MAX || prt > MAX){
                throw "The max of strenght and protection is 20!\nYou cant do that!";
                exit(1);
            }else{
                this->striker_rating = str;
                this->protection_rating = prt;
            }
        }

};

class Team{
    public:
        vector <FootballPlayer> team;
        
        void push_p(FootballPlayer player){
            team.push_back(player);
        }

        void print(){
            if(team.size() == 0){
                throw "You should push_p into the team first!";
                exit(1);
            }
                   
            for (int i=0; i < team.size(); i++) {
                cout << "Player " << i << " Strike =  " 
                     << team[i].striker_rating << ", Protection = "
                     << team[i].protection_rating << endl;
            }
        }
        
        void find_goalkeeper(){ //set the best goalkeeper in possition [0] in the team

            FootballPlayer goalkeeper = FootballPlayer(0, 0);
            if(team.size() == 0){
                throw "You can't find goalkeeper if you don't have players.\nUse push_p!";
                exit(1);
            }
        
            for (int i=0; i < team.size(); i++) {
                if(team[i].protection_rating > goalkeeper.protection_rating){
                    goalkeeper.protection_rating = team[i].protection_rating;
                }
            }
            for (int i = 0; i < team.size(); i++){
                if(team[i].protection_rating == goalkeeper.protection_rating){
                    swap(team[0], team[i]);
                }
            }
        }
        void player_sort_by_striking(){
            for(int i = 1; i < team.size(); i++){
                for(int j = i + 1; j < team.size(); j++){
                    if(team[j].striker_rating > team[i].striker_rating)
                        swap(team[i].striker_rating, team[j].striker_rating);
                }
            }
        }
};

class PenaltyShootout{
    public:
        Team team_1;
        Team team_2;

        PenaltyShootout(Team tm1, Team tm2){
            try{
                tm1.find_goalkeeper(); 
                tm2.find_goalkeeper();
                tm1.player_sort_by_striking();
                tm2.player_sort_by_striking();
                
            }catch(const char* error){
                cout << error << endl;
                exit(1);
            }
            if(tm1.team.size() == tm2.team.size()){
                this->team_1 = tm1;
                this->team_2 = tm2;
            }else{
                throw "You can't start a game with two teams with different number of players!";
                exit(1);
            }
        } 

        /*    Формула за успех при биене на дузпи
            -Всичи опити за биене на дузпа започват с 50% успех за вратаря и 50% за биещия дузпата
            -В зависимост колко е голяма разликата при protection_rating и striking_rating се прилага формулата (показана в примери)
            -Вратар с рейтинг 13 и нападател с рейтинг 17
            - 13 / 20 (макс брой) = 0,65
            - 17 / 20 = 0,85
            - (0,85-0,65)*10 = 2 бонус който се прилага към първоначалните 10 точки (50%) - става 8 вратар, 12 нападател
            - шансове за победа при избиране на рандъм число... вратар печели ако се падне число от 0 до 8, а нападателят печели ако се падне от 9 до 20 (той е с по-висок рейтинг)
        */

        void strike(){
            cout << "STARTING THE GAME" << endl << endl;
            int strikes = team_1.team.size();
            int t1_goals = 0;
            int t2_goals = 0;
            for(int i = 1; i <= strikes; i++){

                if(t1_goals != 3 && t2_goals != 3 && i > (team_1.team.size()-1) ){  //check if more than 5 rounds and if striking players < 5 
                    i = 1;
                }


                double percent_striker_t1 = team_1.team[i].striker_rating / 20.0;
                double percent_goalkeeper_t1 = team_1.team[0].protection_rating / 20.0;
                double percent_striker_t2 = team_2.team[1].striker_rating / 20.0;
                double percent_goalkeeper_t2 = team_2.team[0].protection_rating / 20.0;
                int win = rand() % (MAX - MIN + 1) + MIN;

                cout << "Team ONE is striking..." << endl;

                if(team_1.team[i].striker_rating > team_2.team[0].protection_rating){
                    double perc = percent_striker_t1 - percent_goalkeeper_t2;
                    double win_condition = perc * 10.0;

                    int striker_win_num = 10 + win_condition;
                    int  goalkeeper_win_num = MAX - striker_win_num;
                }

                if(team_1.team[i].striker_rating < team_2.team[0].protection_rating){
                    double perc = percent_goalkeeper_t2 - percent_striker_t1;
                    double win_condition = perc * 10.0;
                   
                    int  goalkeeper_win_num = 10 + win_condition;
                    int striker_win_num = MAX -  goalkeeper_win_num;
                } 

                if(team_1.team[i].striker_rating == team_2.team[0].protection_rating){
                    int  goalkeeper_win_num = 10;
                    int striker_win_num = 10;
                } 
                // check if there is a goal
                if(win > team_2.team[0].protection_rating){
                        t1_goals += 1;
                        cout << "___GOAL!" << endl;
                }else{
                    cout << "--The goalkeeper caught the ball!" << endl;
                }    
                // prtint the current result if team1 win
                if(t1_goals == 3){
                    cout << "Current result: " << t1_goals << " : " << t2_goals << endl << endl;
                    cout << "!+++__Team ONE won the game!__+++!" << endl;
                    exit(0); 
                }  

                cout << "Team TWO is striking..." << endl;
                if(team_2.team[i].striker_rating > team_2.team[0].protection_rating){
                    double perc = percent_striker_t2 - percent_goalkeeper_t1;
                    double win_condition = perc * 10.0;

                    int striker_win_num = 10 + win_condition;
                    int  goalkeeper_win_num = MAX - striker_win_num;
                }

                if(team_2.team[i].striker_rating < team_1.team[0].protection_rating){
                    double perc = percent_goalkeeper_t1 - percent_striker_t2;
                    double win_condition = perc * 10.0;
                   
                    int  goalkeeper_win_num = 10 + win_condition;
                    int striker_win_num = MAX -  goalkeeper_win_num;
                } 

                if(team_2.team[i].striker_rating == team_1.team[0].protection_rating){
                    int  goalkeeper_win_num = 10;
                    int striker_win_num = 10;
                }

                if(win > team_1.team[0].protection_rating){
                        t2_goals += 1;
                        cout << "___GOAL!" << endl;
                }else{
                    cout << "--The goalkeeper caught the ball!" << endl;;
                }           

                if(t2_goals == 3){
                    cout << "Current result: " << t1_goals << " : " << t2_goals << endl << endl;
                    cout << "!+++__Team TWO won the game!__+++!" << endl;
                    exit(0);
                }
                //Print the current result 
                cout << "Current result: " << t1_goals << " : " << t2_goals << endl << endl;

            }


        }
};



int main(){

    srand(time(NULL));

    try{
        Team team1;
        FootballPlayer t1_p1 = FootballPlayer(12, 3);
        FootballPlayer t1_p2 = FootballPlayer(11, 3);
        FootballPlayer t1_p3 = FootballPlayer(16, 1);
        FootballPlayer t1_p4 = FootballPlayer(16, 13);
        FootballPlayer t1_p5 = FootballPlayer(19, 9); 

        team1.push_p(t1_p1);
        team1.push_p(t1_p2);
        team1.push_p(t1_p3);
        team1.push_p(t1_p4);
        team1.push_p(t1_p5);


        Team team2;
        FootballPlayer t2_p1 = FootballPlayer(17, 9);
        FootballPlayer t2_p2 = FootballPlayer(11, 7);
        FootballPlayer t2_p3 = FootballPlayer(20, 8);
        FootballPlayer t2_p4 = FootballPlayer(6, 10);
        FootballPlayer t2_p5 = FootballPlayer(15, 2); 
        //FootballPlayer t2_p6 = FootballPlayer(15, 2); 

        team2.push_p(t2_p1);
        team2.push_p(t2_p2);
        team2.push_p(t2_p3);
        team2.push_p(t2_p4);
        team2.push_p(t2_p5);
        //team2.push_p(t2_p6);

        PenaltyShootout game = PenaltyShootout(team1, team2);
        game.strike();

    }catch(const char* error){
        cout << error << endl;
    }
    
    return 0;
}