/* 
 * File:   spell_check_main.cpp
 * Author: David Oniani
 * (c) 2019
 * Created on March 29, 2019
 * 
 * License:
 * Please read the LICENSE file in this distribution
 * for details regarding the licensing of this code.
 * THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND.
 * 
 * Description:
 * This file is the primary app.
 * 
 */

#include "spellcheck.cpp"
#include "../lib/trie.cpp"

int main(int argc, char* argv[]) {
    // Initialize the trie
    Trie trie;
    trie.init();

    // Insert all the words
    for (std::string word : get_words("../data/normalized.words"))
        trie.insert(word);

    // Get the word to autocomplete
    if (argc < 2)
        return -1;

    std::string incomplete_word;
    std::string input = argv[1];
    std::stringstream ss = std::stringstream(input);
    ss >> incomplete_word;

    auto start = std::chrono::steady_clock::now();

    // Print out all possible autocompletions
    for (auto word : trie.autocomplete(incomplete_word))
        std::cout << word << std::endl;

    auto end = std::chrono::steady_clock::now();

    auto time_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "\nSUMMARY" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << "TOTAL NUMBER OF WORDS: " << trie.autocomplete_number(incomplete_word) << std::endl;
    std::cout << "TIME (MICROSECONDS): " << time_elapsed << std::endl;

    return 0;
}
