/*
 * File:   spellcheck_main.cpp
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
 * This file implements the functions declared in the header file.
 *
 */

#include "spellcheck.hpp"

std::vector<std::string> get_words(std::string path_to_file) {
    std::vector<std::string> all_words;
    std::ifstream file(path_to_file);
    std::string word;

    if (!file.is_open())
        perror("Error while opening the file");

    while (std::getline(file, word))
        all_words.push_back(word);

    if (file.bad())
        perror("Error while reading the file");

    return all_words;
}
