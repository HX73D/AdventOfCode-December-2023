#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

int gameId = 0;

int checkPosibility(std::string line) {
    int currentGreen;
    int maxRed = 0;
    int maxGreen = 0;
    
    int maxBlue = 0; 
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
                if (boolGreen) {
                    std::string strGreen1 = (green1 == ' ') ? "" : std::string(1, green1);
                    std::string strGreen2 = std::string(1, green2);
                    std::string currentGreen = strGreen1 + strGreen2;
                    /*std::cout << std::endl << std::stoi(currentGreen);*/
                    

                    if (std::stoi(currentGreen) >  maxGreen) {
                       maxGreen = std::stoi(currentGreen);
                             
                    /*std::cout << maxGreen << "\n\n";*/
                    }
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
                if (boolBlue) {
                    std::string strBlue1 = (blue1 == ' ') ? "" : std::string(1, blue1);
                    std::string strBlue2 = std::string(1, blue2);
                    std::string currentBlue = strBlue1 + strBlue2;
                    /*std::cout << std::endl << std::stoi(currentBlue);*/


                    if (std::stoi(currentBlue) > maxBlue) {
                        maxBlue = std::stoi(currentBlue);

                        /*std::cout << maxBlue << "\n\n";*/
                    }
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
                if (boolRed) {
                    std::string strRed1 = (red1 == ' ') ? "" : std::string(1, red1);
                    std::string strRed2 = std::string(1, red2);
                    std::string currentRed = strRed1 + strRed2;
                    /*std::cout << std::endl << std::stoi(currentRed);*/


                    if (std::stoi(currentRed) > maxRed) {
                        maxRed = std::stoi(currentRed);

                        /*std::cout << maxRed << "\n\n";*/
                    }
                }
            }
            text.replace(text.find(red), 4, " ");
        }

        text += i;
    }

    if (boolGreen && boolRed && boolBlue) {
        int maxTotal = maxRed * maxBlue * maxGreen;
        std::cout << maxTotal << std::endl;
        return maxTotal;
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