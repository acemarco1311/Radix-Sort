#ifndef RADIXSORTOBJECT_H
#define RADIXSORTOBJECT_H
#include "Node.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

int get_max_key(Node** nodes_array, int length);
void radix_sort_key_digit(Node** nodes_array, int length, int digit);
void radix_sort_object(Node** nodes_array, int length);

#endif
