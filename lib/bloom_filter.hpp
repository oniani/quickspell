/*
 * File:   trie.hpp
 * Date:   04/24/2019
 * Author: David Oniani
 *
 * License:
 * Please read the LICENSE file in this distribution for details regarding
 * the licensing of this code.
 * THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND.
 *
 */

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H
#pragma once

#include <string>
#include <vector>
#include <cmath>

class BloomFilter {
    private:
        int size;
        int hash_count;
        std::vector<bool> bit_vector;
    public:
        BloomFilter(int, double);
        void insert(std::string);
        bool search(std::string);
};

#endif
