#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int calCulateSum(std::string line) {
    std::string one = "one";
    std::string two = "two";
    std::string three = "three";
    std::string four = "four";
    std::string five = "five";
    std::string six = "six";
    std::string seven = "seven";
    std::string eight = "eight";
    std::string nine = "nine";



    std::vector< std::string > numbers;
    std::vector< std::string > textAmount;
    std::string textToNumbers;

    for (char i : line) {
        if (isdigit(i)) {
            numbers.push_back(std::string(1, i));
            
            
        }
        if (isalpha(i)) {
            textToNumbers += i;
            transform(textToNumbers.begin(), textToNumbers.end(), textToNumbers.begin(), ::tolower);
            if (textToNumbers.find(one) != std::string::npos) {
                
                textToNumbers.clear();
                numbers.push_back(std::string("1", 1));
            }
            if (textToNumbers.find(two) != std::string::npos) {
                
                textToNumbers.clear();
                numbers.push_back(std::string("2", 1));
            }
            if (textToNumbers.find(three) != std::string::npos) {
                
                textToNumbers.clear();
                numbers.push_back(std::string("3", 1));
            }
            if (textToNumbers.find(four) != std::string::npos) {
                
                textToNumbers.clear();
                numbers.push_back(std::string("4", 1));
            }
            if (textToNumbers.find(five) != std::string::npos) {
               
                textToNumbers.clear();
                numbers.push_back(std::string("5", 1));
            }
            if (textToNumbers.find(six) != std::string::npos) {
                
                textToNumbers.clear();
                numbers.push_back(std::string("6", 1));
            }
            if (textToNumbers.find(seven) != std::string::npos) {
                
                textToNumbers.clear();
                numbers.push_back(std::string("7", 1));
            }
            if (textToNumbers.find(eight) != std::string::npos) {
                
                numbers.push_back(std::string("8", 1));
                textToNumbers.clear();
            }
            if (textToNumbers.find(nine) != std::string::npos) {
          
                textToNumbers.clear();
                numbers.push_back(std::string("9", 1));
            }
        }
    }
        int aantal = numbers.size();
        std::cout << numbers[0] + numbers[aantal - 1] << std::endl;
 
    int correctNumber = 0;

    if (aantal == 1) {
        std::string str = numbers[0] + numbers[0];
        correctNumber += std::stoi(str);
    }
    else {
        std::string str = numbers[0] + numbers[aantal - 1];
        correctNumber += std::stoi(str);
    }

    return correctNumber;
}

void getFileData() {

    std::ifstream file("Data.txt");
    std::string line;

    if (file.is_open()) {
        int total = 0;
        while (getline(file, line)) {
            total = total + calCulateSum(line);
        }

        std::cout << "Total is: " << total;
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