#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int h,H,M,m,s,S;
	H = atoi(argv[1]);
	M = atoi(argv[2]);
	S = atoi(argv[3]);
	h = atoi(argv[4]);
	m = atoi(argv[5]);
	s = atoi(argv[6]);

	int temps;

	temps = (h-H)*3600+(m-M)*60+(s-S); 
	printf("%d %d %d %d %d %d", H, h, M, m, S, s);
	printf("==== Alarme dans %d ====\n", temps);
	sleep(temps); 
	printf("==== REVEIL TOI ====");
	return 0;
}