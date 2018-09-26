/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on September 25, 2018, 5:31 PM
 * Project: Selection Sort Algorithm
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Function Declarations */
void selectionSort(int[100000], int);
void printArray(int[100000], int);

int main(int argc, char** argv) {
    srand(time(0));
    unsigned int arraySize = 100000;
    int initialArray[arraySize] = {0};
    
    for(int i = 0; i < arraySize; i++){
        initialArray[i] = rand() % 100000;
    }
//    printArray(initialArray, arraySize);
    
    time_t start = time(0);
    selectionSort(initialArray, arraySize);
    time_t end = time(0);
    double time = difftime(end, start);
    
//    printArray(initialArray, arraySize);
    
    cout << "Selection Sort: Sorting " << arraySize << " random elements." << endl;
    cout << "Time: " << time << " seconds" << endl;
    return 0;
}

void selectionSort(int array[100000], int size){
    int min = array[0];
    int index = 0;
    
    for(int i = 0; i < size; i++){
        min = array[i];
        for(int j = (i + 1); j < size; j++){
            if(array[j] < min){
                min = array[j];
                index = j;
            }
        }
        if(min < array[i]){
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
}

void printArray(int array[100000], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}