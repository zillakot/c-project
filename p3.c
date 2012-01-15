#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
    if ( argc != 3 ) /* argc should be 2 for correct execution */
	{
		printf("Wrong amount of commandline parameters");
    }
    else 
    {
        /* We assume argv[1] is a filename to open*/
        FILE *file = fopen( argv[1], "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
			int x;
			int N = atoi(argv[2]);
			int count=0;
			char *buf;
			
			printf("Length of line is: %i\n", N);
			
			buf = malloc((N+1)*sizeof(char));
			if(buf == NULL) {
				printf("mem alloc failed");
				exit(1);
			}
            /* read one character at a time from file, stopping at EOF, which
               indicates the end of the file.  Note that the idiom of "assign
               to a variable, check the value" used below works because
               the assignment statement evaluates to the value assigned. */
            while  ( ( x = fgetc( file ) ) != EOF ){
				if(count==N){
					while ( isspace(x) == 0){
						ungetc( x, file );
						count--;
						x=buf[count];
						if (count == 1) break;
					}
					buf[count]='\0';
					printf(buf);
					printf("\n");
					count=0;
					continue;	
				} else {
					if(isspace(x)) x = ' ';
					buf[count]=x;
					count++;
				}
				
				
            }
            fclose( file );

			if(count!=0){
				buf[count]='\0';
				printf(buf);
				printf("\n");
			}
			
        }
    }
	return 0;
}