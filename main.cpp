//
//  main.cpp
//  AlgorithmsExcercise from
//  https://www.datasim.nl/application/files/2115/3777/1444/Exercise_1_STL_Algorithms.pdf
//
//  Created by jgo on 22/10/2022.
//

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <set>
#include <stdio.h>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

template<typename T>
auto Exercise2(T first, T last, std::size_t size)
{
    std::cout<< "Excercise 2 input: \n";
    T it = first;
    for(; it != last; ++it)
    {
        std::cout << *it << "\n";
    }

    auto minimum = *std::min_element(first, last);
    auto maximum = *std::max_element(first, last);
    auto sum = std::accumulate(first, last, 0U);
    auto average = sum / (size);

    return std::make_tuple(minimum, maximum, sum, average);
}


int main(int argc, char** args)
{
    /* 1a: Count the frequency of each value in a container. For example, for {1,2,4,5,4,1} we get the output {{1,2},
    {2,1}, {4,2}, {5,1}} as pairs of {value, frequency}. There are different ways to model the output depending on
    your requirements.*/
    std::vector<int> v1{1,2,4,5,4,1};
    std::set<int> singleValues(v1.begin(), v1.end());
    std::set<std::pair<int, int> > output;

    std::for_each(singleValues.begin(), singleValues.end(), [&](const int number){
        auto count = std::count(v1.begin(), v1.end(), number);
        output.emplace(number, count);
    });

    std::cout << "Excercise 1 output: \n";
    for(auto pair : output)
    {
        std::cout << pair.first << " : " << pair.second << "\n";
    }
    
    /* b): Write a function to compute the minimum, maximum, sum and average of the values of the elements in a
     container with numeric values. The output is a tuple with four elements.*/

    auto ex2Tuple = Exercise2(v1.begin(), v1.end(), v1.size());
    std::cout << "Excercise 2 output: \n";
    std::cout << "Minimum value: " << std::to_string(std::get<0>(ex2Tuple)) << "\n";
    std::cout << "Maximum value: " << std::to_string(std::get<1>(ex2Tuple)) << "\n";
    std::cout << "Sum value: " << std::to_string(std::get<2>(ex2Tuple)) << "\n";
    std::cout << "Average value: " << std::to_string(std::get<3>(ex2Tuple)) << "\n";
    
    
    return 0;
}

