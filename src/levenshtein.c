/** levenshtein.c
    by tlehman at 1459052110
 */
#include <stdio.h>
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
const int MATCH = 0;
const int INSERT = 1;
const int DELETE = 2;

int levenshtein_dist(const char * str1, const char * str2)
{
  int i, j, k;
  int opt[3];      /* cost of three options */
  int n1 = strlen(str1);
  int n2 = strlen(str2);
  int m[n1+1][n2+1];

  // initialize cost matrix at lower boundaries
  for(i=0; i < n1+1; i++) {
    m[i][0] = i;
  }
  for(j=0; j < n2+1; j++) {
    m[0][j] = j;
  }

  

  for(i=1; i < n1+1; i++) {
    for(j=1; j < n2+1; j++) {
      opt[MATCH] = m[i-1][j-1] + ((str1[i] == str2[j]) ? 0 : 1);
      opt[INSERT] = m[i][j-1] + 1;
      opt[DELETE] = m[i-1][j] + 1;

      m[i][j] = opt[MATCH];
      for (k = INSERT; k <= DELETE; k++) {
        if(opt[k] < m[i][j]) {
          m[i][j] = opt[k];
        }
      }
    }
  }

  return m[i-1][j-1];
}

