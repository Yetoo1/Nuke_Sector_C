#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char *argv[])
{
	/*
	int isCaseInsensitive = 0; //0 false, 1 is true
	int opt;
	enum { CHARACTER_MODE, VERBOSE_MODE, VERSION_MODE, DEMIGOD_MODE, GOD_MODE, INTERDIP_MODE, MAXCHAOS_MODE, BEYONDCHAOSI_MODE } mode = CHARACTER_MODE; //wait shit, not all these should be here since multiple of these could be at once, mode means that the program is going to be working in it, having multiple means that there needs to be boolean but this is mode soi that's not the best option, could bhe done though, though very shitty result
	while ((opt=getopt(argc, argv, "v")) != -1) 
	{
		switch(opt)
		{
			case 'v': mode = VERBOSE_MODE; break;
			case 'V': break;
			default:
				fprintf(stderr, "Usage: %s [-v]", argv[0]);
				exit(EXIT_FAILURE);

		}
	}
	*/
	initscr();
	noecho();
	curs_set(FALSE);
	refresh();
	int open;
	srand(time(NULL)); //starts the instance of random
	/* The arrays that store shit starts here */
	char sectorletter[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //will need to convert to string
	/* The arrays that store shit ends here */
	int sectoramnt = rand() % 100 + 1; //sectoramnt equals a random number from 1 to 100 (verify on that) 
	printw("Sectors:\n");
	/* THE LOOP THAT PUTS VARIABLES INTO THE INDEX STARTS HERE */
	int i;
	for (i = 0; i < sectoramnt; i++) //for loop iterates for whatever number of times defined by sectoramnt
	{
		int sector = rand() % 100 + 1; //sector equals a random number from 1 to 100 (verify on that)
		char sectorts[3];
		sprintf(sectorts, "%d", sector);
		//char sectorwl 
	}
	while ((open = getch()) != 'q')
	{
		
		//printw("%c\n",open);
		//break;
	}
	refresh();
	endwin();
}
