#include <fstream>
#include <iostream>
#include <string>
void update_dial(int *current_postition, std::string instruction){

    std::string distance = instruction.substr(1);

    if(instruction[0] == 'L'){
        (*current_postition) -= std::stoi(distance);
    } else {
        (*current_postition) += std::stoi(distance);
    }

    *current_postition = ((*current_postition) + 100) % 100;
}

int main(){

    int dial_postition { 50 }; 
    std::string turn_instruction;
    std::ifstream rotations_file("rotations.csv");

    if(!rotations_file.is_open()){
        std::cerr << "Error: could not open rotations.csv" << '\n';
        return 1; 
    }

    while(std::getline(rotations_file,turn_instruction)){
        if (!turn_instruction.empty()) {
        update_dial(&dial_postition, turn_instruction);
        }
    }


    std::cout << dial_postition << '\n';
    return 0; 
}
