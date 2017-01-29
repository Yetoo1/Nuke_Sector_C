#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
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
	//char sectorletter[26] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}; //this is the array that is supposed to hold the predefined letters that sectors will contain 
	/* The arrays that store shit ends here */
	int sectoramnt = rand() % 100 + 1; //sectoramnt equals a random number from 1 to 100 (verify on that) 
	printw("Sectors:\n");
	/* THE LOOP THAT PUTS VARIABLES INTO THE INDEX STARTS HERE */
	int i;
	for (i = 0; i < sectoramnt; i++) //for loop iterates for whatever number of times defined by sectoramnt
	{
		//for some reason this part outputs garbled characters with some versions of gcc, the one on my laptop works though
		int sector = rand() % 100 + 1; //sector equals a random number from 1 to 100 (verify on that)
		char sectorts[3];
		char sectorlc[3]; //converted letter
		char *sectorln; //sector with number and letter
		sprintf(sectorts, "%d", sector); //converts the sector number to string
		sectorlc[0] = sectorletter[rand()%26+0] + '\0';//make the zero position the char that's converted
		asprintf(&sectorln, "%s%s", sectorlc, sectorts);
		//memcpy(sectorwl, sectorletter[rand()%26+0], 1);
		//printf("%s\n", sectorletter);
		//char sectorwl = sectorletter[rand()%26+0] 
		printw("%s ", sectorln);
	}
	printw("\n");
	int happy = 0;
	//while (happy == 0)
	//{
	printw("Which sector do you want to select?\nNOTE: You cannot select any more sectors aftere this point in this session, unless of course you choose to restart the session. (You can keep the sector that you select into the next restart but you'll be losing <insert what they'll be losing>)\n"); //make this in a loop that works
	char input[4];	
	while ((open = getch()) != 'q')
	{
		input[i];
		//printw("%c", input[i]);
		i++;	
	//printw("%c\n",open);
		//break;
	}
	refresh();
	curs_set(TRUE);
	endwin();
}
