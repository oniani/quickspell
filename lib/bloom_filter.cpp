/* 
 * File:   trie.cpp
 * Date:   04/24/2019
 * Author: David Oniani
 * 
 * License:
 * Please read the LICENSE file in this distribution for details regarding
 * the licensing of this code.
 * THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND.
 * 
 */

#include "bloom_filter.hpp"

BloomFilter::BloomFilter(int size, double false_positive_probability) {
    // The formula for the optimal size (the number of bits in the array) is (-n * ln p) / ln2^2
    this->size = (int) (-size * std::log(false_positive_probability)) / std::pow(std::log(2), 2);
    // The formula for the optimal number of hash functions is m / n * ln 2
    this->hash_count = (int) (this->size / size * std::log(2));
    this->bit_vector = std::vector<bool>(this->size);
}

void BloomFilter::insert(std::string word) {
    for (int i = 0; i < this->hash_count; i++) {
        int index = std::hash<std::string>()(word) % this->size;
        this->bit_vector[index] = true;
    }
}

bool BloomFilter::search(std::string word) {
    for (int i = 0; i < this->hash_count; i++) {
        int index = std::hash<std::string>()(word) % this->size;

        if (this->bit_vector[index] == false)
            return false;
    }

    return true;
}
