/*
 * Using names.txt, a 46K text file containing over five-thousand first names,
 * begin by sorting it into alphabetical order. Then working out the
 * alphabetical value for each name, multiply this value by its alphabetical
 * position in the list to obtain a name score.
 * For example, when the list is sorted into alphabetical order, COLIN, which is
 * worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 × 53 = 49714.
 * What is the total of all the name scores in the file?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NAMES 10000 // assume there are <= 10000 names in file

int compare(const void *a, const void *b);
int alphabeticalSum(char *str);
int alphabeticalValue(char c);

int main() {
    FILE *fp = fopen("names.txt", "r");
    if (fp == NULL) return 0;

    // Get file size and use it to determine array size
    int fileSize;
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);

    // Read file into a string
    char fileString[fileSize];
    fseek(fp, 0, SEEK_SET);
    fgets(fileString, fileSize+1, fp);

    // Put each separate name into a name array
    int index = 0;
    char *names[NUM_NAMES], *ptr;
    ptr = strtok(fileString, ",\"");
    while (ptr != NULL) {
        names[index] = ptr;
        ptr = strtok(NULL, ",\"");
        index++;
    }
    
    // Sort the array using qsort()
    int numNames = index;
    qsort(names, numNames, sizeof(char *), compare);
    
    // Get name scores; since we start index at 0, we multiply the alphabetical
    // sum of the name by i+1
    int i, nameScore, sum = 0;
    for (i = 0; i < numNames; i++) {
        nameScore = (i+1) * alphabeticalSum(names[i]);
        sum += nameScore;
    }
    
    printf("%d\n", sum);
    fclose(fp);
}

int compare(const void *a, const void *b) {
    // a and b must be converted from const void* to const char*
    char * const *strA = a;
    char * const *strB = b;
    return strcmp(*strA, *strB);
}

int alphabeticalSum(char *str) {
    int i, sum = 0;
    for (i = 0; i < strlen(str); i++) {
        sum += alphabeticalValue(str[i]);
    }
    return sum;
}

int alphabeticalValue(char c) {
    switch(c) {
    case 'A': return 1;
    case 'B': return 2;
    case 'C': return 3;
    case 'D': return 4;
    case 'E': return 5;
    case 'F': return 6;
    case 'G': return 7;
    case 'H': return 8;
    case 'I': return 9;
    case 'J': return 10;
    case 'K': return 11;
    case 'L': return 12;
    case 'M': return 13;
    case 'N': return 14;
    case 'O': return 15;
    case 'P': return 16;
    case 'Q': return 17;
    case 'R': return 18;
    case 'S': return 19;
    case 'T': return 20;
    case 'U': return 21;
    case 'V': return 22;
    case 'W': return 23;
    case 'X': return 24;
    case 'Y': return 25;
    case 'Z': return 26;
    default: return 0;
    }
}
