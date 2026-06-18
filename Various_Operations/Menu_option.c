#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main()
{
	int done;
  char ch;
			
	/* main program loop */
	done = FALSE;
	while(!done)
	{
		printf("Command: ");
		scanf("%c",&ch);
		switch( ch )
		{
			case 'R':
			case 'r':
				printf("Move right");
				break;
			case 'L':
			case 'l':
				printf("Move left");
				break;
			case 'B':
			case 'b':
				printf("Move back");
				break;
			case 'Q':
			case 'q':
				done = TRUE;
				printf("Goodbye!");
				break;
			case 'H':
			case 'h':
			case '?':
				printf("To go Right type (R), for left (L), or for back (B) Or you can type (Q) for quit");
				break;
			default:
				printf("Invalid Input!");
		}
		while( (ch=getchar()) !='\n' )
			;
	}

	return 0;
}
