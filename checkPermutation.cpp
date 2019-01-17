//
//  checkPermutation.cpp
//  checkPermutation
//
//  Created by Louie Shi on 5/29/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

hi

using namespace std;

bool checkPermutationSort(string str1, string str2)
{
    if(str1.size() != str2.size())
    {
        return false;
    }
    else
    {
        sort(str1.begin(), str1.end()); //Sorts in place
        sort(str2.begin(), str2.end()); //Sorts in place
    
        return (str1.compare(str2) == 0);
    }
}

bool checkPermutationCounting(string str1, string str2)
{
    int characterCount[128];
    
    for(int i = 0; i < 128; i++)    //Remove random numbers from the array. Zero out the array.
    {
        characterCount[i] = 0;
    }
    
    if(str1.size() != str2.size())
    {
        return false;
    }
    
    for(char c:str1)
    {
        characterCount[c]++;
    }
    
    for(char c:str2)
    {
        characterCount[c]--;
        if(characterCount[c] < 0)
        {
            return false;
        }
    }
    
    return true; //temp
}

int main(int argc, const char * argv[]) {
    
    string s1 = "hello";
    string s2 = "lloeh";
    
    cout << "checkPermutationSort: " << checkPermutationSort(s1, s2) << endl;
    cout << "checkPermutationCounting: " << checkPermutationCounting(s1, s2) << endl;
    
    return 0;
}
