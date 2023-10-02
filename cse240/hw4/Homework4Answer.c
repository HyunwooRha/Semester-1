// CSE240 Spring 2023 HW4
// Hyunwoo Rha

// Reminder that your file name is incredibly important. Please review the Specification document for correct naming conventions
// Reminder that we are compiling on Gradescope using GCC. 

// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of tilesets and levels like you'd see in a folder.
// The struct 'tileset' holds information of one tileset. Variety is an enum.
// Each tileset has this information: the name, variety, and a unique ID.
// The struct 'level' holds information of one level.
// Each level has this information: the name, ID of the used tileset, unique ID, difficulty level, and a pointer to the next level
// An array of structs called 'tileList' is made to hold the list of tilesets.
// A linked list of structs called 'levelList' is declared to hold the list of levels.

// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters. Otherwise, you risk getting compilation errors.
// You are not allowed to modify main().
// You can use string library functions.

// WRITE COMMENTS FOR IMPORANT STEPS IN YOUR CODE.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#pragma warning(disable: 4996) 		        // for Visual Studio Only. You can remove this for GCC

#define MAX_TILESETS 10                     // Number of tilesets 
#define MAX_LEVELS 5                        // Number of levels
#define MAX_NAME_LENGTH 25                  // General Name Restriction

typedef enum { City = 0, Dungeon, Wilderness } tileType;		// enum type 

struct tileset {						    // struct for tileset details
	char tileName[MAX_NAME_LENGTH];         // Name of the tileset
	tileType variety;                       // the assigned enum for the tileType
	unsigned int tileID;                    // Identifier for unique tileset
};

struct level {						        // struct for level details
	char levelName[MAX_NAME_LENGTH];        // name of the level
	unsigned int currentSet;                // Selected setID of a tileset
	unsigned int levelID;                   // Identifier for unique level
    int difficulty;                         // Difficulty level
	struct level* next;				        // pointer to next node
};

struct tileset tileList[MAX_TILESETS];	    // declare list of tilesets 'tileList'
struct level* levelList = NULL;				// declare linked levelList 'levelList'
int tileCount = 0;							// the numbesr of tilesets currently stored in the list (initialized to 0)
int levelCount = 0;							// the number of levels currently stored in the list (initialized to 0)

// functions already implmented
void flushStdIn();                          // Flush the input buffer
void executeAction(char);                   // Execute choice from input
void save(char* fileName);                  // Saves current details
void display();	                            // Displays all details

// functions that need implementation:
int addTileSet(char* tileName_input, 
		char* variety_input, 
		unsigned int tileID_input);	        // Add a tileset into the array		
int addLevel(char* levelName_input, 
		unsigned int tileID_input,
        unsigned int levelID_input,
        int difficulty_input);		        // Add a level into the level linked list
int deleteTileSet(unsigned int ID_input);	// delete a tileset
int deleteLevel(unsigned int ID_input);		// delete a Level
void sort();							    // Sort both the tilesets and levels
void load(char* fileName);					// Load all details from a file

/****************************************************************************************************************************************************************************************/

