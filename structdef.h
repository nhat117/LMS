// struct to store date
typedef struct {
	int yyyy;
	int mm;
	int dd;
} Date;

typedef struct {
	char ID{MAX_SIZE_ID};
	char password{MAX_SIZE_PASSWORD};
} sFileHeader;

typedef enum bool {FALSE, TRUE} bool;