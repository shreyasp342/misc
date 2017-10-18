// Question 1
// Fizzbuzz!
// Please write a function that iterates from 1 to 100. 
// When the number is evenly divisible by 5, it writes “fizz.” 
// When the number is evenly divisible by 6, it writes “buzz.” 
// When the number is evenly divisible by both, it writes “fizzbuzz.” 
// Otherwise, it writes out the number. 

// Use any language you like.

#include <stdio.h>

void fizzBuzz(){
	for(int i = 1; i <= 100; i++){
		if((i % 5) == 0){
			if((i % 6) == 0) printf("fizzbuzz.\n");
			else printf("fizz.\n");
		}else if((i % 6) == 0) printf("buzz.\n");
	}
}

int main(){
	fizzBuzz();
}