int main()
{
	char* fileName = "BiggusListus.txt";
	load(fileName);						    // load list of tiles and levels from file (if it exists). Initially there will be no file.
	char choice = 'i';					    // initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t 1: add a new tileset\n");
        printf("\t 2: add a new level\n");
        printf("\t 3: display tileset and level lists\n");
		printf("\t 4: remove a tileset from list\n");
        printf("\t 5: remove a level from list\n");
		printf("\t 6: sort tilesets by ID and levels by difficulty\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName);						    // save list of tiles and levels to file (overwrites file, if it exists)
	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
	char tileName_input[MAX_NAME_LENGTH], levelName_input[MAX_NAME_LENGTH];
	unsigned int tileID_input, levelID_input, difficulty_input, add_result = 0;
	char variety_input[20];
	switch (c)
	{
	case '1':
		// input tileset from user
		printf("\nEnter tileset name: ");
		fgets(tileName_input, sizeof(tileName_input), stdin);
		tileName_input[strlen(tileName_input) - 1] = '\0';				// discard the trailing '\n' char
		printf("Enter whether the tileset is 'City' or 'Dungeon' or 'Wilderness': ");
		fgets(variety_input, sizeof(variety_input), stdin);
		variety_input[strlen(variety_input) - 1] = '\0';				// discard the trailing '\n' char
		printf("Please enter tileset ID number: ");
		scanf("%d", &tileID_input);
		flushStdIn();

		// add the tileset to the list
		add_result = addTileSet(tileName_input, variety_input, tileID_input);
		if (add_result == 0)
			printf("\nTileset is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nTileset successfully added to the list! \n\n");
		else
			printf("\nUnable to add. the Tileset list is full! \n\n");
		break;
    case '2':
        // input level from user
		printf("\nEnter level name: ");
		fgets(levelName_input, sizeof(levelName_input), stdin);
		levelName_input[strlen(levelName_input) - 1] = '\0';	        // discard the trailing '\n' char
		printf("Please enter associated tileset ID number: ");
		scanf("%d", &tileID_input);
        printf("Please enter level ID number: ");
		scanf("%d", &levelID_input);
        printf("Please enter level difficulty number: ");
		scanf("%d", &difficulty_input);
		flushStdIn();


		// add the level to the list
		add_result = addLevel(levelName_input, tileID_input, levelID_input, difficulty_input);
		if (add_result == 0)
			printf("\nLevel is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nLevel successfully added to the list! \n\n");
		else
			printf("\nUnable to add the level. The level list is full! \n\n");

		break;
    case '3': 
        display();	
        break;
	case '4':
		printf("Please enter the ID number of the tileset to be deleted: ");
		scanf("%d", &tileID_input);
		flushStdIn();
		int delete_result1 = deleteTileSet(tileID_input);
		if (delete_result1 == 0)
			printf("\nTileset not found in the list! \n\n");
		else
			printf("\nTileset deleted successfully! \n\n");
		break;
    case '5':
		printf("Please enter the ID number of the level to be deleted: ");
		scanf("%d", &levelID_input);
		flushStdIn();
		int delete_result2 = deleteLevel(levelID_input);
		if (delete_result2 == 0)
			printf("\nLevel not found in the list! \n\n");
		else
			printf("\nLevel deleted successfully! \n\n");
		break;
	case '6': 
        sort();	
        break;
	case 'q': 		
        break;
	default: printf("%c is an invalid input!\n", c);
	}
}

// This function displays the tileset and level lists with the details (struct elements) of each tileset and level. 
void display()
{
	char* varietyString = "NoType";							        // dummy init
    struct level* tempList = levelList;				                // work on a copy of 'list'

    //
	for (int i = 0; i < tileCount; i++)						        // iterate through the tileset List
	{
		printf("\nTileset name: %s", tileList[i].tileName);		    // display tileset's name
		if (tileList[i].variety == City)						    // find what to display for tileset type
			varietyString = "City";
		else if (tileList[i].variety == Dungeon)
			varietyString = "Dungeon";
		else
			varietyString = "Wilderness";
		printf("\nTileset Type: %s", varietyString);			    // display tileset type
		printf("\nTileset ID Number: %d", tileList[i].tileID);	    // display tileset's ID
		printf("\n");
	}

	while (tempList != NULL) {					                    // traverse all levels in the list
		printf("\nLevel Name: %s", tempList->levelName);		    // display the level name
		printf("\nCurrent Tileset ID: %d", tempList->currentSet);   // display ID of currently used tileset
        printf("\nLevel ID Number: %d", tempList->levelID);		    // display level's ID
		printf("\nLevel Difficulty: %d", tempList->difficulty);		// display level's difficulty
		printf("\n");

		tempList = tempList->next;
	}
}

// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should read and understand how this code works. It will help you with 'load()' function.
// save() is called at end of main() to save the tileset and level lists to a file.
// The file is saved at the same place as your C file. 
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
    struct level* tempList = levelList;		            // work on a copy of 'list'
    int varietyValue = 0;
	FILE* file;

    file = fopen(fileName, "wb");			            // open file for writing

	fwrite(&tileCount, sizeof(tileCount), 1, file);		// First, store the number of tilesets in the list

	// Parse the list and write tileset record to file
	for (int i = 0; i < tileCount; i++)
	{
		fwrite(tileList[i].tileName, sizeof(tileList[i].tileName), 1, file);
		// convert enum to a number for storing
		if (tileList[i].variety == City)
			varietyValue = 0;		                    // 0 for City
		else if (tileList[i].variety == Dungeon)
			varietyValue = 1;		                    // 1 for Dungeon
		else
			varietyValue = 2;		                    // 2 for Wilderness

		fwrite(&varietyValue, sizeof(varietyValue), 1, file);
		fwrite(&tileList[i].tileID, sizeof(tileList[i].tileID), 1, file);
	}

    fwrite(&levelCount, sizeof(levelCount), 1, file);   // First, store the number of levels in the list

	// Parse the list and write level details to the file
	while (tempList != NULL) {
		fwrite(tempList->levelName, sizeof(tempList->levelName), 1, file);
		fwrite(&tempList->currentSet, sizeof(tempList->currentSet), 1, file);
        fwrite(&tempList->levelID, sizeof(tempList->levelID), 1, file);
        fwrite(&tempList->difficulty, sizeof(tempList->difficulty), 1, file);
		tempList = tempList->next;
	}

	fclose(file);					                    // close the file after writing
}

