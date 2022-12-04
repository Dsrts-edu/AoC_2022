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
                int my_choice = ((int)cur_line[2] - 23);
                int round_score = 0;

                // set game outcome to the current game's outcome (use ascii values)
               
                game_outcome = their_choice - my_choice;
                outfile << their_choice << " " << my_choice << " \n";
                // Push outcomes to outfile for debug
                outfile << game_outcome << " | ";
                switch (my_choice){
                case 65:
                        outfile << "ROCK ";
                        round_score += 1;
                        break;
                case 66:
                        outfile << "PAPER ";
                        round_score += 2;
                        break;
                case 67:
                        outfile << "SCISSORS ";
                        round_score += 3;
                        break;
                default:
                        //Nothing should happen here, if it does... fix it! 
                        outfile << "\n\n SOMETHING WENT WRONG!!! \n\n";
                        break;
                }
                

                // Win = -1, Tie = 0, Loss = -2 or 1
                // unless The Opponent chose scissors, 
                // in which case 2 is a win and 1 is a loss 
                switch(game_outcome){
                case -1:
                        round_score += 6;
                        outfile << " WIN! ";
                        break;
                case 0:
                        round_score += 3;
                        outfile << " DRAW! ";
                        break;
                case 1: 
                        outfile << " LOSS! ";
                        break; 
                default:
                        if(their_choice == 67){
                                round_score += 6;
                                outfile << " WIN! ";
                                break;
                        }
                        outfile << " LOSS! ";
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

// ASCII values for ref: (diff is 23)
// A - 65   X - 88   ROCK
// B - 66   Y - 89   PAPER
// C - 67   Z - 90   SCISSORS
