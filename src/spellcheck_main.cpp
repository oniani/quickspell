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

int main() {
    std::cout << "Below are the words from the dictionary\n" << std::endl;

    for (auto word : get_words("./data/linux.words"))
        std::cout << word << std::endl;

    return 0;
}
