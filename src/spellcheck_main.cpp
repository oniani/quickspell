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

#include "spellcheck.hpp"
#include "../lib/trie.cpp"

int main() {
    // std::cout << "Below are the words from the dictionary\n" << std::endl;

    // for (auto word : get_words("./data/linux.words"))
    //     std::cout << word << std::endl;
    
    Trie trie;
    trie.init();

    std::cout << "Pointer to the head of the trie: " << trie.get_head() << std::endl;
    std::cout << "The end of the trie: " << trie.get_is_end() << std::endl;

    trie.insert("harley");
    trie.insert("ham");
    trie.insert("hamburger");
    trie.insert("harley quinn");
    trie.insert("he");

    std::cout << "Word 'harley quinn': " << trie.search("harley quinn") << std::endl;
    std::cout << "Word 'ham': " << trie.search("ham") << std::endl;
    std::cout << "Word 'bam': " << trie.search("ha") << std::endl;

    std::cout << "Words with the prefix 'Har': " << trie.words_with_prefix("har") << std::endl;
    std::cout << "Current value: " << trie.get_value() << std::endl;

    std::cout << "Words with the prefix 'Har': " << trie.words_by_prefix("har") << std::endl;

    trie.~Trie();

    return 0;
}
