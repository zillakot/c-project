#include <stdio.h>
#define N 5

void anagram_maker(int *stack, int head, int *count, char *anagrammi);

int main(){

    char anagrammi[]={'A','B','C','C','A'};
    int count;
    int i;
    int stack[5];
    count=0;
    
	for(i=0; i<N; i++){
    	stack[0]=i;
    	anagram_maker(stack, 1, &count, anagrammi);
	}
	return 0;
}

void anagram_maker(int *stack, int head, int *count, char *anagrammi){
    int i, j, used;
    
    for(i=0; i<N; i++){
    
		stack[head+1]=i;
    
    	/* check if used*/
    	for(j=0; j<head; j++){
        	if(stack[head+1] == stack[j]) used=1; 
    	}
    
    	if(used == 1){
        used = 0;
    	} else {
    
        	if(head < N-2){
            	anagram_maker(stack, head+1 ,count, anagrammi);
        	} else {
            	
				count++;
                printf("\n%i\n,  ", *count);
            	for(j=0; j<N; j++){
                	printf("%c", anagrammi[stack[j]]);
            	}
        	}
    	}
	}
}
