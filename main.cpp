//
//  main.cpp
//  AlgorithmsExcercise from
//  https://www.datasim.nl/application/files/2115/3777/1444/Exercise_1_STL_Algorithms.pdf
//
//  Created by jgo on 22/10/2022.
//

#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>


int main(int argc, char** args)
{
    /* 1: Count the frequency of each value in a container. For example, for {1,2,4,5,4,1} we get the output {{1,2},
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
    
    return 0;
}

