#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

int gameId = 0;

int checkPosibility(std::string line) {
    std::string line1 = ";";
    line1 += line += ";";
    gameId += 1;
    std::string text;
    std::string oneRound;
    std::string green = "green";
    std::string red = "red";
    std::string blue = "blue";
    bool boolGreen = true;
    bool boolBlue = true;
    bool boolRed = true;
    
    std::string currentRound;

    for (char i : line1) {
        
        if (text.find(green) != std::string::npos) {
            oneRound = text;
            


            if (text.find(';') != std::string::npos) {
                int IndexGreen = oneRound.find(green);
                char green1 = char(oneRound[IndexGreen - 3]);
                char green2 = char(oneRound[IndexGreen - 2]);

                if (int(green1) == 32) {
                    
                }
                else if (int(green1) == '1' && (int(green2) == 48 || int(green2) == '1' || int(green2) == '2' || int(green2) == '3')) {
                    
                }
                else {
                    boolGreen = false;
                }

            }
            
            text.replace(text.find(green), 4, " ");

            
        }
        if (text.find(blue) != std::string::npos) {
            oneRound = text;

            if (text.find(';') != std::string::npos) {
                int IndexBlue = oneRound.find(blue);
                char blue1 = char(oneRound[IndexBlue - 3]);
                char blue2 = char(oneRound[IndexBlue - 2]);

                if (int(blue1) == 32) {

                }
                else if (int(blue1) == '1' && (int(blue2) == '0' || int(blue2) == '1' || int(blue2) == '2' || int(blue2) == '3' || int(blue2) == '4')) {

                }
                else {
                    boolBlue = false;
                }

            }

            text.replace(text.find(blue), 4, " ");
           
        }
        if (text.find(red) != std::string::npos) {
            oneRound = text;

            if (text.find(';') != std::string::npos) {
                int IndexRed = oneRound.find(red);
                char red1 = char(oneRound[IndexRed - 3]);
                char red2 = char(oneRound[IndexRed - 2]);

                if (int(red1) == 32) {

                }
                else if (int(red1) == '1' && (int(red2) == '0' || int(red2) == '1' || int(red2) == '2')) {

                }
                else {
                    boolRed = false;
                }
            }
            text.replace(text.find(red), 4, " ");
        }
        text += i;
    }

    if (boolGreen && boolRed && boolBlue) {
        std::cout << gameId << std::endl;
        return gameId;
    }
    else {
        return 0;
    }

}

int getFileData() {

    std::ifstream file("Data.txt");
    std::string line;
    int redCubes = 12;
    int greenCubes = 13;
    int blueCubes = 14;
    int total = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            total += checkPosibility(line);
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file";
    }
    return total;
}

int main() {

    std::cout << getFileData();

    return 0;
}