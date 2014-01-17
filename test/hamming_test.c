#include <assert.h>
#include "../include/hamming.h"

int main(int argc, char *argv[])
{
    assert( hamming_dist("a", "aa") == -1 );
    assert( hamming_dist("same", "same") == 0 );
    assert( hamming_dist("tobi", "toby") == 1 );
    assert( hamming_dist("math", "meth") == 1 );     // just sayin'
    assert( hamming_dist("shovel", "shower") == 2 );

    return 0;
}

