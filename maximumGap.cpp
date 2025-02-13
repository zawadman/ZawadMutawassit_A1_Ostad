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

void populateArray(int* nums, int n)
{
    for (size_t i = 0; i < n; i++) 
    {
        nums[i] = rand() % 1000000000; 
    }
}

int main()
{
    // std::srand(std::time(0));
    int n = 10000;
    //int nums [] = {3,6,9,1};//// COMMENT THIS AND UNCOMMENT THE RANDOM NUMBER POPULATION FUNCTION
    int nums [n] ;//// COMMENT THIS TO POPULATE ARRAY WITH DESCRETE RANDOM VALUES
    populateArray(nums,n);///// COMMENT THIS TO POPULATE ARRAY WITH DESCRETE RANDOM VALUES
    int size = sizeof(nums) / sizeof(nums[0]);

    std::sort(nums, nums+size);

    auto start = std::chrono::high_resolution_clock::now();
    
    maxGap(size, nums);

    auto stop = std::chrono::high_resolution_clock::now();
    
    // time
    auto duration = std::chrono::duration<double, std::milli>(stop - start);

    std::cout << "Execution time: " << duration.count() << " ms\n";
    return 0;
}

///By Zawad Ul Mutawassit