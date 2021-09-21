#include "Node.h"
#include "Radix-Sort-Object.h" 
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int get_max_key(Node** nodes_array, int length){
    int max = nodes_array[0]->get_key();
    for(int i = 0; i < length; i++){
        if(max < nodes_array[i]->get_key()){
            max = nodes_array[i]->get_key();
        }
    }
    return max;
}

void radix_sort_key_digits(Node** nodes_array, int length, int digit){
    vector<vector<Node*>> sorted;
    sorted.resize(10); //assume key in base 10 -> the max input value
    for(int i = 0 ; i < length; i++){
        sorted.at((int)(nodes_array[i]->get_key() / pow(10, digit)) % 10).push_back(nodes_array[i]);
    }
    int index = 0;
    Node** output = new Node*[length];
    while(index < length){
        for(int i = 0; i < sorted.size(); i++){
            for(int j = 0; j < sorted.at(i).size(); j++){
                output[index] = sorted.at(i).at(j);
                index++;
            }
        }
    }
    for(int i = length-1; i >= 0; i--){
        nodes_array[i] = output[i];
    }
}

void radix_sort_object(Node** nodes_array, int length){
    for(int i = 0; (int)(get_max_key(nodes_array, length) / pow(10, i)) > 0; i++){
        radix_sort_key_digits(nodes_array, length, i);
    }
}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node** array = new Node*[4];
    array[1] = first;
    array[0] = second;
    array[3] = third;
    array[2] = fourth;
    radix_sort_object(array, 4);
    for(int i = 0; i < 4; i++){
        std::cout << array[i]->get_key() << " ";
    }
    std::cout << endl;
    return 0;
}
