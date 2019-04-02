/* 
 * File:   trie.cpp
 * Date:   03/31/2019
 * Author: David Oniani
 * 
 * License:
 * Please read the LICENSE file in this distribution for details regarding
 * the licensing of this code.
 * THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND.
 * 
 */

#include "trie.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <set>


void Trie::init() {
    this->root = new Trie();
    this->value = '\0';
    this->prefix_count = 0;
    this->is_end_of_word = false;
}

int Trie::get_index(char letter) {
    return (std::isalnum(letter)) ? (std::tolower(letter) - 'a') : ALPHABET_SIZE - 1;
}

void Trie::insert(std::string word) {
    Trie* current = this->root;
    current->prefix_count++;

    for (char letter : word) {
        int index = Trie::get_index(letter);

        if (current->children[index] == NULL)
            current->children[index] = new Trie();

        current->value = letter;
        current->children[index]->prefix_count++;
        current = current->children[index];
    }

    current->is_end_of_word = true;
}

bool Trie::search(std::string word) {
    Trie* current = this->root;

    for (char letter : word) {
        int index = Trie::get_index(letter);

        if (current->children[index] == NULL)
            return false;
        
        current = current->children[index];
    }

    return current->is_end_of_word;
}

int Trie::autocomplete_number(std::string prefix) {
    Trie* current = this->root;

    for (char letter : prefix) {
        int index = Trie::get_index(letter);

        if (current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return current->prefix_count;
}

void Trie::traverse(std::string prefix, Trie* trie, std::vector<std::string>& all_words) {
    if (trie->is_end_of_word)
        all_words.push_back(prefix);

    for (uint i = 0; i < ALPHABET_SIZE; i++)
        if(trie->children[i])
            traverse(prefix + (char) (i + 'a'), trie->children[i], all_words);
}

std::vector<std::string> Trie::autocomplete(std::string& prefix) {
    Trie* current = this->root;
    std::vector<std::string> result;

    for(uint i = 0; i < prefix.length(); i++) {
        int index = Trie::get_index(prefix.at(i));
        current = current->children[index];
    }

    Trie::traverse(prefix, current, result);

    return result;
}

Trie::~Trie() {
    if (this->root)
        this->root = NULL;
    delete this->root;
}

Trie* Trie::get_root() {
    return this->root;
}

char Trie::get_value() {
    return this->value;
}

bool Trie::get_is_end_of_word() {
    return this->is_end_of_word;
}

int Trie::get_prefix_count() {
    return this->prefix_count;
}
