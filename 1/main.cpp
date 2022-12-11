#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
//#include <bits/stdc++.h>

int main(){

        int max_sum = 0; // The elf with the mostest
        int cur_sum = 0; // loop sum tracking, sum per "elf"

        // Open filestreams 
        std::ifstream input_file("input.txt");
        std::ofstream outfile("out.txt");
        std::vector<int> top_three;
        
        for (int i = 0; i < 3; i++){
                top_three.push_back(0);
        }

        // Find the max sum 
        while(!input_file.eof()){
                
                std::string cur_line = "";
                std::getline(input_file, cur_line);

                // If the current line is empty, this breaks spots between elves
                if(cur_line == ""){

                        
                        // Add the top three sums to the list 
                        for(int i = 0; i < 3; i++){
                               
                                if (cur_sum > top_three.at(i))
                                {
                                        top_three.at(i) = cur_sum;
                                        break;
                                }
                        }
                        
                        // Calc max sum (from previous part 1)
                        if(max_sum < cur_sum){
                                max_sum = cur_sum;

                                // outfile for debugging
                                outfile << "\tNEWMAX!: " << max_sum << "\n";
                        }
                        outfile << "Current sum: "<< cur_sum << "\n";
                        cur_sum = 0; // reset current sum
                // If the line is not a line break, add it's contents to 
                // cur sum 
                }else{
                        cur_sum += std::stoi(cur_line);
                }
        }
       // std::sort(top_three.begin(), top_three.end());
        std::cout << "The Elves with the top three calories are:\n"
                  << "\n1: " << top_three.at(0) << "\n2: " << top_three.at(1) << "\n3: " << top_three.at(2) << "\n";
        int top_three_cals = 0;
        for (int i = 0; i < 3; i++)
        {
                top_three_cals += top_three.at(i);
        }
        std::cout << " Top three calories: " << top_three_cals << "\n";
        // close files !!
        outfile.close();
        input_file.close();
}
