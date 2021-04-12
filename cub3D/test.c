#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int main()
{
	pid_t proc;
	int i = 0;
	int ret;
	int error = 0;
	char *argv[3];
	argv[0] = "test_map.cub";
	argv[1] = "test_map.cub";
	argv[2] = NULL;
	proc = 123;
	while (i < 100)
	{
		if (proc != 0)
			proc = fork();
		printf ("pid = %d\n", proc);
		if (proc == 0)
		{
			// error = system("./cub3D test_map.cub");
			error = execve("./cub3D",argv, NULL);
			if (error < 1)
				printf("error happened\n");
			// kill(proc , SIGINT);
			exit(0);
		}
		else if (proc > 0)
		{
			printf ("i am goint to kill %d\n", proc);
			sleep(1);
			// ret = waitpid(-1, 0, WNOHANG);
			kill(proc, SIGTERM);
			printf ("i killed %d\n", proc);
		}
		i++;
	}
	return (0);
}