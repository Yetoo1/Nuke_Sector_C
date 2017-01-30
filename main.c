#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
//#include <ncurses.h> This has no practical use for now
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
/* Put the below values into a struct */
//const char *sectorletter[26] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}; //this is the array that is supposed to hold the predefined letters that sectors will contain 
//const char *sectorindexn[] = {"s", "s"};
//int sort(char *sectorindex) //note that this is a single array
//{
//	printf("%s ", sectorindexn[]);
	
//}
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
	//initscr();
	//noecho();
	//curs_set(FALSE);
	//refresh();
	srand(time(NULL)); //starts the instance of random
	int sectoramnt = rand() % 100 + 1; //this is part of the problem causing the segmentation fault, the other random generator doesn't though
	int N = 2;
	char *sectorindex[sectoramnt];
	char *sectorletter[26] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}; //this is the array that is supposed to hold the predefined letters that sectors will contain 
	char *sepli[sectoramnt]; //separated letter index, each position in this tells which number should go where
	char *seplt = malloc(N * sizeof(char)); //separated letter temp
	printf("Sectors:\n");
	int i;
	/* THE LOOP THAT PUTS ITEMS INTO THE INDEX STARTS HERE */	
	for (i = 0; i < sectoramnt; i++) //for loop iterates for whatever number of times defined by sectoramnt
	{
		int sector = rand() % 100 + 1; //sector equals a random number from 1 to 100 (verify on that)
		//int sector = 3;
		asprintf(&sectorindex[i], "%s%d", sectorletter[rand()%26+0], sector); //this took me for fucking ever to figure this out
										      //however if we want to sort, we are going to need to take this apart
										      //we need to take it apart each time, because I'm not going to store separate arrays or multidimensional arrays that tell where each letter is, i just want arrays that have the letter, i always want this shit to look modular 
										      //also incase you think there should be variables here that could makes this go faster and not go directly to the sector index, it would only make it faster for this instance since we are creating the variables to put into the array, but we want this to happen multiple times so we need to make this modular, maybe i'm using faster wrong but just less yeah
		printf("%s ", sectorindex[i]); //this needs to get sorted ALSO PLEASE NOTE THAT SECTORLETTER IS GETTING A NEW LETTER EVERY ITERATION
		printf("\n");
		strncpy(seplt, sectorindex[i], N-1); //FOR FUCKS SAKE! STRNCPY APPARENTLY ALWAYS PUTS CHARACTERS NO MATTER FUCKING WHAT THOSE PIECE OF SHIT COMMIES MADE THAT COMMAND AND MAN FUCKING POAGES THE HARDEST FUCKING THING TO UNDERSTAND SINCE IT 8IS SO FUCKI NG VAGUE THIS DUDE ON STAKC OVERFLOW DESERVES 100 SEX OF ANY KIND OF CHOOSING JESSSSUS http://stackoverflow.com/questions/14065391/strncpy-leading-to-segmentation-fault
		seplt[N-1] = 0;
		sepli[i] = seplt; 
		printf("%s\n", sepli[i]);
		//sort(sectorindex[i]);//, sectoramnt);
		//try memmove, it copies to a temp so maybye that's another 1 liner
	}
	printf("\n");
	int happy = 0;
	while (happy != 1) 
	{
		printf("Which sector do you want to select?\nNOTE: You cannot select any more sectors aftere this point in this session, unless of course you choose to restart the session. (You can keep the sector that you select into the next restart but you'll be losing <insert what they'll be losing>)\n"); //make this in a loop that works
		char sectordec[5];
		fgets(sectordec, 5, stdin);
		printf("You selected sector %s\n", sectordec);	
		//for (i = 0; u < sectoramnt; i++)
		//{
		//	if (strcmp(sectordec, sectorindex[i]))
		//}
		happy = 1;	
	}	
	//char input[4];	
	//while ((open = getch()) != 'q')
	//{
	//	input[i];
		//printw("%c", input[i]);
	//	i++;	
	//printw("%c\n",open);
		//break;
	//}
	//refresh();
	//curs_set(TRUE);
	//endwin();
}
