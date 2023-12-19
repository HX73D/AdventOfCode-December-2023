#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

void checkPosibility(std::string line) {
    std::string text;
    std::string oneRound;
    std::string green = "green";
    int gameId = 1;
    std::string currentRound;
    
    text += ";";
    
    for (char i : line) {
        
        if (text.find(';') != std::string::npos) {
            oneRound = text;
            


            if (text.find(green) != std::string::npos) {
                std::cout << "test" << std::endl;
                int IndexGreen = oneRound.find(green);
                char green1 = char(oneRound[IndexGreen - 3]);
                char green2 = char(oneRound[IndexGreen - 2]);
                
                if (int(green1) == 32) {
                }
            }
            
            

            text.clear();
        }
        text += i;
    }
    ++gameId;

}

void getFileData() {

    std::ifstream file("Data.txt");
    std::string line;
    int redCubes = 12;
    int greenCubes = 13;
    int blueCubes = 14;

    if (file.is_open()) {
        while (getline(file, line)) {
            checkPosibility(line);
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file";
    }

}

int main() {

    getFileData();

    return 0;
}