#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "float.h"

/*
Knapsack problem
– You have a set of products with a given weight and value. Suppose you have a knapsack
(suitcase) that can hold N pounds, which subset of objects can you pack that maximizes the
value.
– Example:
• Knapsack can hold 35 pounds
• Product A: 7 pounds, $12 ea. Product B: 10 pounds, $18 ea.
• Product C: 4 pounds, $7 ea. Product D: 2.4 pounds, $4 ea.
*/

void knapsackSolver(const std::map<char, std::pair<double, int> >& options, double weight);
void knapsackHelper(const std::map<char, std::pair<double, int> >& options, 
                    std::string curr, 
                    std::string& maxChoice, 
                    int& maxMoney, 
                    double weightLeft,
                    double minWeight);

void knapsackSolver(const std::map<char, std::pair<double, int> >& options, double weight)
{
    std::string maxChoice = "";
    int maxMoney = 0;
    double minWeight = DBL_MAX;
    for(const auto& w : options)
    {
        if(w.second.first < minWeight)
        {
            minWeight = w.second.first;
        }
    }
    knapsackHelper(options, "", maxChoice, maxMoney, weight, minWeight);
    std::cout << "The maximum money you can get is: " << maxMoney << "\n" << "The according load is: " << maxChoice << std::endl;
}

void knapsackHelper(const std::map<char, std::pair<double, int> >& options, 
                    std::string curr, 
                    std::string& maxChoice, 
                    int& maxMoney, 
                    double weightLeft,
                    double minWeight)
{
    // base case
    if(weightLeft < minWeight)
    {
        // calculate current $
        int money = 0;
        for(auto c : curr)
        {
           money += options.find(c)->second.second;
        }
        if(money > maxMoney)
        {
            maxMoney = money;
            maxChoice = curr;
        }
        return;
    }
    // backtracking search
    for(const auto& choice : options)
    {
        // we load the item only if it weight fits and has not been previously loaded
       if(weightLeft > choice.second.first)
       {
        // load this one
        curr = curr + choice.first;
        weightLeft -= choice.second.first;
        knapsackHelper(options, curr, maxChoice, maxMoney, weightLeft, minWeight);
        curr = curr.substr(0, curr.length()-1);
        weightLeft += choice.second.first;
       } 
    }
}

int main()
{
    std::map<char, std::pair<double, int> > options;
    options['a'] = std::make_pair(7.0, 12);
    options['b'] = std::make_pair(10.0, 18);
    options['c'] = std::make_pair(4.0, 7);
    options['d'] = std::make_pair(2.4, 4);
    knapsackSolver(options, 35);
    return 0;
}