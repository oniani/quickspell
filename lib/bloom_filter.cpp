/* 
 * File:   bloom_filter.cpp
 * Author: David Oniani
 * (c) 2019
 * Created on March 30, 2019
 * 
 * License:
 * Please read the LICENSE file in this distribution
 * for details regarding the licensing of this code.
 * THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND.
 * 
 * Description:
 * This file implements the functions declared in the header file.
 * 
 */

#include "bloom_filter.hpp"

// Constructor for the bloom filter data structure
BloomFilter::BloomFilter(std::vector<int> bit_vector) {
    this->bit_vector = bit_vector;
}

// Default, built-in hash function
unsigned int BloomFilter::hash_zero(std::string key) {
    unsigned int hash = std::hash<std::string>()(key);
    return hash;
}

// A simple hash function
unsigned int BloomFilter::hash_one(std::string key) {
    unsigned int hash = 0;
    for (int i = 0; i < key.length(); i++)
        hash ^= int(key[0]);

    return hash;
}

// Another simple hash function
unsigned int BloomFilter::hash_two(std::string key) {
    unsigned int hash = 0;
    for(int i = 0; i < key.length(); ++i) {
        hash += key[i] * std::pow(31, i);
    }
    return hash;
}

// Insert method for the bloom filter
void BloomFilter::insert(std::string key) {
    this->bit_vector[this->hash_zero(key) % this->bit_vector.size()] = 1;
    this->bit_vector[this->hash_one(key) % this->bit_vector.size()] = 1;
    this->bit_vector[this->hash_two(key) % this->bit_vector.size()] = 1;
}

// Search method for the bloom filter
bool BloomFilter::search(std::string key) {
    if (this->bit_vector[this->hash_zero(key) % this->bit_vector.size()] == 0) {
        return false;
    }

    if (this->bit_vector[this->hash_one(key) % this->bit_vector.size()] == 0) {
        return false;
    }

    if (this->bit_vector[this->hash_two(key) % this->bit_vector.size()] == 0) {
        return false;
    }

    return true;
}

// Show the contets of the bit vector
void BloomFilter::show() {
    std::cout << "<";
    for (auto word : this->bit_vector)
        std::cout << word << ", ";
    std::cout << ">" << std::endl;
}
