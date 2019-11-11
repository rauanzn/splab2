// your code here
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]){
    
	int a = atoi(argv[1]);	
	int b = atoi(argv[2]);	
	
	pid_t ch1 = fork();
	
	if (ch1 == 0) {
		printf("child1: %d+%d=%d \n", a, b, a + b);
		exit(0);
	}    
	pid_t ch2 = fork();
	
	if (ch2 == 0) {
		printf("child2: %d*%d=%d \n", a, b, a * b);
		exit(0);
	} 
	pid_t ch3 = fork();

	if (ch3 == 0) {
		printf("child3: %d-%d=%d \n", a, b, a - b);
		exit(0);
	}    

	pid_t ch4 = fork();
	
	if (ch4 == 0) {
		printf("child4: %d/%d=%d \n", a, b, a / b);
		exit(0);
	} 
    	waitpid(ch1, NULL, 0);
    	waitpid(ch2, NULL, 0);
    	waitpid(ch3, NULL, 0);
    	waitpid(ch4, NULL, 0);

	printf("parent: done.\n");
}
