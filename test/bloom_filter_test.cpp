/*
 * This is an actual test file
 */

#include "catch.hpp"
#include "../lib/bloom_filter.cpp"

TEST_CASE( "Class BloomFilter is implemented", "[BloomFilter]" ) {
    BloomFilter bloom_filter0;
    BloomFilter bloom_filter1;
    BloomFilter* bloom_filter2;

    // 9 test cases are sufficient for all practical purposes.
    // Unfortunately, could not find a testing library similar
    // to QuickCheck (of Haskell) for property-based testing.
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();
    CHECK ();

    delete bloom_filter2;
}
