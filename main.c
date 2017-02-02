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
	int L = 2; //L for letter, 2 because of the letter and the trailing null terminator
	int N = 4; //N for number, 4 because of the possibility of three and the trailing null terminator
	char *sectorindex[sectoramnt];
	char *sectorletter[26] =  {"A","B","C","D","E","F","G","H","I","J","K", "L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}; //this is the array that is supposed to hold the predefined letters that sectors will contain 
	char *sepli[sectoramnt]; //separated letter index, each position in this tells which number should go where
	char *sepni[sectoramnt]; //separated number index, each position in this tells which shoudl go where and such 
	char *seplt = malloc(L * sizeof(char)); //sep letter temp
	char *sepnt = malloc(N * sizeof(char)); //sep number temp
	char *tmp;
	int lp[sectoramnt];
	int lps = (int)(sizeof(lp)/sizeof(lp[0]));
	int i;
	int k;
	printf("Sectors:\n");
	/* THE LOOP THAT PUTS ITEMS INTO THE INDEX STARTS HERE */	
	for (i = 0; i < sectoramnt; i++) //for loop iterates for whatever number of times defined by sectoramnt
	{
		int sector = rand() % 100 + 1; //sector equals a random number from 1 to 100 (verify on that)
					       //now yes ideally there would be another for loop above this that puts all the sectors into an array and down here all it does is concayenate
		asprintf(&sectorindex[i], "%s%d", sectorletter[rand()%26+0], sector); //this took me for fucking ever to figure this out
										      //however if we want to sort, we are going to need to take this apart
										      //we need to take it apart each time, because I'm not going to store separate arrays or multidimensional arrays that tell where each letter is, i just want arrays that have the letter, i always want this shit to look modular 
										      //also incase you think there should be variables here that could makes this go faster and not go directly to the sector index, it would only make it faster for this instance since we are creating the variables to put into the array, but we want this to happen multiple times so we need to make this modular, maybe i'm using faster wrong but just less yeah
		//printf("%s ", sectorindex[i]); //this needs to get sorted ALSO PLEASE NOTE THAT SECTORLETTER IS GETTING A NEW LETTER EVERY ITERATION
		//printf("\n");
		/*The number and letter both need to be separated because we need to keep track of both to sort the sectorindex*/
		/*---separates letter---*/
		strncpy(seplt, sectorindex[i], L-1); //FOR FUCKS SAKE! STRNCPY APPARENTLY ALWAYS PUTS CHARACTERS NO MATTER FUCKING WHAT THOSE PIECE OF SHIT COMMIES MADE THAT COMMAND AND MAN FUCKING POAGES THE HARDEST FUCKING THING TO UNDERSTAND SINCE IT 8IS SO FUCKI NG VAGUE THIS DUDE ON STAKC OVERFLOW DESERVES 100 SEX OF ANY KIND OF CHOOSING JESSSSUS http://stackoverflow.com/questions/14065391/strncpy-leading-to-segmentation-fault
		seplt[L-1] = 0;
		sepli[i] = seplt;
		/*---separates number---*/
		strncpy(sepnt, &sectorindex[i][1], N-1); //&index[i][1] means that from the first letter of the item in the current iteration, it's going to copy the contents 
		sepnt[N-1] = 0;
		sepni[i] = sepnt;
		//printf("Letter: %s Number: %s\n\n", sepli[i], sepni[i]);
		//first keep track of the index with letters
		for (k = 0; k < 27; k++) //26  becuase the current iteration is the value in the index minus 1 which is then proper, 25 is the position of 26
		{
			//what is the the fucking 4reaosn why i have have a headache it is bvery annoying how i have a headachw evry day of my fuckin g luife, will the pain ever go  away in a split second of wonder i wonde rwhat the possibilties are, such an answr would vch nafge the outcome for me indefinitely, unintentionally, but no matter, i will always wonder, it will always be a queastion of supreme unknown, i wish i could find that, but it will not happen, i am the victim, or at least that's what i hope, probably im  the perpetuiator, that's how this type of shit works, but that's no matter because I have 2wonderful capabilities capailitie sgreater than all, greater than me, greater than i, not greater than you, becauswe you are arbituary, i am absolute, but that's like, could you know? i wish i could holsd the answers, but they are so dear to someone in me, it makes me sad that such a person would withhold that from another. It could all bhe a n elaborate trap keeping myself from blame, maybe it;'s not even myself, and its yourself that the one at question. it make stno sense once you come to conclusion. but i digress, all i want  is appeal, maybe i jus tweant to get along so that there is no more asnnoying fights, because thos efightr s make me sad, that's another lie, they make me annoyed.
			if (strcmp(sepli[i], sectorletter[k]) == 0) //checks for position in letters
			{
				printf("Your verification:  Sector: %s Letter: %d Iteration of separation: %d\n",sectorindex[i], k, i);
				lp[i] = k;
			}
		}
		printf("\n");
		//then keep track of the index with numbers
		//<start sorting of>
		//sort(sectorindex[i]);//, sectoramnt);
		//REMEMBER UNDEFINED BEHAVIOR IS BECAUSE YOU ARE WRITING BEYOND THE ALLOCATED SPACE HOLY FUCK WAS IT THAT HARD TO FIND AN ANSWER JESUS
	}
	for (i = 0; i < lps; i++)
	{
		printf("In: %s\n", sectorindex[i]);
		for (k = 0; k < lps; k++)
		{
			if (lp[i] > lp[k+1])
			{
				tmp = sectorindex[i];
				sectorindex[i] = sectorindex[k+1];
				sectorindex[k+1] = tmp;
			}
		}
		printf("\nOut #%d: %s\n", k, sectorindex[k]);
	}
	printf("\n");
	for (i = 0; i < sectoramnt; i++)
	{
		printf("%s\n", sectorindex[i]);
	}
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
