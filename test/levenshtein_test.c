#include <assert.h>
#include "../include/levenshtein.h"


int main(int argc, char *argv[])
{
    // Distance between identical strings is zero
    assert( levenshtein_dist("", "") == 0 );
    assert( levenshtein_dist("same", "same") == 0 );

    // Symmetry
    assert( levenshtein_dist("", "the") == 3 );
    assert( levenshtein_dist("the", "") == 3 );
    assert( levenshtein_dist("vim", "vm") == 1 );
    assert( levenshtein_dist("vm", "vim") == 1 );
    assert( levenshtein_dist("a", "as") == 1 );
    assert( levenshtein_dist("as", "a") == 1 );
    assert( levenshtein_dist("mathematical", "methodical") == 5 );
    assert( levenshtein_dist("methodical", "mathematical") == 5 );

    // Triangle Inequality
    assert( levenshtein_dist("string", "sting") + levenshtein_dist("sting", "ring") >= levenshtein_dist("string", "ring"));

    // transpositions are 2 units
    assert( levenshtein_dist("typographical", "tyopgraphical") == 2 );
 
    return 0;
}
