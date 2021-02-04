/* 11917679, Matthew Jericho Go Sy, S15A */

#include <stdio.h>
#include <stdlib.h>		// rand(), srand()
#include <time.h>		// time()

#define FALSE 0
#define TRUE 1

#define ANNA 1		// Anna's story is labeled as "Scenario 1" in the flowchart
#define HARRY 2		// Harry's story is labeled as "Scenario 2" in the flowchart

/*
	Description: 	This function obtains a random number between 1-100
	Parameters:
		nRandomNumber	The value of rand() is assigned to this variable.
		nMin			Sets the minimum value produced by the RNG
		nMax 			Sets the maximum value produced by the RNG
		
	Return value:	Returns the random number stored in the nRandomNumber variable.
*/
int getRandomNumber() {
	int nRandomNumber;
	int nMin = 1; 
	int nMax = 100;
  
    nRandomNumber = (rand() % (nMax - nMin + 1)) + nMin; 
    
    return nRandomNumber;
}

/*
	Description: 	Checks if value is either 1 or 2. If not, the user is prompted to input a valid number again. NOTE: Cannot catch wrong data type entry
	Parameters:
		nInput		The value of scanf() is assigned to this variable
		
	Return value:	Returns the VALID number stored in the nInput variable.
*/
int getIntInput() {
	int nInput;
	
	do
	{	
		printf("\n[Enter 1 or 2]: ");
		scanf("%d", &nInput);
		if (nInput != 1 && nInput != 2)
			printf("	Invalid input.");
		
	}while (nInput != 1 && nInput != 2);
	
	return nInput;
}

/*
	Description: 	Checks if value is 'Y', 'y', 'N', or 'n'. If not, the user is prompted to input a valid value again.
	Parameters:
		cInput		The value of scanf() is assigned to this variable
		
	Return value:	Returns TRUE if the VALID input value equals to 'Y' or 'y', and FALSE if the VALID input value equals to 'N' or 'n'.
*/
int getCharInput() {
	char cInput;
	
	do
	{	// Ask input from user
		printf("[Y/n]: ");
		scanf(" %c", &cInput);
		// Check if not within range
		if (cInput != 'Y' && cInput != 'y' && cInput != 'N' && cInput != 'n')	// (As long as one of these conditions isn't satisfied meaning the input is within range, the loop exits.)
			printf("	Invalid input.");
		
	}while (cInput != 'Y' && cInput != 'y' && cInput != 'N' && cInput != 'n');	// Re-prompt the user if input is invalid.
	
	// Return the answer as TRUE or FALSE
	if (cInput == 'Y' || cInput == 'y')
		return TRUE;
	else
		return FALSE;
}

/*
	Description: 	Puzzle 1 prompts to user to input a 4-digit PIN code on the vault 
	Parameters:
		nFailCount		Stores the number of attempts
		nInput			The value of scanf() is assigned to this variable
		*nPuzzle2Passed		Assigned TRUE if puzzle was successful
		
	Return value:	N/A, (used pointers to set the if the puzzle was successful or not).
*/
void doPuzzle1(int * nPuzzle1Passed) {
	int nFailCount = 0;
	int nInput;
	
	*nPuzzle1Passed = FALSE;	// Pre-assign value of false (FAIL) to be changed later if the puzzle is solved (SUCCESS).
	
	// Display puzzle 1 info and needed input
	printf("\n	The vault seems to be locked with a 4-digit PIN code.\n");
	
	do
	{
		printf("\n	[Enter a code]: ");
		scanf("%d", &nInput);
		if (nInput != 2001)
			printf("		Try again.");
		else
			*nPuzzle1Passed = TRUE;
		nFailCount++;
	}while (nInput != 2001 && nFailCount != 4);	// The clue is 010928 and the PIN code is 2001. Re-prompt the user if input doesn't match.
}

