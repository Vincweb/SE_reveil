#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	int HEURES;
	char *option[3];
	
	option[0] = "date";
	option[1] = "+%H:%M:%S";
	option[2] = NULL;
	
	HEURES = fork();

	if(HEURES == 0)	execv("/bin/date", option);
	else
	{
		sleep(1);
		execv("reveil_entr",NULL);
	}
	exit(0);

}
