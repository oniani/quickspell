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
#include "../lib/bloom_filter.cpp"

int main(int argc, char* argv[]) {
    // Get the words out of the dictionary
    std::vector<std::string> words = get_words("../data/normalized.words");

    // Initialize the trie
    Trie trie;

    // Initialize the bloom filter
    BloomFilter bloom_filter = BloomFilter(words.size(), 0.0025);

    // Insert all the words
    for (std::string word : words) {
        trie.insert(word);
        bloom_filter.insert(word);
    }

    // Get the word to autocomplete
    if (argc < 2)
        return -1;

    std::string incomplete_word;
    std::string input = argv[1];
    std::stringstream ss = std::stringstream(input);
    ss >> incomplete_word;

    std::string incomplete_word_pretty_print = incomplete_word;

    // Convert the word to lowercase
    std::transform(incomplete_word.begin(), incomplete_word.end(), incomplete_word.begin(),
    [](unsigned char c){ return std::tolower(c); });

    // A variable to determine whether the pattern is a word
    bool is_word;

    // Start the timer
    auto start = std::chrono::steady_clock::now();

    // Check if the incomplete_word is the actual word
    if (!bloom_filter.search(incomplete_word))
        is_word = false;
    else
        if (trie.search(incomplete_word))
            is_word = true;

    // Print out all possible autocompletions
    for (auto word : trie.autocomplete(incomplete_word_pretty_print))
        std::cout << "\033[92m" + word.substr(0, incomplete_word_pretty_print.length()) +
            "\033[0m" + word.substr(incomplete_word_pretty_print.length(), word.length()) << std::endl;

    // End the timer
    auto end = std::chrono::steady_clock::now();

    // Calculate the elapsed time
    auto time_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Print out the statistics
    std::cout << "\n\033[93m\033[4mSUMMARY\033[0m" << std::endl;

    // Is the pattern a word?
    if (is_word)
        std::cout << "\033[93mYOUR PATTERN IS A WORD\033[0m\n" << std::endl;
    else
        std::cout << "\033[93mYOUR PATTERN IS NOT A WORD\033[0m\n" << std::endl;

    // What is the total number of words?
    std::cout << "\033[93mPOSSIBLE AUTOCOMPLETIONS: " << trie.autocomplete_number(incomplete_word) << std::endl;

    // What time did the program take?
    std::cout << "\033[93mTIME (MICROSECONDS):      " << time_elapsed << "\033[0m" << std::endl;

    return 0;
}
