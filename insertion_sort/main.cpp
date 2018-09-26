/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on September 24, 2018, 8:57 PM
 * Project: Insertion Sort Algorithm
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Function Declarations */
void printArray(int[100000], int);
void insertionSort(int[100000], int);

int main(int argc, char** argv) {
    srand(time(0));
    int arraySize = 100000;
    int initialArray[arraySize] = {0};
    
    for(int i = 0; i < arraySize; i++){
        initialArray[i] = rand() % 100000;
    }
//    printArray(initialArray, arraySize);
    
    time_t start = time(0);
    insertionSort(initialArray, arraySize);
    time_t end = time(0);
    double time = difftime(end, start);
    
//    printArray(initialArray, arraySize);
    
    cout << "Insertion Sort: Sorting " << arraySize << " random elements." << endl;
    cout << "Time: " << time << " seconds" << endl;
    
    return 0;
}

void insertionSort(int array[100000], int size){
    int marker = 1;
    int i = marker - 1;
    while(marker < size){
        if(array[marker] < array[i]){
            int temp = array[marker];
            array[marker] = array[i];
            array[i] = temp;
            
            if(i >= 1){
                int top = i;
                int bottom = top - 1;
                while(bottom >= 0){
                    if(array[top] < array[bottom]){
                        int temp2 = array[top];
                        array[top] = array[bottom];
                        array[bottom] = temp2;
                        top--;
                        bottom--;
                    } else {
                        break;
                    }
                }
            }
        }
        
        i++;
        marker++;
    }
}

void printArray(int array[100000], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}