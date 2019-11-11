#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]){
    
	pid_t p1 = fork();
	
	if (p1 == 0) {
		execlp("python", "python3", "CalPython.py", argv[1], argv[2], NULL);
		exit(0);
	}    
	pid_t p2 = fork();
	
	if (p2 == 0) {
		execlp("java", "java", "CalJava", argv[1], argv[2], NULL);
		exit(0);
	} 
	pid_t p3 = fork();

	if (p3 == 0) {
		execlp("nodejs", "nodejs", "CalNodeJs.js", argv[1], argv[2], NULL);
		exit(0);
	}    

	pid_t p4 = fork();
	
	if (p4 == 0) {
		execlp("bash", "bash", "CalBash.sh", argv[1], argv[2], NULL);
		exit(0);
	} 
    	waitpid(p1, NULL, 0);
    	waitpid(p2, NULL, 0);
    	waitpid(p3, NULL, 0);
    	waitpid(p4, NULL, 0);
	printf("parent: done.\n");


}
