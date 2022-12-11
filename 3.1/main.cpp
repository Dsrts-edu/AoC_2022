#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
//#include <bits/stdc++.h>

int main(){
        // Make a map of the second half values 
        // see if anything in the first half is in the second half 
        std::ifstream input_file("input.txt");
        std::ofstream outfile("out.txt");
        int the_sum = 0;

        while(!input_file.eof()){
                // Make a map with the first half of the string
                std::map<char, int> tmp_first_half;
                std::string line = "";
                getline(input_file, line);
                char tmp_char = '9'; // temporary char
                outfile << line << std::endl;
                // Place characters in the map, as you find new ones
                for (int i = 0; i < (line.size() / 2); i++)
                {
                        outfile << line[i];
                        tmp_first_half.insert(std::pair<char, int>(line[i], 0));
                }
                outfile << std::endl;

                // Loop through second half to find the matching thing 
                for (int i = (line.size() / 2); i < line.size() ; i++){
                        // This is janky but I am half paying attention to this 
                        // one while playing a TTRPG so you get what you get 
                        try
                        {
                                tmp_char = tmp_first_half.at(line[i]);
                        }
                        catch(...)
                        {
                               // std::cout << "No Match\n";
                                continue;
                        }
                        if(tmp_char != 9){
                                tmp_char = line[i];
                                outfile << "tmp_char : " << tmp_char << "\n";
                                break;
                        }
                }

                // Test for upper and lower case 
                if(tmp_char > 96){
                        std::cout << "Lower Case" << std::endl;
                        std::cout << tmp_char - 96 << std::endl;
                        the_sum += tmp_char - 96;
                }
                else
                {
                        the_sum += tmp_char - 38;
                        std::cout << "Upper Case" << std::endl;
                        std::cout << tmp_char - 38 << std::endl;
                }
        }
        std::cout << the_sum << std::endl;
        return 0;
}