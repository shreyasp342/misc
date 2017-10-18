// You walk into a bar trying to find someone. You ask person 0 about them, but he tells you to ask another person (a person between 0 and 5000), who then tells you to ask another person. Soon you realize that you are going in a loop of asking the same person. Write a program to figure out how may people are involved once you land in a loop. The loop does not necessarily involve the first person you ask.

// Write a function that takes an array of integers X , and proceeding at each step to the value Y = X[0] , proceed to X[Y]. Find the length of the loop once a loop is detected.

// Use any language you like. 

#include <stdio.h>
#include <stdlib.h>

int loopLength(int X[], int N){
	int *counter = (int *) calloc (N,sizeof(int));
	for(int i = 0; i < N; i++){
		if(counter[X[i]] != 0){
			int length = (i+1) - counter[X[i]];
			free(counter);
			return length;
		}
		counter[X[i]] = i+1;
	}
}

int main(){
	int X[5000];
	for(int i = 0; i < 5000; i++) X[i] = rand() % 5000 + 1;
	int N = sizeof(X) / sizeof(X[0]);
	int length = loopLength(X, N);
	printf("length of the loop is %d\n", length);
}