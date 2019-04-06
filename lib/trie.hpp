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

#include <string>
#include <vector>

const int ALPHABET_SIZE = 128;

struct TrieNode {
    bool is_end_of_word;
    TrieNode* children[ALPHABET_SIZE];
    char value;
    int prefix_count;
};

class Trie {
    private:
        TrieNode* root;
        int get_index(char);
    public:
        Trie();
        void insert(std::string);
        bool search(std::string);
        int autocomplete_number(std::string);
        void traverse(std::string, TrieNode*, std::vector<std::string>&);
        std::vector<std::string> autocomplete(std::string&);
        ~Trie();

        // Getters for the outside access
        TrieNode* get_root();
        char get_value();
        bool get_is_end_of_word();
        int get_prefix_count();
};

#endif
