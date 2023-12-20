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
    std::string red = "red";
    std::string blue = "blue";
    int gameId = 1;
    std::string currentRound;
    
    text += ";";
    
    for (char i : line) {
        
        if (text.find(green) != std::string::npos) {
            oneRound = text;
            


            if (text.find(';') != std::string::npos) {
                int IndexGreen = oneRound.find(green);
                char green1 = char(oneRound[IndexGreen - 3]);
                char green2 = char(oneRound[IndexGreen - 2]);

                std::cout << "Green: " << green1;
                std::cout << green2 << std::endl << std::endl;
                
                if (int(green1) == 32) {
                    std::cout << "Groen is kleiner dan 13" << std::endl;
                }
                else if (int(green1) == '1' && (int(green2) == '1' || int(green2) == '2' || int(green2) == '3')) {
                    std::cout << "Groen is kleiner dan 1312" << std::endl;
                }
                else {
                    std::cout << "Green is bigger than 13";
                }

            }
            
            

            text.clear();
        }
        if (text.find(blue) != std::string::npos) {
            oneRound = text;



            if (text.find(';') != std::string::npos) {
                int IndexBlue = oneRound.find(blue);
                char blue1 = char(oneRound[IndexBlue - 3]);
                char blue2 = char(oneRound[IndexBlue - 2]);

                std::cout << "Blue: " << blue1;
                std::cout << blue2 << std::endl << std::endl;

                if (int(blue1) == 32) {
                    std::cout << "blue is kleiner dan 14" << std::endl;
                }
                else if (int(blue1) == '1' && (int(blue2) == '1' || int(blue2) == '2' || int(blue2) == '3' || int(blue2) == '4')) {
                    std::cout << "blue is kleiner dan 14" << std::endl;
                }
                else {
                    std::cout << "blue is bigger than 14";
                }

            }



            text.clear();
        }
        if (text.find(red) != std::string::npos) {
            oneRound = text;



            if (text.find(';') != std::string::npos) {
                int IndexRed = oneRound.find(red);
                char red1 = char(oneRound[IndexRed - 3]);
                char red2 = char(oneRound[IndexRed - 2]);

                std::cout << "red: " << red1;
                std::cout << red2 << std::endl << std::endl;

                if (int(red1) == 32) {
                    std::cout << "red is kleiner dan 13" << std::endl;
                }
                else if (int(red1) == '1' && (int(red2) == '1' || int(red2) == '2')) {
                    std::cout << "red is kleiner dan 13" << std::endl;
                }
                else {
                    std::cout << "red is bigger than 13";
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