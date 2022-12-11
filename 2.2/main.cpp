#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main(){

        int total_score = 0; // loop sum tracking, sum per "elf"
        int game_outcome = 0;
        // Open filestreams
        std::ifstream input_file("input.txt");
        std::ofstream outfile("out.txt");

        // Find the max sum 
        while(!input_file.eof()){
                
                std::string cur_line = "";
                std::getline(input_file, cur_line);

                // Run error checks
                if(cur_line.length() > 3 || cur_line.length() < 3){
                        continue;
                }

                int their_choice = (int)cur_line[0];
                int mandated_outcome = ((int)cur_line[2] - 23);
                int round_score = 0;

                // set game outcome to the current game's outcome (use ascii values)
               
                game_outcome = their_choice - mandated_outcome;
                outfile << their_choice << " " << mandated_outcome << " \n";
                // Push outcomes to outfile for debug
                outfile << game_outcome << " | ";

                // The mandated outcome 
                switch (mandated_outcome){
                case 65:
                        outfile << "LOSE ";
                        switch(their_choice){
                        case 65:
                                round_score += 3; // if rock you must choose scissors to lose
                                break;
                        case 66:
                                round_score += 1; // if paper you must choose rock to lose
                                break;
                        case 67:
                                round_score += 2; // if scissors you must choose paper to lose
                                break;
                        default:
                                outfile << "\n\n SOMETHING WENT WRONG!!! \n\n";
                                break;
                        }
                        break;
                case 66:
                        outfile << "DRAW ";
                        // draw is worth 2 pts + Choice ASCII value - 64 (ei: 67 - 64 = 3 pts for scissors)
                        // Works because choices are equivalent for a draw
                        round_score += ((their_choice - 64) + 3);
                        break;
                case 67:
                        outfile << "WIN ";
                        round_score += 6; // 6 for a win 
                        switch(their_choice){
                        case 65:
                                round_score += 2; // if rock you must choose paper to win
                                break;
                        case 66:
                                round_score += 3; // if paper you must choose scissors to win
                                break;
                        case 67:
                                round_score += 1; // if scissors you must choose rock to win
                                break;
                        default:
                                outfile << "\n\n SOMETHING WENT WRONG!!! \n\n";
                                break;
                        }
                        break;
                default:
                        //Nothing should happen here, if it does... fix it! 
                        outfile << "\n\n SOMETHING WENT WRONG!!! \n\n";
                        break;
                }
                
        

                outfile << "Round Score: " << round_score << "\n";
                // Add round score to total score 
                total_score += round_score;
        }

        std::cout << "Your final score is: " << total_score << "\n";
        // close files !!
        outfile.close();
        input_file.close();
}


// if the value is the same, it is a tie (rock == rock, etc )
//                             
// Rock > Scissors   LOSS       65 - 67 = -2
// Scissors < ROCK   WIN        67 - 65 = 2
// Scissors > paper  LOSS       67 - 66 = 1
// Rock < Paper      WIN        65 - 68 = -1
// Paper < Scissors  WIN        66 - 67 = -1
// Paper > Rock      LOSS       66 - 65 = 1
//
// Ties will be 0, wins == -1, unless they chose scissors, in which case -2 is a win and -1 is a loss 

// ASCII values for ref: (diff is 23) .   points worth : 
// A - 65   X - 65   ROCK LOSE                          1
// B - 66   Y - 66   PAPER DRAW                         2
// C - 67   Z - 67   SCISSORS WIN                       3

// Mandated outcomes    | My choice     | choice v outcome | 

// Rock -> Draw         | Rock          | -1            |  67 their choice = score add for draws 
// Paper -> Draw        | Paper         | 0             |
// Scissors -> Draw     | Scissors      | -2            | .   
                                                      // score result
// Rock -> Lose         | Scissors      | 0             |   3
// Paper -> Lose        | Rock          | 1             |  1
// Scissors -> Lose     | Paper         | -2            |  2

// Rock -> Win          | Paper         | -2            | 2
// Paper -> Win         | Scissors      | -1            | 3
// Scissors -> Win      | Rock          | 0             | 1

