#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char *p,buf[20];
	int n=shmget(12325,25,IPC_CREAT|0666); // shmget(key which uniquely identifies the shared memory segement, size of the shared memory in bytes,
					       // flag which indicates a new shared memory segment must be created if it doesnt exist already, gives read and write permission)

	if(n!=1) // Checks if the shmget() call was successful. If n is not equal to 1, it implies that the shared memory segment was successfully created or retrieved.
	{
		p=(char *)shmat(n,NULL,0); 
		/*
		 * Calls the shmat() system call to attach the shared memory segment to the address space of the calling process. It takes three arguments:
                   n: The identifier of the shared memory segment obtained from shmget().
                   NULL: The system chooses a suitable address to attach the segment.
                  0: Flags, in this case, indicates no specific behavior.
		 */
		printf("enter your data: ");
		scanf("%[^\n]s",buf); // the special specifier makes sure that scanf reads till the encounter of newline
		strcpy(p,buf);
	}
	return 0;
}
