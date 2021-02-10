#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structdef.h"
//Function declaration
int isFileExists(const char *path);
void init();
void printMessageCenter();
void headMessage (const char *message);
void welcomeMessage();
int isNameValid(const char *name);
//Function start
int isNameValid(const char *name) {
	int validName = TRUE;
	int len = 0;
	int index = 0;
	len = strlen (name);
	while (index < len) {
		if (!(isalpha(name [index])) && (name[index] != '\n') && (name[index] != ' ') ) {
			validName = FALSE;
			break;
		}
	}
	return validName;
}

void welcomeMessage() {
	headMessage("Tommy LMS");
	   headMessage("www.aticleworld.com");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

void headMessage (const char *message) {
	system("cls");
	 printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void printMessageCenter (const char * message) {
	int len = 0;
	int pos = 0;

	//Calculate how many space need to print 
	len = (78 - strlen(message)) /2;
	printf("\t\t\t");
	while(pos < len) {
		//Print space
		printf(" ");
		++ pos;
	}
	//print message
	printf("%s", message);
}

void init() {
	FILE *fp = NULL;
	int status  = 0;
	//Username and password
	const char defaultID[] = "Tommy";
	const char defaultPassword[] = "Tommy";

	sFileHeader fileHeaderInfo = {0};

	status = isFileExists(FILE_NAME);
	if(!status) {
		//Create the binary file
		fp = fopen(FILE_NAME,"wb");
		if(fp != NULL) {
			//Copy defaultPassword
			strncpy(fileHeaderInfo.password, defaultPassword; sizeof(defaultPassword));
			strncpy(fileHeaderInfo.ID, defaultID, sizeof(defaultID));
			fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
			fclose(fp);
		} 
	}
}

int isFileExists(const char *path) {
	//Try to open file
	FILE *fp = fopen(path, "rb");
	int status = 0;
	
	//If file doesn't exist
	if(fp != NULL) {
		status = 1;
		// File exists hence close file
		fclose (fp);
	}
}
