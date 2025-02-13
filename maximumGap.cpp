#include <algorithm> 
#include <iostream>
#include <cstdlib>
#include <ctime>

void maxGap(int size, int* nums) 
{
    int maxDef = 0;


    for (size_t i = 0; i < size ; i++)
    {
        if ( i == size-1)
        {
            continue;
        }
        if (size == 1)
        {
            continue;
        }
        int currDef = nums[i+1]-nums[i];
        if (maxDef < currDef)
        {
            maxDef = currDef;
        }
    }

    std::cout << maxDef << "\n";
}

int main()
{
    std::srand(std::time(0));
    int n = 10000;
    int nums [n] ;
    int size = sizeof(nums) / sizeof(nums[0]);

    for (size_t i = 0; i < n; i++) 
    {
        nums[i] = rand() % 1000000000; 
    }

    //int nums [] = {3,6,9,1};

    std::sort(nums, nums+size);

    auto start = std::chrono::high_resolution_clock::now();
    
    maxGap(size, nums);

    auto stop = std::chrono::high_resolution_clock::now();
    
    // time
    auto duration = std::chrono::duration<double, std::milli>(stop - start);

    std::cout << "Execution time: " << duration.count() << " ms\n";
    return 0;
}