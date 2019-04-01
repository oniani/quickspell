/*
 * This is an actual test file
 */

#include "catch.hpp"
#include "../lib/trie.cpp"


// 9 test cases are sufficient for all practical purposes.
// Unfortunately, could not find a testing library similar
// to QuickCheck (of Haskell) for the property-based testing.

TEST_CASE( "Class BloomFilter is implemented", "[Trie]" ) {
    Trie trie = Trie();

    CHECK (trie.get_head() == NULL);
    CHECK (trie.get_is_end() == false);
    CHECK (trie.get_prefix_count() == 0);
    // CHECK (trie.get_children() == NULL); // have to deal with this case
};
