#include "sort.h"

std::vector<int> sort(std::vector<int> input){
    for(int i=0;i<input.size()-1;i++){
        int minIndex = i;
        for(int j=i;j<input.size();j++){
            if(input[minIndex] > input[j])minIndex = j;
        }
        int temp = input[minIndex];
        input[minIndex] = input[i];
        input[i] = temp;
    }
    return input;
}

