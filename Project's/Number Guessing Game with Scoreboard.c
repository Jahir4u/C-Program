#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <dos.h>   // for delay()

#define MAX 50   // maximum players to store

char playerNames[MAX][30];
int attempts[MAX];
int playerCount = 0;

// Function for animation (loading)
void loading() {
    int i;
    printf("\nLoading");
    for (i = 0; i < 5; i++) {
        delay(500);  // half-second delay
        printf(".");
    }
    printf("\n");
}

// Login function
int login() {
    char user[20], pass[20];
    char sysUser[20] = "admin";
    char sysPass[20] = "1234";
    int tries = 0;

    while (tries < 3) {
        printf("\n--- LOGIN ---\n");
        printf("Username: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", pass);

        if (strcmp(user, sysUser) == 0 && strcmp(pass, sysPass) == 0) {
            printf("\nLogin Successful!\n");
            loading();
            return 1; // success
        } else {
            printf("\nInvalid credentials! Try again.\n");
            tries++;
        }
    }
    printf("\nToo many failed attempts. Exiting...\n");
    return 0; // fail
}

// Function to play one round
void playGame() {
    char name[30];
    int guess, secret, count = 0;

    printf("\nEnter your name: ");
    scanf("%s", name);

    // Generate random number between 1 and 100
    secret = (rand() % 100) + 1;

    printf("\nI have chosen a number between 1 and 100.\n");
    printf("Try to guess it!\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;

        if (guess > secret) {
            printf("Too high! Try again.\n");
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else {
            printf("\n🎉 Correct! You guessed it in %d attempts.\n", count);
        }

        delay(400);  // small pause for effect
    } while (guess != secret);

    // Save record
    if (playerCount < MAX) {
        strcpy(playerNames[playerCount], name);
        attempts[playerCount] = count;
        playerCount++;
    }
}

// Function to display scoreboard
void showScoreboard() {
    int i;
    if (playerCount == 0) {
        printf("\nNo games played yet!\n");
        return;
    }

    printf("\n--- Scoreboard ---\n");
    printf("Name\tAttempts\n");
    for (i = 0; i < playerCount; i++) {
        printf("%s\t%d\n", playerNames[i], attempts[i]);
    }
}

void main() {
    int choice;

    // Seed random number generator
    srand(time(NULL));

    // Login first
    if (!login()) {
        exit(0);
    }

    do {
        printf("\n--- Number Guessing Game ---\n");
        printf("1. Play Game\n");
        printf("2. View Scoreboard\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showScoreboard();
                break;
            case 3:
                printf("\nThanks for playing! Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 3);
}
