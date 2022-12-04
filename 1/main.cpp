#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main(){

        int max_sum = 0; // The elf with the mostest
        int cur_sum = 0; // loop sum tracking, sum per "elf"

        // Open filestreams 
        std::ifstream input_file("input.txt");
        std::ofstream outfile("out.txt");

        // Find the max sum 
        while(!input_file.eof()){
                
                std::string cur_line = "";
                std::getline(input_file, cur_line);

                // If the current line is empty, this breaks spots between elves
                if(cur_line == ""){

                        // If the max sum is less than the current sum
                        // set cur as max 
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
        std::cout << "The Elf With the most has: " << max_sum << " calories!\n";

        // close files !!
        outfile.close();
        input_file.close();
}
