#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char *argv[])
{
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
}
