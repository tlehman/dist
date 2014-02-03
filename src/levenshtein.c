/** levenshtein.c
    by tlehman at 1391385132
 */
#include <string.h>
#include "../include/util.h"

 /*** levenshtein_dist(str1, str2) is a non-negative integer value that counts
      the minimum number of addtions, substitutions or deletions required to 
      transform str1 into str2

      Note: the string lengths of str1 and str2 do not have to be equal, if they are, 
      then levenshtein_dist is bounded above by hamming_dist. For example: the strings 
      "abcd" and "dabc" are hamming distance 4 apart, but with levenshtein distance, 
      you can delete the last d and append it to the beginning, so they are levenshtein 
      distance 2 apart.
  */
int levenshtein_dist_with_lengths(const char * str1, int n1, const char * str2, int n2)
{
    if(min(n1, n2) == 0) {
        return max(n1, n2);
    } else if(str1[n1-1] == str2[n2-1]) {
        return levenshtein_dist_with_lengths(str1, n1-1, str2, n2-1);
    } else {
        return 1 + min3( levenshtein_dist_with_lengths(str1, n1-1, str2, n2), 
                         levenshtein_dist_with_lengths(str1, n1,   str2, n2-1), 
                         levenshtein_dist_with_lengths(str1, n1-1, str2, n2-1) );
    }
}

int levenshtein_dist(const char * str1, const char * str2)
{
    return levenshtein_dist_with_lengths(str1, strlen(str1), str2, strlen(str2));
}

