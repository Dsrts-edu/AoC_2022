#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
//#include <bits/stdc++.h>

void printGroup(std::map<char, char> &m);

int main(){
        // Make a map of the second half values 
        // see if anything in the first half is in the second half 
        std::ifstream input_file("input.txt");
        std::ofstream outfile("out.txt");
        int the_sum = 0;

        int cur_group_number = 1; //(from 1-3) 

        // Make a map with the first half of the string
        std::map<char, char> group_1;
        std::map<char, char> group_2;
        std::map<char, char> group_3;

        // idx 0, 1, 2 hold each triple string groups. 
        std::string group[3];

        while (!input_file.eof())
        {

                // Get the next line 
                std::string line = "";
                getline(input_file, line);

                // Depending on if this is the 3rd pass 
                // or not, behavior as follows

                char tmp_char; // temporary char
                switch(cur_group_number){
                case 1: 
                        for (int i = 0; i < line.size(); i++)
                        {
                                outfile << line[i];
                                char c = line[i];
                                group_1.insert(std::pair<char, char>(c,c));
                        }
                        cur_group_number++;
                        break;
                case 2:
                        for (int i = 0; i < line.size() ; i++){
                        // This is janky but I am half paying attention to this 
                        // one while playing a TTRPG so you get what you get 
                        try
                        {
                                tmp_char = group_1.at(line[i]);
                        }
                        catch(...)
                        {
                               // std::cout << "No Match\n";
                                continue;
                        }
                        if(tmp_char != 9){
                                tmp_char = line[i];
                                group_2.insert(std::pair<char, char>(tmp_char,tmp_char));
                                
                        }
                
                        }
                        cur_group_number++;
                        break;
                case 3:
                        for (int i = 0; i < line.size() ; i++){
                        // This is janky but I am half paying attention to this 
                        // one while playing a TTRPG so you get what you get 
                                try
                                {
                                        tmp_char = group_2.at(line[i]);
                                }
                                catch(...)
                                {
                                // std::cout << "No Match\n";
                                        continue;
                                }
                              
                                tmp_char = line[i];
                                        
                                                // Test for upper and lower case 
                        }

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
                        printGroup(group_1);
                        printGroup(group_2);
                        std::cout << tmp_char << std::endl;
                        cur_group_number = 1;
                        // Clean up maps for next group of 3 
                        group_1.clear();
                        group_2.clear();
                        group_3.clear();
                        break;
                default:
                        std::cout << "BROKE" << std::endl;
                        break;
                }
                // Place characters in the first map of the group, as you find new ones
                

                outfile << std::endl;

        }
        std::cout << the_sum << std::endl;
        return 0;
}


void printGroup(std::map<char, char> &m){
        std::cout << "group: ";
        for (std::pair<char, char> p : m)
        {
                std::cout << p.first;
        }
        std::cout << std::endl;
}