/*
	Description: 	Puzzle 1 prompts to user to input a 4-digit PIN code on the vault 
	Parameters:
		nFailCount			Stores the number of attempts
		nInput				The value of scanf() is assigned to this variable
		*nPuzzle2Passed		Assigned TRUE if puzzle was successful
		
	Return value:	N/A, (used pointers to set the if the puzzle was successful or not).
*/
void doPuzzle2(int * nPuzzle2Passed) {
	int nFailCount = 0;
	int nInput;
	
	*nPuzzle2Passed = FALSE;	// Pre-assign value of false (FAIL) to be changed later if the puzzle is solved (SUCCESS).
	
	// Prompt the user for a room to search
	do
	{
		printf("\n	Which room should you search?\n");
		printf("\n  	[1] A room within the basement\n  	[2] The living room\n 	[3] The bedroom\n  	[4] The attic");
		printf("\n	[Enter a code]: ");
		scanf("%d", &nInput);
		if (nInput != 3)
			printf("\n		Try again.\n");
		else
			*nPuzzle2Passed = TRUE;
		nFailCount++;
	}while (nInput != 3 && nFailCount != 2);	// Room 3 is the significant room. Re-prompt the user if input doesn't match.
}

int main() {
	/* --- INITIALIZE EVERYTHING --- */
	
	// Assign names of the three (3) characters in the story
	// Note: In C, a string is really just an array of characters
	/*
	char cProtagonistA[] = "Anna"; 		-X- DISABLED as it worsens code readability -X-
	char cProtagonistB[] = "Harry";
	char cAntagonist[] = "Drake";
	*/
	
	int nStoryEnded = FALSE;
	
	// Declare and assign puzzles to be neither passed nor failed
	int nPuzzle1Passed = 5;
	int nPuzzle2Passed = 5;
	
	// Initialize random seed for rand()
	srand(time(NULL));
	
	// Declare input variables
	int nInput;		// nInput range always 1 or 2
	char cInput;
	
	/* --- DISPLAY STARTUP AND SYNOPSIS --- */
	printf("\n");
	printf("	****************************\n");
	printf("	*        Welcome to        *\n");
	printf("	*                          *\n");
	printf("	*  A NIGHT WITH THE TWINS  *\n");
	printf("	*                          *\n");
	printf("	* by Matthew Jericho Go Sy *\n");
	printf("	****************************\n");
	
	printf("________________________________________________________________________________________\n\n");
	
	printf("Synopsis: You and your twin decide to spend your winter break at your family rest house.\n");
	printf("________________________________________________________________________________________\n\n");
	
	
	/* --- CHARACTER SELECTION --- */
	// User picks a character to play as
	printf("Who do you want to play as? [1. Anna / 2. Harry] ");
	int nCharacterChoice = getIntInput();
	
	// Display feedback of their choice
	if (nCharacterChoice == ANNA)
		printf("\nYou chose Anna.\n");
	else
		printf("\nYou chose Harry.\n");
	
	/* --- DISPLAY INTRO --- */
	printf("______________________________________________________________________\n\n");
	printf("Intro: You approach the abandoned and lifeless house where your friend\n");
	printf("       died last year after a harmless prank led to her tragic end.\n");
	printf("______________________________________________________________________\n\n");
	
	/* --- STORY STARTS --- */
	if (nCharacterChoice == ANNA) {
		printf("\n	Harry looks dementedly at the house.\n");
		printf("\nHarry: Old but stable, good enough.");
	}
	else {
		printf("\n	Anna sighs at the sight of the house.\n");
		printf("\nAnna:  This house sure has a spooky vibe.");
	}
	printf("\nAnna:  At least tell me there's hot water.");
	printf("\nHarry: Maybe?");
	
	if (nCharacterChoice == ANNA) {
		printf("\nHarry: Do you wanna go to the basement?");
		printf("\nAnna:  You can stay here and set up the fireplace, I'll check it out.");
		printf("\n\n	You go to the basement separately; finds the water heater and switches it on.\n");
	}
	else {
		printf("\nAnna:  Do you wanna go to the basement?");
		printf("\nHarry: Let's check it out together.");
		printf("\n\n	You go to the basement together to turn on the water heater.\n");
	}
	
	// Display info/guideline
	printf("\n\n	(The future will remain uncertain. Your choices will affect the story later on.)\n\n");
	
	/* --- STORY DIVERGES (lock on a character's viewpoint) --- */
	// Scenario 1
	if (nCharacterChoice == ANNA) {
		// Declare variables and assign zero (0) to flag points. This will be changed to one (1) if the user picks up the item.
		int nFlagClue = 0; 
		int nFlagShotgun = 0;
		
		// Ask if the user wants to view nFlagClue clue
		printf("\n	You find a small note stuck on the wall.\n	Do you pick it up? ");
		nFlagClue += getCharInput();
		if (nFlagClue == 1)
			printf("\n	You spot a code on the note: 010928\n");
		
		printf("\n	You go back upstairs.\n");
		printf("\nHarry: I don't recall anyone breaking a window the last time we had our friends here.");
		
		// Dialogue input 1
		printf("\n  [1] \"It probably was like that before we got here.\"\n  [2] \"That's weird, I don't recall that either.\"");
		if (getIntInput() == 1)
			printf("\nHarry: I'm pretty sure that was not the case.");
		else {
			// Dialogue input 2
			printf("\nHarry: The house may have had a heinous history but there is nothing here. It's just rumors.");
			printf("\n  [1] \"Yeah you're probably right.\"\n  [2] \"No one would make a rumor like that, that's insane!\"");
			/* if (getIntInput() == 1) */
			getIntInput();
		}
		printf("\nHarry: Whatever. Let's just settle in, I can't wait!");
		
		printf("\n\n	One day, Harry goes for a jog, you are home alone.\n");
		printf("\n	An hour passes, Harry isn't back. You decide to take a nap.\n");
		printf("\n	Suddenly, you wake up from a loud bang downstairs assuming it is Harry.\n");
		// Dialogue input 3
		printf("\n  [1] Wait for him.\n  [2] Go downstairs.");
		if (getIntInput() == 1)
			printf("\n	After waiting a little bit, he still hasn't gone up, so you go downstairs to check.\n");
		
		printf("\n	A masked figure with an axe looms in front of the doorway of the house.\n");
		printf("\n	You see him wandering around & you see the phone by an end table.\n");
		// Dialogue input 4
		printf("\n  [1] Run to the phone.\n  [2] Crawl to the phone.");
		nInput = getIntInput();
		printf("\n	You were able to grab the phone.\n");
		
		if (nInput == 1)
			printf("\n	While frantically finding a place to hide...\n");
		else {
			// Dialogue input 5
			printf("\n  [1] Look for a room to hide in.\n  [2] Try dialing 9-1-1.");
			nInput = getIntInput();
		}
		
		if (nInput == 1) {
			printf("\n	You stumble upon a room with a vault in it.\n");
			printf("\n	At first, you try to dial 9-1-1 but, you realize, there is no signal in the room.\n");
			// Dialogue input 6
			printf("\n  [1] Go out of the room to find signal.\n  [2] Try to open the vault instead.");
			if (getIntInput() == 1)
				nInput = 1;
			else {
				// Puzzle 1
				doPuzzle1(&nPuzzle1Passed);
				if (nPuzzle1Passed == 1) {	// User SUCCEEDS in Puzzle 1 and obtains nFlagShotgun item
					printf("\n	The vault opened. Inside you find a shotgun.\n");
					nFlagShotgun = 1;
					printf("\n	You try to grab the shotgun in order to defend yourself.\n");
					printf("\n	Before you could do so, the intruder holds you at gunpoint again.\n");
					// Dialogue input 7
					printf("\n  [1] Grab the gun anyway.\n  [2] Give up.");
					if (getIntInput() == 1) {	/* --- (BAD) ENDING 1 --- */
						printf("_______________________________________________\n\n");
						printf("You get shot before you're able to use the gun.\n");
						nStoryEnded = TRUE;
					}
				}
				else { 	// User FAILS Puzzle 1
					nInput = 1;
					// nPuzzlePassed left at default value of FALSE
				}
			}
		}
		else {
			printf("\n	You hear the sound of an axe smashing through the door.\n");
			printf("\n	Before you know it, you are held at gunpoint from behind.\n");
			printf("\n(Intruder): DROP THE PHONE !!\n");
			// Dialogue input 8
			printf("\n  [1] Try to grab his gun.\n  [2] Drop the call.");
			if (getIntInput() == 1) {	/* --- (BAD) ENDING 2 --- */
				printf("_________________________________________________\n\n");
				printf("While wresting for the gun, you get shot and die.\n");
				nStoryEnded = TRUE;
			}
		}
		// Need nStoryEnded condition == FALSE onwards	
		
		if (nStoryEnded == FALSE) {
			if (nInput == 1 || nPuzzle1Passed == FALSE)
				printf("\n	The intruder spots you...\n");
			
			// All paths in Scenario 1 lead to here (if they haven't died)
			// Ending sequence
			printf("\n	You get beaten, gassed, and eventually pass out.\n");
			printf("\n	You wake up, tied up. The intruder faces you and your heart drops when he removes his mask.\n");
			printf("\n(Intruder): I don't want you dead, but your brother needs to pay.");
			printf("\nAnna:  Drake,you're evil!");
			printf("\nDrake: You did stop everyone so I'd spare you... not your twin though. Can't wait till he gets back.");
			printf("\n\n	Somehow, you're able to grab a pocket knife and cut the ropes off, instantly kicking him to the ground.\n");
			printf("\n	You run back upstairs, shoving or throwing anything to block him.\n");
			if (nFlagShotgun == 1)
				printf("\n	You find your gun but, it is now empty.");
			printf("\n	He starts firing indiscriminately.\n");
			printf("\n	You spot Harry coming from the basement, while Drake runs towards you and confronts you with a question\n");
			
			printf("\nDrake: Decide, you or Harry?");
			// Dialogue input 9
			printf("\n  [1] Surrender.\n  [2] Plead with him.");
			if (getIntInput() == 1) {
				printf("\n	Harry abruptly knocks a candle by a curtain and you tackle Drake.\n");
				printf("\n	Drake inches the gun to Harry about to pull the trigger when you push him and he falls down onto the burning curtain.\n");
				printf("\nHarry: The police is here Anna!!");
				printf("\nAnna: Let's get out of here!");
				
				/* --- (GOOD) ENDING 3 --- */
				printf("\n_____________________________________________________\n\n");
				printf("Trembling, you murmur. \"Sigh, at least we're okay.\"\n");
				nStoryEnded = TRUE;
			}
			else {
				printf("\n	Drake frowns after you backtrack stories of what his sister was like.\n");
				printf("\n	Harry eyes the door to you. You hesitate, sirens faintly coming close.\n");
				if (getRandomNumber() > 50) {		/* --- (BEST) ENDING 4 --- */
					printf("%d", getRandomNumber());
					printf("\n__________________________________________________________________________________________\n\n");
					printf("The police catch Drake and escort him to their car, while you and Harry hold on to relief.\n");
					nStoryEnded = TRUE;
				}
				else {		/* --- (OK) ENDING 5 --- */
					printf("\n__________________________________________________________________________________\n\n");
					printf("Drake abruptly rushes out the door, evades the police, but you and Harry are safe.\n");
					nStoryEnded = TRUE;
				}
			}
		}
	}
	// Scenario 2
	else {
		// Declare variables and assign zero (0) to flag points. This will be changed to one (1) if the user picks up the item.
		int nFlagSafetyPin = 0;
		int nFlagShovel = 0;
		// int nFlagPhoto = 0;
		
		printf("\nHarry: Wow there's a lot of stuff here. I've never been in this part of the house before.");
		printf("\nAnna:  Don't get distracted much, we still have to set up.");
		
		// Ask if the user to either pick up nFlagSafetyPin or nFlagPhoto
		printf("\n\n	You spot a safety pin and a piece of torn photo. Which one do you pick up?");
		printf("\n  [1] Safety pin\n  [2] Piece of torn photo");
		if (getIntInput() == 1)
			nFlagSafetyPin = 1;
		
		printf("\nAnna: This house is nice but it's a little dull and slightly eerie.");
		// Dialogue input 10
		printf("\n  [1] Reassure her.\n  [2] Scare her.");
		if (getIntInput() == 1)
			printf("\nAnna: Thanks, I appreciate it!");
		else {
			printf("\n	Anna squeals and slaps your arm.\n");
			printf("\nAnna: Very funny.\n");	
		}
		
		printf("\n\n	You and Anna spend the rest of the day settling in and relaxing under the cozy winter weather.\n");
		printf("\n	The next day, you decided to go for a walk while Anna stayed at the house.\n");
		printf("\n	On your way back, you noticed the lights are off. You reach for the door but it is locked.\n");
		
		if (nFlagSafetyPin == 1) {
			// Dialogue input 11
			printf("\n	You have a safety pin available. Use it? ");
			cInput = getCharInput();
			
			if (cInput == 1) {		// Can't use else so if again used later
				printf("\n	You check the basement and see a light trail of blood at your left, and a shadowy figure trailing at your right.");	
				// Dialogue input 12
				printf("\n  [1] Follow the moving shadow.\n  [2] Follow the blood trail.");
				nInput = getIntInput();
				
				if (nInput == 1) {
					printf("\n	While trying to follow the figure, you lose sight of him.\n");	
					// Dialogue input 13
					printf("\n  [1] Continue searching.\n  [2] Check the blood trail earlier.");
					nInput = getIntInput();
					
					if (nInput == 1) {
						printf("\n	Being curious and scared, you try to your luck in searching a few rooms.\n");
						doPuzzle2(&nPuzzle2Passed);
						
						if (nPuzzle2Passed == FALSE) {	/* --- (BAD) ENDING 6 --- */
							printf("\n________________________________________________________________________________\n\n");
							printf("You died... A man was right behind you all along and stabbed you with a knife...\n");
							nStoryEnded = 1;
						}
					}
				}
				if (nInput == FALSE && nPuzzle2Passed != TRUE) {
					printf("\n	You realize the blood trail leads upstairs...\n");
					printf("\nHarry: Anna!? Where are you?!!");
					printf("\n	You follow the path but find nothing, except a small room filled with traps & tools.\n");
				}
				if (nInput == FALSE) {
					printf("\n	You see small traces of blood in the corner, still looking fresh.\n");
					printf("\n	Suddenly, you hear Anna scream. You frantically try to reach her.\n");
				}
			}
		}
		// Need nStoryEnded condition == FALSE onwards	
		
		if (nStoryEnded == FALSE) {
			
			if (nFlagSafetyPin == FALSE) {
				printf("\n	You check the back entrance instead.\n");
				printf("\n	You try to open but it's really is locked.\n");
				printf("\n	A shovel catches your eye.\n	Pick it up? ");
				nFlagShovel += getCharInput();
				
				printf("\n	You peer through the windows and see Anna getting gassed. \n");
				
				if (nFlagShovel == 1 && nPuzzle2Passed != TRUE)
					printf("\n	You were able to break the window using your shovel.\n");
				if (nFlagShovel == 1) {
					printf("\nHarry: Anna!!");
					printf("\n\n	A fight ensues...\n");
					printf("\n	But suddenly, he disappears...\n");
					printf("\nHarry: Are you okay?");
					printf("\nAnna: HE GASSED ME!!!");
					printf("\n	Suddenly, you hear glass shattering in the kitchen. You both go there and see the intruder advancing to you.\n");
					printf("\n(Man): What did you do to her!!");
					printf("\nHarry: Drake?!? Dude, I tried to save her but I was late.");
					printf("\nDrake: Exactly! You had a chance to go after her, but you left her out there to die!");
					
					// Dialogue input 14
					printf("\n  [1] Feel sympathetic.\n  [2] Provoke him.");
					nInput = getIntInput();
					if (nInput == TRUE) {
						printf("\n	He grimaces and takes out a lighter. Anna tackles him from behind.\n");
						printf("\n	Anna: Just get out of here and get help... Please let me do this for you!\"\n");
						
						// Dialogue input 15
						printf("\n  [1] Leave the house\n  [2] Save Anna");
						nInput = getIntInput();
						if (nInput == TRUE) {	/* --- (OK) ENDING 7 --- */
							printf("\n__________________________________________________________________________________________\n\n");
							printf("The house explodes, you watch and pray for a miracle. She makes it. With burns, but alive.\n");
						}
					}
					if (nInput == FALSE) {		/* --- (TRAGIC) ENDING 8 --- */
						printf("\n_______________________________________________\n\n");
						printf("Lighter drops onto the gasoline, everyone dies.\n");
					}
				}
				if (nFlagShovel != 1)	/* --- (BAD) ENDING 9 --- */
				{
					printf("\n	You try breaking the window with your hands.\n");
					printf("\n	You eventually succeed.\n");
					printf("\n	But, it's too late...\n");
					printf("\n	He choked her...\n");
					printf("\n____________\n\n");
					printf("Anna dies...\n");
					nStoryEnded = 1;
				}
			}
		}		
	}
	return 0;
}
