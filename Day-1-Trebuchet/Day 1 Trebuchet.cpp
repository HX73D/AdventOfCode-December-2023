#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>


int calCulateSum(std::string line) {
    std::vector< std::string > numbers;
    for (char i : line) {
        if (isdigit(i)) {
            numbers.push_back(std::string(1, i));
        }
    }
    int aantal = numbers.size();
    int correctNumber = 0;

    // 1 word 11
    if (aantal == 1) {
       std::string str = numbers[0] + numbers[0];
       correctNumber += std::stoi(str);
    }
    else {
        std::string str = numbers[0] + numbers[aantal - 1];
        correctNumber += std::stoi(str);
    }



    //std::cout << std::endl;

    return correctNumber;
}

void getFileData() {

    std::ifstream file("Data.txt");
    std::string line;

    if (file.is_open()) {
        int total = 0;
        while (getline(file, line)) {
            total = total +calCulateSum(line);
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
