#ifndef RADIXSORT_H
#define RADIXSORT_H
#include "Node.h"
#include "Counting-Sort.h"
#include "Radix-Sort.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;


void counting_sort_digit(int* input_array, int input_length, int digit){
    //this function will sort input_array base on the location of digit
    //assume that the input is in base 10 as decimals
    int* counter_array = new int[10];
    for(int i = 0; i < 10; i++){
        counter_array[i] = 0;
    }
    for(int i = 0; i < input_length; i++){
        counter_array[(int)(input_array[i] / pow(10,digit)) % 10] += 1;
    }
    //improve counter_array 
    for(int i = 1; i < 10; i++){
        counter_array[i] = counter_array[i] + counter_array[i-1];
    }
    int* output = new int[input_length+1];
    for(int i = input_length-1; i >= 0; i--){
        output[counter_array[(int)(input_array[i] /  pow(10, digit)) % 10]] = input_array[i];
        counter_array[(int)(input_array[i] / pow(10,digit)) % 10]--;
    }

    for(int i = 0; i < input_length + 1; i++){
        std::cout << output[i] << " ";
    }
    std::cout << endl;

    for(int i = 0; i < input_length; i++){
        input_array[i] = output[i+1];
    }
}

void radix_sort(int* input_array, int input_length){
    for(int i = 0; (get_max(input_array, input_length) / (int)pow(10, i)) > 0; i++){
        counting_sort_digit(input_array, input_length, i);
    }
}

int main(){
    int* array = new int[4];
    int length = 4; 
    array[0] = 2342;
    array[1] = 545; 
    array[2] = 234;
    array[3] = 102;
    radix_sort(array, length);
    for (int i = 0; i < length ; i++){
        std::cout << array[i] << "  " ;
    }
    return 0; 
}
#endif
