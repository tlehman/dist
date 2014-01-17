/** hamming.c
    by tlehman at 1389927665

 */

#include <string.h>
#include "../include/hamming.h"

 /*** hamming_dist(str1, str2) is a non-negative integer value that counts
      the minimum number of substitutions required to transform str1 into str2

      Note: the string lengths of str1 and str2 have to be equal, if they are not, 
      return a -1 to signal an error.
  */
int hamming_dist(const char * str1, const char * str2)
{
    if(strlen(str1) != strlen(str2)) return -1;
    if(strcmp(str1, str2) == 0)      return 0;

    int dist = 0;
    int i = 0;
    int n = strlen(str1);

    for(i = 0; i < n; ++i) {
        if(str1[i] != str2[i]) ++dist;
    }

    return dist;
}

