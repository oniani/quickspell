/* 
 * File:   trie.hpp
 * Date:   03/31/2019
 * Author: David Oniani
 * 
 * License:
 * Please read the LICENSE file in this distribution for details regarding
 * the licensing of this code.
 * THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND.
 * 
 */

#ifndef TRIE_H
#define TRIE_H
#pragma once

#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

class Trie {
    private:
        Trie* root;
        char value;
        bool is_end_of_word;
        int prefix_count;
        Trie* children[ALPHABET_SIZE];  // change it to 128 for all ASCII characters
        int get_index(char);
    public:
        // Trie(); // interesting...
        void init();
        void insert(std::string);
        bool search(std::string);
        int autocomplete_number(std::string);
        void traverse(std::string, Trie*, std::vector<std::string>&);
        std::vector<std::string> autocomplete(std::string&);
        ~Trie();

        // Getters for the outside access
        Trie* get_root();
        char get_value();
        bool get_is_end_of_word();
        int get_prefix_count();
};

#endif
