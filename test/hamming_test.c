#include <assert.h>
#include "../include/hamming.h"

int main(int argc, char *argv[])
{
    assert( hamming_dist("a", "aa") == -1 );
    assert( hamming_dist("aa", "aa") == 0 );

    return 0;
}

