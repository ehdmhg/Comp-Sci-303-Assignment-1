#pragma once
#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
void fillMatrix(ifstream& inFile, int arr[], int size);
void returnInd(int arr[], int size, int value);
void returnVal(int arr[], int size, int index, int newVal);
void addVal(int arr[], int &size, int max_size, int newVal);
int replaceVal(int arr[], int index, int size);