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

void Trie::init() {
    this->head = new Trie();
    this->value = '\0';
    this->prefix_count = 0;
    this->is_end = false;
}

void Trie::insert(std::string word) {
    Trie* current = this->head;
    current->prefix_count++;

    for (char letter : word) {
        int index = letter - 'a';

        if (current->children[index] == NULL)
            current->children[index] = new Trie();
        
        current->value = letter;
        current->children[index]->prefix_count++;
        current = current->children[index];
    }

    current->is_end = true;
}

bool Trie::search(std::string word) {
    Trie* current = this->head;

    for (char letter : word) {
        int index = letter - 'a';

        if (current->children[index] == NULL)
            return false;
        
        current = current->children[index];
    }

    return current->is_end;
}

int Trie::words_with_prefix(std::string prefix) {
    Trie* current = this->head;

    for (char letter : prefix) {
        int index = letter - 'a';

        if (current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return current->prefix_count;
}


// WORK ON THIS!
std::string Trie::words_by_prefix(std::string prefix) {
    std::string result = "";
    Trie* current = this->head;

    for (char letter : prefix) {
        int index = letter - 'a';

        if (current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int count = 0;

    for (auto letter: alphabet) {
        int index = letter - 'a';

        if (current->children[index] != NULL) {
            current = current->children[index];
            count = 0;
        }

        else {
            if (count == 0) {
                result += current->value;
                count += 1;
            }
        }
    }

    return prefix + result;
}

Trie::~Trie() {
    if (this->head)
        this->head = NULL;
    delete this->head;

    if (this->children[26])
        this->children[26] = NULL;

    delete[] this->children[26];
}

Trie* Trie::get_head() {
    return this->head;
}

char Trie::get_value() {
    return this->value;
}

bool Trie::get_is_end() {
    return this->is_end;
}

int Trie::get_prefix_count() {
    return this->prefix_count;
}
