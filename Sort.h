#pragma once
#include"dataGenerator.h"
using namespace std; 
void bubbleSort(int a[], int n);
void shakerSort(int a[], int n);

void selectionSort(int a[], int n);
void insertionSort(int a[], int n);

int partition(int a[], int first, int last);
void quickSort(int a[], int first, int last);

void heapRebuild(int a[], int pos, int n);
void heapConstruct(int a, int n);
void heapSort(int a[], int n);


void merge(int a[], int first, int mid, int last);
void mergeSort(int a[], int first, int last);

void shellSort(int a[], int n);

int binarySearch(int a[], int first, int mid, int last);
void binaryInsertionSort(int a[], int n);

void countingSort(int a[], int n);
void radixSort(int a[], int n);
void flashSort(int a[], int n);