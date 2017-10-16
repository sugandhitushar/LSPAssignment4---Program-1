#include"program.h"

void *ThreadProc(void *args)
{
	printf("Inside ThreadProc\n");
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1;
	int ret;
	
	ret = pthread_create(&thread1, NULL, ThreadProc, NULL);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	printf("Thread created.\n");	
	
	pthread_join(thread1,NULL);
	printf("Thread terminated.\n");
	
	pthread_exit(NULL);
	return 0;
}

