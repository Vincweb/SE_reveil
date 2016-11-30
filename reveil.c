#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
	time_t secondes;
   	struct tm instant;

    	time(&secondes);
    	instant=*localtime(&secondes);
	
	char hour[3], min[3], sec[3];
	sprintf(hour, "%d",instant.tm_hour);
    sprintf(min, "%d",instant.tm_min);
  	sprintf(sec, "%d",instant.tm_sec);

	char *argv[8];
	argv[0] = "reveil_alarm";
	argv[1] = hour;
	argv[2] = min;
	argv[3] = sec;
	argv[7] = NULL;

	printf("\n\n==== Bienvenue sur dans le reveil ====\n\n");

	printf("Il est %s:%d:%d\n\n ", hour, instant.tm_min, instant.tm_sec);
	
	printf("Saisir une heure de réveil :\n ");
	printf("Saisir l\'heure : ");
    scanf("%s", hour);
    printf("Saisir la minute  : ");
    scanf("%s", min);
    printf("Saisir la seconde : ");
    scanf("%s", sec);

	argv[4] = hour;
	argv[5] = min;
	argv[6] = sec;
	printf("%s\n", argv[1]);
	printf("%s\n", argv[4]);	
	
	int E, A;

	A = fork();	

	if(A == 0)
	{
		E = fork();
		if(E == 0)
		{
			execv("reveil_alarm", argv);
		}
		else
		{
			execv("reveil_entr", NULL);
		}
	}
	wait(NULL);
	return 0;
}
