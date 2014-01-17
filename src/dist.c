/** dist: compute distances between strings
    by tlehman at 1389927665

 */
#include <stdio.h>
#include <string.h>
#include "../include/hamming.h"

void usage()
{
    printf("Usage: dist -h tribe pride\n");
}

void help()
{
    printf("dist: compute distances between strings\n");
    printf("  -h --hamming\tHamming Distance\n");
    printf("  -l --levenshtein\tLevenshtein Distance\n");
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        help();
        return 0;
    }

    if (strcmp(argv[1], "--help") == 0) help();

    if (argc != 4) {
        usage();
        return -1;
    }


    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--hamming") == 0) {
        printf("%d\n", hamming_dist(argv[2], argv[3]));
    }

    if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--levenshtein") == 0) {
    }
    return 0;
}

