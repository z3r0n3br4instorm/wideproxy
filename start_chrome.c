#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *file;
	file = fopen("launch_chrome.zttf","r");
	if (file == NULL){
		printf("An error occured while Trying to access the file...\n");
		return 1;
	}
	char buffer[1024];
	while(fgets(buffer, sizeof(buffer), file) != NULL){
		printf("%s",buffer);
	}
	char command[1023];
	sprintf(command,"google-chrome --proxy-server=%s",buffer);
	system(command);
	fclose(file);
	return 0;
}
