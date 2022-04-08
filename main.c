#include <stdio.h>
#include <stdlib.h>

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

int main() {
    char filename[] = "words.txt";

    int num_words = 0;
    char** words = read_words(filename, &num_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    free_words(words, num_words);
    return 0;
}