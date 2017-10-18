// A train has a given number of cars and a given number of passengers. Write a program that evenly distributes people between the cars, and then tells you how many cars there are with an equal number of passengers. The train is represented by an array, with each value being the number of people in the car. 
	// You may only move 1 person at a time – in other words, choose 2 elements of the array, x[i] and x[j] (I distinct from j) and simultaneously increment x[i] by 1 and decrement x[j] by
// 1.	Your goal is to get as many elements of the array to have an equal value as you can.
// For example, if the array was [ 1,4,1] you could perform the opertions as follows: Send someone from the 1st car to the 0th: increment x[0], decrement x[1], resulting in [2,2,2]. The answer in this case would be 3. 
	// Not that if the array was [1,2] , the maximum possible number of equal elements we could get is 1, as the cars could never have the same number of people in them. The number of cars in the train is at least 2, and no more than 100. Each car can hold at most 1,000,000 people. 
	// Write a program that takes the array of integers x and returns the maximum number of equal array elements that we can get, by doing the above described command as many times as needed. 
	// Use any language you like. 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int redistribution(int X[], int N){
	int sum = 0;
	for(int i = 0; i < N; i++) sum += X[i];
	int average = sum / N;

	while(true){
		int max = X[1];
		int min = X[1];
		int maxpos = 0;
		int minpos = 0;
		for(int i = 0; i < N; i++){
			if(max <= X[i]){
				max = X[i];
				maxpos = i;
			}
			if(min >= X[i]){
				min = X[i];
				minpos = i;
			}
		}
		X[minpos]++;
		X[maxpos]--;
		if(min == average && max == average+1) break;
	}

	int a = 0, b = 0;
	for(int i = 0; i< N; i++){
		if(X[i] == average) a++;
		else b++;
	} 

	return a>b?a:b;
}

int main(){
	int X[100];
	for(int i = 0; i < 100; i++) X[i] = rand() % 1000000 + 1;
	int N = sizeof(X) / sizeof(X[0]);
	int length = redistribution(X, N);
	
	printf("maximum number of equal array elements is %d\n", length);
}