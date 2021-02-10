#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Preprocessor
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_ID 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "Tommybookslibs.bin"
// Macro related to the books info
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)

// struct to store date
typedef struct {
	int yyyy;
	int mm;
	int dd;
} Date;

typedef struct {
	char ID {MAX_SIZE_ID};
	char password{MAX_SIZE_PASSWORD};
} sFileHeader;

typedef struct {
	unsigned int book_id; //Declare the interger data
	char bookName {MAX_BOOK_NAME};
	char authorName {MAX_AUTHOR_NAME};
	char studentName {MAX_STUDENT_NAME};
	char studentAddr{MAX_STUDENT_ADDRESS};
	Date bookIssueDate;
} s_BooksInfo;

//bool declaration
typedef enum bool {FALSE, TRUE} bool;

//Function declaration
int isFileExists(const char *path);
void init();
void printMessageCenter();
void headMessage (const char *message);
void welcomeMessage();
int isNameValid(const char *name);
int isLeap(int year);
int isValidDate (Date *validDate);
void menu();
//Function 
void menu() {
	int choice = 0;
	do {
		headMessage("Main Menu");
		printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				addBookInDB();
				break;
			case 2:
				searchBooks();
				break;
			case 3: 
				viewBooks();
				break;
			case 4:
				deleteBooks();
				break;
			case 5:
				updateCredential();
				break;
			case 0:
				printf("\n\n\n\t\t\t\tThank you !!\n\n\n\n\n");
				exit(TRUE);
				break;
			default: 
				    printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
		}
	}
	while(choice != 0);
}
int isValidDate (Date *validDate) {
	//check range of year, month and day
	if (validDate -> yyyy > MAX_YR || validDate -> yyyy < MIN_YR) {
		return  FALSE;
	}
	if (validDate->mm < 1 || validDate->mm > 12)
        return FALSE;
    if (validDate->dd < 1 || validDate->dd > 31)
        return FALSE;
	// Handle feb days in leap year
	if (validDate -> mm == 2) {
		if (isLeap(validDate -> yyyy)) {
			return (validDate -> dd <= 29);
		} else
			return (validDate -> dd <=28);
	}
	//handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return TRUE;
}

int isLeap(int year) {
	return ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

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
    getc();
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
	int status = FALSE;
	
	//If file doesn't exist
	if(fp != NULL) {
		status = TRUE;
		// File exists hence close file
		fclose (fp);
	}
}
