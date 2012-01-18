#include <stdio.h>
#include <stdlib.h>

void anagram_maker(int *stack, int head, int *count, char *anagram, int N);

int main(){

    char anagram[]={'A','B','C','D','E'};
    int N;
    int *stack;
	int count, head;
	
	/*Length of anagram*/
	N=sizeof(anagram)/sizeof(char);
	
	/*Init starting values for function call*/
	/*Stack is integer list which contains positions of characters*/
	/*Count is counter of anagrams*/
	/*Head is "help pointer" for stack but not really a pointer. It gives present position or recursion depth.*/
	stack=malloc(sizeof(int)*N);
	count=0;
	head=-1; /*stack empty*/
    
	/*I want to ephasize that this funktion is planned and made by me and no help of internetz is used :)*/
	anagram_maker(stack, head, &count, anagram, N);
	printf("\ndone\n");
	return 0;
}

/*Function basicly goes through all possible combinations of list*/
void anagram_maker(int *stack, int head, int *count, char *anagram, int N){
    int i, j, used=0;
	
    for(i=0; i<N; i++){
		
		/*Values for head + 1*/
		stack[head+1]=i;
    
    	/* check if next value is used already*/
    	for(j=0; j<=head; j++){
        	if(stack[j]==i) used=1; 
    	}
		
    	if(used == 1){ /*if next value is used do nothing, else call function again until all possible values are checked*/
        	used = 0;

    	} else {
        	if(head < N-2){ /*if stack not full*/
            	anagram_maker(stack, head+1, count, anagram, N);
    		} else { /*if stack is full then anagram is printed*/
				(*count)++; 
				printf("Number: %i, Anagram: ", *count);
            	for(j=0; j<N; j++){ 
                	printf("%c", anagram[stack[j]]);
            	}
				printf("\n");
        	}
    	}
	}
}
