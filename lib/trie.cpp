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

Trie::Trie() {
    this->root = new TrieNode();
}

int Trie::get_index(char letter) {
    return (std::isalnum(letter)) ? (std::tolower(letter) - 'a') : ALPHABET_SIZE - 1;
}

void Trie::insert(std::string word) {
    TrieNode* current = this->root;
    current->prefix_count++;

    for (char letter : word) {
        int index = Trie::get_index(letter);

        if (current->children[index] == NULL)
            current->children[index] = new TrieNode();

        current->value = letter;
        current->children[index]->prefix_count++;
        current = current->children[index];
    }

    current->is_end_of_word = true;
}

bool Trie::search(std::string word) {
    TrieNode* current = this->root;

    for (char letter : word) {
        int index = Trie::get_index(letter);

        if (current->children[index] == NULL)
            return false;
        
        current = current->children[index];
    }

    return current->is_end_of_word;
}

int Trie::autocomplete_number(std::string prefix) {
    TrieNode* current = this->root;

    for (char letter : prefix) {
        int index = Trie::get_index(letter);

        if (current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return current->prefix_count;
}

void Trie::traverse(std::string prefix, TrieNode* trie, std::vector<std::string>& all_words) {
    if (trie->is_end_of_word)
        all_words.push_back(prefix);

    for (unsigned int i = 0; i < ALPHABET_SIZE; i++)
        if (trie->children[i])
            traverse(prefix + (char) (i + 'a'), trie->children[i], all_words);
}

std::vector<std::string> Trie::autocomplete(std::string& prefix) {
    TrieNode* current = this->root;
    std::vector<std::string> result;

    for (unsigned int i = 0; i < prefix.length(); i++) {
        int index = Trie::get_index(prefix[i]);
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
