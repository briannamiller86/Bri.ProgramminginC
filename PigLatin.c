#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LEN 1000
#define MAX_LINE_LEN 10000

int is_vowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void to_pig_latin(char *word, char *result) {
    int len = strlen(word);
    int i = 0, punct_index = -1;

    // Check for punctuation at the end
    if (ispunct(word[len - 1])) {
        punct_index = len - 1;
        word[len - 1] = '\0';
        len--;
    }

    // Handle words like "all's" or "world's" that have apostrophes
    if (strchr(word, '\'')) {
        strcpy(result, word);
        strcat(result, "yay");
        if (punct_index != -1)
            result[strlen(result)] = word[len];
        return;
    }

    if (is_vowel(word[0])) {
        sprintf(result, "%syay", word);
    } else {
        int consonant_cluster_end = 0;
        while (consonant_cluster_end < len && !is_vowel(word[consonant_cluster_end])) {
            consonant_cluster_end++;
        }

        sprintf(result, "%s%.*say",
                &word[consonant_cluster_end],
                consonant_cluster_end,
                word);
    }

    // Restore punctuation
    if (punct_index != -1) {
        int l = strlen(result);
        result[l] = word[len];  // restore punctuation
        result[l + 1] = '\0';
    }
}

void translate_sentence(char *input, char *output) {
    char *token;
    char buffer[MAX_WORD_LEN];
    char translated[MAX_WORD_LEN];
    output[0] = '\0';

    token = strtok(input, " ");
    while (token != NULL) {
        to_pig_latin(token, translated);
        strcat(output, translated);
        token = strtok(NULL, " ");
        if (token != NULL)
            strcat(output, " ");
    }
}

int main() {
    char input[MAX_LINE_LEN];
    char output[MAX_LINE_LEN];

    printf("Enter a sentence: \n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline

    translate_sentence(input, output);
    printf("\nPig Latin Translation:\n%s\n", output);

    return 0;
}
