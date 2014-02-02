/** levenshtein.c
    by tlehman at 1391385132
 */

 /*** levenshtein_dist(str1, str2) is a non-negative integer value that counts
      the minimum number of addtions, substitutions or deletions required to 
      transform str1 into str2

      Note: the string lengths of str1 and str2 do not have to be equal, if they are, 
      then levenshtein_dist is bounded above by hamming_dist. For example: the strings 
      "abcd" and "dabc" are hamming distance 4 apart, but with levenshtein distance, 
      you can delete the last d and append it to the beginning, so they are levenshtein 
      distance 2 apart.
  */
int levenshtein_dist(const char * str1, const char * str2)
{
    return 0;
}

