#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _POSIX_C_SOURCE 200809L

char** read_words(const char* filename, int* num_words) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error reading file.\n");
        return NULL;
    }

    char** words = NULL;
    char* word = NULL;
    size_t word_size = 0;

    int count_words = 0;

    while (getline(&word, &word_size, file) != EOF) {
        words = realloc(words, sizeof(char*) * (count_words + 1));
        word[5] = '\0';
        words[count_words] = word;
        count_words++;
        word = NULL;
    }
    free(word);
    fclose(file);
    *num_words = count_words;
    return words;
}

void free_words(char** words, const int num_words) {
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
}

char* get_random_word(char** words, const int num_words) {
    int idx = rand() % num_words;
    return words[idx];
}

bool word_in_words(char* attempt, char** words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(attempt, words[i]) == 0) {
            return true;
        }
    }
    return false;
}

void score_attempt(char* attempt, char* target, char* result) {
    // char result[] = "_____"; // não pode ser retornado
    // char* result = malloc(sizeof(char) * 6);
    for (int i = 0; i < 5; i++) {
        result[i] = '_';
    }
    result[5] = '\0';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // TODO: falta comparar no mesmo case
            if (attempt[i] == target[j]) {
                if (i == j) {
                    // Indicar com maiúscula que a letra está na posição correta
                    result[i] = attempt[i] < 'a' ? attempt[i] : attempt[i] - ('a' - 'A');
                } else {
                    // Indicar com minúscula que a letra existe, mas não está na posição correta
                    result[i] = attempt[i] < 'a' ? attempt[i] + ('a' - 'A') : attempt[i];
                }
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    char filename[] = "words.txt";

    int num_words = 0;
    char** words = read_words(filename, &num_words);

    char* target = get_random_word(words, num_words);

    char* attempt = NULL;
    size_t num_chars = 0;
    int num_attempts = 0;
    while (num_attempts < 6) {
        getline(&attempt, &num_chars, stdin);
        attempt[strlen(attempt) - 1] = '\0';
        if (strlen(attempt) != 5) {
            printf("Tentativa inválida.");
        } else if (!word_in_words(attempt, words, num_words)) {
            printf("Tentativa inválida.");
        } else {
            char* attempt_score = malloc(sizeof(char) * 6);
            score_attempt(attempt, target, attempt_score);
            printf("%s\n", attempt_score);
            free(attempt_score);
            num_attempts++;
        }
        attempt = NULL;
    }
    free(attempt);

    free_words(words, num_words);
    return 0;
}