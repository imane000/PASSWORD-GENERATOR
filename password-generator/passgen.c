#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char charset[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789"
    "!@#$%^&*()_+-=[]{}|;:,.<>?";

int main() {
    int length, i;
    char password[100]; // taille max = 99 caractères + '\0'

    printf("Welcome to simple password generator!\n");
    sleep(3);

    printf("Please enter the length of the password: ");
    scanf("%d", &length);

    if (length > 99 || length <= 0) {
        printf("Invalid length. Must be between 1 and 99.\n");
        return 1;
    }

    srand(time(NULL)); // initialise le générateur aléatoire

    for (i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
    }

    password[length] = '\0'; // fin de chaîne

    printf("Generated password: %s\n", password);

    return 0;
}
