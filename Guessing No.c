#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random, guess;
    int no_of_guess = 0;
    srand(time(NULL));
    printf("Welcome to the world of Guessing Numbers,\n");
    random = rand() % 100 + 1;

    do {
        printf("Guess the number between (1 to 100): \n");
        scanf("%d", &guess);
        no_of_guess++;
        if (guess < random) {
            printf("You need to guess a larger number.\n");
        } else if (guess > random) {
            printf("You need to guess a smaller number.\n");
        } else {
            printf("\nCongratulations!! You have guessed the correct number in %d attempts.\n", no_of_guess);
        }
    } while (guess != random);

    printf("Thank you from the bottom of our heart for playing.\n");
    printf("Created by: Himesh Raghuwanshi\n");

    return 0;
}
