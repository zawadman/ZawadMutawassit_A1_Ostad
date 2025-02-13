#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <map>

bool containsSpace(const std::string &input)
{
    for (char c : input) {
        if (c == ' ') return true;
    }
    return false;
}

void pascalTriangle(int numRows)
{
    std::cout << "Generating Pascal's Triangle with " << numRows << " rows:\n";

    std::map<int, std::vector<int>> pascalMap;

    //initialize all indices of pascalMap with 1
    for (int i = 0; i < numRows; i++)
    {
        pascalMap[i] = std::vector<int>(i + 1, 1);  //each row starts with 1s
    }

    for (int row = 2; row < numRows; row++)
    {
        for (int col = 1; col < row; col++)
        {
            pascalMap[row][col] = pascalMap[row - 1][col - 1] + pascalMap[row - 1][col];
        }
    }
    //print triangle
    std::cout << "[";
    for (const auto &pair : pascalMap)
    {
        std::cout << "[";
        for (size_t i = 0; i < pair.second.size(); i++)
        {
            std::cout << pair.second[i];
            if (i < pair.second.size() - 1) std::cout << ",";
        }
        std::cout << "]";
        if (pair.first < numRows - 1) std::cout << ",";
    }
    std::cout << "]\n";
}

int main()
{
    int numRows;
    std::srand(std::time(0));  

    while (true) //infinite loop until valid input is given
    {
        int DEFAULT_VALUE = (std::rand() % 30) + 1;
        std::string input;

        std::cout << "Enter an integer (press Enter to use random default value " << DEFAULT_VALUE << "): ";
        std::getline(std::cin, input);

        //check if input contains any space
        if (containsSpace(input))
        {
            std::cout << "Input cannot contain spaces! Restarting...\n";
            continue;  //restart input loop
        }

        //checks if input is empty (user pressed Enter)
        if (input.empty())
        {
            numRows = DEFAULT_VALUE;
        } 
        else
        {
            std::stringstream ss(input);
            if (!(ss >> numRows))
            {
                std::cerr << "Invalid input! Please enter an integer.\n";
                continue;  //restart input loop
            }
        }

        if (numRows == 0 || numRows > 30)
        {
            std::cout << "Cannot be 0 or more than 30. Restarting...\n";
            continue;  //restart input loop
        }

        std::cout << "You entered: " << numRows << std::endl;
        break; //exit loop when valid input is received
    }

    //printing Pascal's Triangle after a valid input
    //timing before calling pascalTriangle
    auto start = std::chrono::high_resolution_clock::now();
    
    pascalTriangle(numRows);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(stop - start);

    // execution time
    std::cout << "Execution time: " << duration.count() << " ms\n";
    return 0;
}

//BY Zawad Ul Mutawassit