/***************************************************************** BEGIN QUESTION SETS ********************************************************************************/

// Q1 : addTileSet
// This function is used to add a tileset into the list. You can simply add the new tileset to the end of list (array of structs).
// Do not allow the tileset to be added to the list if it already exists in the list. 
// You can do this by checking if the tileset ID is already in the list.
// If the tileset already exists, then return 0 without adding it to the list. 
// If the tileset does not exist in the list, then add the tileset at the end of the list and return 1.
// If the tileset list is full, then do not add new tileset to the list and return 2.
// NOTE: Notice how return type of addTileSet() is checked in case '1' of the executeAction() function.
// NOTE: You must convert the string 'variety_input' to an enum type and store it in the list because the tileset type has enum type (not string type).
// Hint: the global variable 'tileCount' holds the number of tilesets currently in the list
int addTileSet(char* tileName_input, char* variety_input, unsigned int tileID_input)
{
	tileType tile_enum;
	// Write the code below.
	for (int i = 0; i < tileCount; i++) {
		if (tileList[i].tileID == tileID_input) {
			return 0;
		}
	}
	if (tileCount < MAX_TILESETS) {
		switch(variety_input[0]) {
			case 'C':
				tile_enum = City;
				break;
			case 'D':
				tile_enum = Dungeon;
				break;
			case 'W':
				tile_enum = Wilderness;
				break;
		}
		strcpy(tileList[tileCount].tileName, tileName_input);
		tileList[tileCount].variety = tile_enum;
		tileList[tileCount].tileID = tileID_input;
		tileCount++;
		return 1;
	}
	return 0;										// edit this line as needed
}

// Q2 : addLevel
// This function is used to add a level into the list. You can simply add the new level to the end of list (linked list of structs).
// Do not allow the level to be added to the list if it already exists in the list. 
// You can do that by checking if the level ID is already in the list.
// If the level already exists then return 0 without adding it to the list. 
// If the level does not exist in the list, then add the level at the end of the list and return 1.
// If level list is full, then do not add new level to the list and return 2.
// NOTE: Notice how return type of addLevel() is checked in case '2' of executeAction()
// Hint: 'levelCount' holds the number of levels currently in the list
int addLevel(char* levelName_input, unsigned int tileID_input, unsigned int levelID_input, int difficulty_input)
{
    struct level* tempList = levelList;		        // work on a copy of 'levelList'
	// Write the code below.
	for (int i = 0; i < levelCount; i++) {
		if (tempList->levelID == levelID_input) {
			return 0;
		}
		tempList = tempList->next;
	}
	if (levelCount < MAX_LEVELS) {
		struct level* newLevel = (struct level*)malloc(sizeof(struct level));
		strcpy(newLevel->levelName, levelName_input);
		newLevel->currentSet = tileID_input;
		newLevel->levelID = levelID_input;
		newLevel->difficulty = difficulty_input;
		newLevel->next = NULL;
		if (levelList == NULL) {
			levelList = newLevel;
		} else {
			tempList = levelList;
			while (tempList->next != NULL) {
				tempList = tempList->next;
			}
			tempList->next = newLevel;
		}
		levelCount++;
		return 1;
	}
	return 0;										// edit this line as needed
}

// Q3 : deleteTileSet
// This function is used to delete a tileset by ID.
// Parse the list and compare the tileset IDs to check which one should be deleted.
// Restore the array structure after removal of the tileset.
// You'll have to parse through the levelList to see if the tileset is used by any level.
// If a level uses the specified tileset, set that level's currentSet attribute to 9999.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a tileset.
int deleteTileSet(unsigned int tileID_input)
{
	struct tileset tilesetTemp;						// useful for swapping structs. Not absolutely necessary to use.
    struct level* tempList = levelList;		        // work on a copy of 'levelList'
	// Write the code below
	for (int i = 0; i < tileCount; i++) {
		if (tileList[i].tileID == tileID_input) {
			for (int j = i; j < tileCount - 1; j++) {
				tileList[j] = tileList[j + 1];
			}
			tileCount--;
			for (int j = 0; j < levelCount; j++) {
				if (tempList->currentSet == tileID_input) {
					tempList->currentSet = 9999;
				}
				tempList = tempList->next;
			}
			return 1;
		}
	}
	return 0; // edit this line as needed
}

