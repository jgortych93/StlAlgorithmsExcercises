//
//  main.cpp
//  AlgorithmsExcercise from
//  https://www.datasim.nl/application/files/2115/3777/1444/Exercise_1_STL_Algorithms.pdf
//
//  Created by jgo on 22/10/2022.
//

#include <algorithm>
#include <cstddef>
#include <functional>
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
    
    /*c) Consider the container S = {1,2,-3,4,5,5,5,6}. Use an STL algorithm to find the first occurrence of the value.*/
    std::vector<int> v2{1,2,-3,4,5,5,5,6};
    int exampleValue = -3;
    std::vector<int>::iterator result = std::find(v2.begin(), v2.end(), exampleValue);
    if(result != v2.end())
    {
        std::cout << "Value: " << std::to_string(*result) << " found.\n";
    }
    else
    {
        std::cout << "Value: " << std::to_string(exampleValue) << " not found.\n";
    }
    



    /* 2. Now use the following functions:
     std::bind2nd() - removed in c++ 17
     std::bind()
     Lambda expression
     to find the position of the first even number in S.*/

    auto modulo2 = std::bind(std::modulus(), std::placeholders::_1, 2);
    auto firstEvenNumberPos = std::find_if(v2.begin(), v2.end(), [&modulo2](int number){ return (modulo2(number) == 0); });
    if(firstEvenNumberPos != v2.end())
    {
        std::cout << "First even value: " << std::to_string(*firstEvenNumberPos) << " found.\n";
    }
    else
    {
        std::cout << "No even value found.\n";
    }




    /*2d) Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5}.
     Determine how to do the following:
      Return the position of the first three consecutive elements having the value 5.
      Return the position of the first element of the first subrange matching {3,4,5}.
      Return the position of the first element of the last subrange matching {3,4,5}.*/
    std::vector<int> ex2d{1,2,5,5,-3,4,5,5,5,6,3,4,5,3,4,5};

    auto pos = std::search_n(ex2d.begin(), ex2d.end(), 3, 5);
    if(pos != ex2d.end())
    {
        std::cout << "Three conscutive 5 elements found on position: " << std::to_string(std::distance(ex2d.begin(), pos)) << "\n";
    }

    std::vector<int> firstSubrange{3,4,5};
    auto pos2 = std::search(ex2d.begin(), ex2d.end(), firstSubrange.begin(), firstSubrange.end());
    if(pos2 != ex2d.end())
    {
        std::cout << "The position of the first element of the first subrange matching {3,4,5} found at position: " << std::to_string(std::distance(ex2d.begin(), pos2)) << "\n";
    }

    std::vector<int> lastSubrange{3,4,5};
    auto pos3 = std::find_end(ex2d.begin(), ex2d.end(), lastSubrange.begin(), lastSubrange.end());
    if(pos3 != ex2d.end())
    {
        std::cout << "The position of the first element of the last subrange matching {3,4,5} found at position: " << std::to_string(std::distance(ex2d.begin(), pos3)) << "\n";
    }




    /*2e) Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5}. Find the first element in S that has a value equal to
     the value of the following element.*/
    std::vector<int> ex2e{1,2,5,5,-3,4,5,5,5,6,3,4,5};

    auto pos4 = std::adjacent_find(ex2e.begin(), ex2e.end());
    if(pos4 != ex2e.end())
    {
        std::cout << "The first element in container that has a value equal to the value of the following element found at position: " << std::to_string(std::distance(ex2e.begin(), pos4)) << "\n";
    }




    /*2f) Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5} and S1 = {1,2,5}. Determine whether the elements in
     S1 are equal to the elements in S.*/
    std::vector<int> ex2f{1,2,5,5,-3,4,5,5,5,6,3,4,5};
    std::vector<int> S1{1,2,5};

    auto posPairs = std::mismatch(ex2f.begin(), ex2f.end(), S1.begin(), S1.end());
    if(posPairs.second == S1.end())
    {
        std::cout << "Elemnts in two given vectors are equal. \n";
    }

    /*3. (Which Style to use?)
     Some STL algorithms use unary and binary predicates. Both predicate types return a bool. A unary predicate
     has one input argument while a binary predicate has two input arguments. We can model these predicates and
     other kinds of functions in a number of ways:
      User-defined function objects.
      Predefined STL function objects (for example, std::multiplies<T>()).
      Using lambda functions (possibly with captured variables).
     Answer the following questions:
     a) Compare these three solutions with regard to quality issues such as readability, understandability and
     maintainability.*/

    /*Answer:
        User defined function objects are the objects that have overloaded () operator. That often makes it the worst in terms of understandability as it's need to be clear what the function do (so for example proper naming is important).
        Predefined STL functions are often easiest to use as the set of ready standard functions that does not need to be implemented and maintained by the users but of corse they are less changeable. As well named and documented functions they are most understandable.
        While creating some in-place function escpecially the one that should be used in some STL algortihm the good choice is to create anonymous lambda function (in-place as algorithm's param or assinged to auto variable) but using such function in place may decrease the general readability.
     */

    /*3b) Consider transforming a vector of integers into a set of integers. Only those elements whose absolute value
    is strictly greater than a given threshold value should appear in the destination. An example is the vector
    {1,2,1,4,5,5,-1}. If the threshold value is 2 then the output set will be {4,5}. Implement this problem using
    the three bespoke methods above.*/

    std::set<int> output3b;
    std::vector<int> ex3b{1,2,1,4,5,5,-1};
    constexpr int treshold = 0U;

    std::copy_if(ex3b.begin(), ex3b.end(), std::inserter(output3b, output3b.begin()), [treshold](int input){
        return input > treshold;
    });

    if(output3b.begin() != output3b.end())
    {
        std::cout << "The result of transforming vector {1,2,1,4,5,5,-1} which threshold value: " << std::to_string(treshold) << " is:\n";
        for(auto el : output3b)
        {
            std::cout << std::to_string(el) << "\n";
        }
    }

    return 0;
}

