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

class Trie {
    private:
        Trie* head;
        char value;
        bool is_end;
        int prefix_count;
        Trie* children[26];
    public:
        // Trie(); // interesting...
        void init();
        void insert(std::string);
        bool search(std::string);
        int words_with_prefix(std::string);
        std::string words_by_prefix(std::string);
        ~Trie();

        // Getters for the outside access
        Trie* get_head();
        char get_value();
        bool get_is_end();
        int get_prefix_count();
};

#endif
