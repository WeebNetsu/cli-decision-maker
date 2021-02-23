#include <iostream>
#include <cstdlib> //import to use rand() function
#include <ctime>
#include <vector>

#include "CommonMethods.hpp"

// https://www.geeksforgeeks.org/insertion-sort/
void sortValues(std::vector<int> &arr1, std::vector<std::string> &arr2)
{
    int i, key1, j;
    std::string key2;
    for (i = 1; i < arr1.size(); i++)
    {
        key1 = arr1.at(i);
        key2 = arr2.at(i);
        j = i - 1;

        while (j >= 0 && arr1.at(j) > key1)
        {
            arr1.at(j + 1) = arr1.at(j);
            arr2.at(j + 1) = arr2.at(j);
            j = j - 1;
        }

        arr1.at(j + 1) = key1;
        arr2.at(j + 1) = key2;
    }
}

int main(int argc, char const *argv[])
{
    if (argc <= 2)
    {
        std::cout << "Too few parameters added" << std::endl;
        return 0;
    }

    std::vector<std::string> options;

    for (int i = 1; i < argc; i++)
    {
        options.push_back(argv[i]);
    }

    bool customAmount = false;
    int amount = argc * 20;

    for (int i = 0; i < options.size(); i++)
    {
        if (customAmount)
        {
            if (cmds::sii(options.at(i))) // check if string is a positive integer value
            {
                amount = std::stoi(options.at(i));
                customAmount = false;
                options.erase(options.begin() + i);
                i--;
            }
            else
            {
                std::cout << "No positive number after '-n', error." << std::endl;
                return 0;
            }
        }

        if (cmds::compareStrings(options.at(i), "-n"))
        {
            customAmount = true;
            options.erase(options.begin() + i);
            i--;
        }
    }

    std::vector<int> values;

    for (int i = 0; i < options.size(); i++)
    {
        values.push_back(0);
    }

    srand(time(0));
    for (int i = 0; i < amount; i++)
    {
        int val = 1 + (rand() % options.size()); // random number between 1 and length of option (including both)

        values.at(val - 1) += 1;
    }

    sortValues(values, options);
    for (int i = values.size() - 1; i >= 0; i--)
    {
        std::cout << options.at(i) << ": " << values.at(i) << std::endl;
    }

    return 0;
}