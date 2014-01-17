/** hamming.h: the header file for the hamming distance function
    by tlehman at 1389927665
 */

 /*** hamming_dist(str1, str2) is a non-negative integer value that counts
      the minimum number of substitutions required to transform str1 into str2

      Note: the string lengths of str1 and str2 have to be equal, if they are not, 
      return a -1 to signal an error.
  */
int hamming_dist(const char * str1, const char * str2);
