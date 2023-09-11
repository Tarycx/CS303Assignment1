#pragma once
#include <iostream>
using namespace std;




int mainMenu();

void readFileToArry(int numArray[], int arrLength);

void checkValue(int numArray[], int arraySize); //f1

void changeValue(int numArray[], int arraySize); //f2

void appendValue(int numArray[], int newSize); //f3

void copyNewArray(int numArray[], int newSize); //f3

void deleteValue(int numArray[], int newSize);//f4

void printArray(int numArray[], int arraySize); //FixMe