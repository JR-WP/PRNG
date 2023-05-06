#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution
#include <chrono> // for std::chrono

int main()
{
unsigned int NumArray[100]{};
//std::mt19937_64 mt{}; // Instantiate a 64-bit Mersenne Twister

//will ask the OS for a random number
//std::mt19937_64 mt{ std::random_device{}() };



std::mt19937_64 mt{
                static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) //Choose to use std::chrono::high_resolution_clock instead of std::chrono::steady_clock.
               };

// Create a reusable random number generator that generates uniform numbers between 1 and #
std::uniform_int_distribution<> tmp{ 1, 100 }; //	std::uniform_int_distribution #{ 1, # }; // for C++14, use std::uniform_int_distribution<> #{ 1, # };

// Print a bunch of random numbers
for (int count{ 1 }; count <= 100; ++count)
{
    NumArray[count] = tmp(mt);
    std::cout << tmp(mt) << '\t'; // generate a roll of the die here
    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
			std::cout << '\n';
	}
// Count occurrences of each value in NumArray
for (int i = 0; i < 100; i++)
{
    NumArray[i]++;
}

// Print histogram
for (int i = 0; i < 6; i++)
    {
    std :: cout << "\t" <<i + 1 << ": ";
        for (int j = 0; j < NumArray[i]; j++)
        {
            std :: cout << "*";
        }
    std :: cout << "\n ";
    }

	return 0;
}