// Q4 : deleteLevel
// This function is used to delete a level by ID.
// Parse the list and compare the level IDs to check which one should be deleted.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a level.
int deleteLevel(unsigned int levelID_input)
{
    struct level* tempListCur = levelList;		        // work on a copy of 'levelList'
    struct level* tempListPrev = levelList;		        // work on a copy of 'levelList'
	// Write the code below.
	for (int i = 0; i < levelCount; i++) {
		if (tempListCur->levelID == levelID_input) {
			if (tempListCur == levelList) {
				levelList = tempListCur->next;
			} else {
				tempListPrev->next = tempListCur->next;
			}
			free(tempListCur);
			levelCount--;
			return 1;
		}
		tempListPrev = tempListCur;
		tempListCur = tempListCur->next;
	}
	return 0;										// edit this line as needed
}

// Q5 : sort
// This function serves two purposes. Please view each section below for information on each purpose

/*TILESETS*/
// This function is used to sort the list (array of structs) numerically by the tileset's ID.
// Parse the list and compare the tileset IDs to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new list of structs having sorted tilesets.
// Hint: Use a temp struct (already declared) if you need to swap two structs in your logic

/*LEVELS*/
// This function is used to sort the list (linked list of structs) numerically by difficulty.
// Parse the list and compare the level difficulties to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new node of structs having sorted difficulty.
void sort()
{
	struct tileset tilesetTemp;						// needed for swapping structs. Not absolutely necessary to use.
    struct level* tempList = levelList;		        // work on a copy of 'levelList'
    int swapped = 0;				                // indicator for checking whether or not swap happened. May be useful
	// Write the code below.
	for (int i = 0; i < tileCount; i++) {
		for (int j = 0; j < tileCount - i - 1; j++) {
			if (tileList[j].tileID > tileList[j + 1].tileID) {
				tilesetTemp = tileList[j];
				tileList[j] = tileList[j + 1];
				tileList[j + 1] = tilesetTemp;
			}
		}
	}

	// display message for user to check the result of sorting. Do not touch this
	printf("\nBoth lists sorted! Use display option '3' to view the sorted lists.\n");
}

// Q6:  load (10 points)
// This function is called in the beginning of main().
// This function reads both lists from the saved file and builds the array of structures 'tileList' and linked list of structures 'levelList'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// If the file exists, then parse the tileset and level lists to read the tileset and level details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//  So you need to implement load() similar to how save() is implemented. Only then will the lists be loaded correctly.
//	You can simply delete the file to 'reset the lists' or to avoid loading from it.
void load(char* fileName)
{
	// Write the code below.
	FILE* file;
	file = fopen(fileName, "rb");
	if (file == NULL) {
		return;
	}
	fread(&tileCount, sizeof(tileCount), 1, file);
	for (int i = 0; i < tileCount; i++) {
		fread(tileList[i].tileName, sizeof(tileList[i].tileName), 1, file);
		fread(&tileList[i].variety, sizeof(tileList[i].variety), 1, file);
		fread(&tileList[i].tileID, sizeof(tileList[i].tileID), 1, file);
	}
	fread(&levelCount, sizeof(levelCount), 1, file);
	struct level* tempList = levelList;
	for (int i = 0; i < levelCount; i++) {
		struct level* newLevel = (struct level*)malloc(sizeof(struct level));
		fread(newLevel->levelName, sizeof(newLevel->levelName), 1, file);
		fread(&newLevel->currentSet, sizeof(newLevel->currentSet), 1, file);
		fread(&newLevel->levelID, sizeof(newLevel->levelID), 1, file);
		fread(&newLevel->difficulty, sizeof(newLevel->difficulty), 1, file);
		newLevel->next = NULL;
		if (levelList == NULL) {
			levelList = newLevel;
		} else {
			tempList = levelList;
			while (tempList->next != NULL) {
				tempList = tempList->next;
			}
			tempList->next = newLevel;
		}
	}
	fclose(file);

	// The following two print statements are used in your code. You may have to change their position but not their contents. 
	printf("%s not found.\n", fileName);
	// printf("Lists successfully loaded from %s.\n", fileName);
}
