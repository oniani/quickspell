/* 
 * File:   bloom_filter.hpp
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
 * This is a header file declaring the constructor and a number of functions for the bloom filter.
 * 
 */

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <set>
#include <map>

class BloomFilter {
    private:
        std::vector<int> bit_vector;
        unsigned int hash_zero(std::string);
        unsigned int hash_one(std::string);
        unsigned int hash_two(std::string);
    public:
        BloomFilter(std::vector<int>);
        void insert(std::string);
        bool search(std::string);
        void show();
};

#endif
