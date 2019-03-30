/* 
 * File:   spellcheck.hpp
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
 * This is a header file declaring a number of functions for the spell checker.
 * 
 */

#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <set>
#include <map>

// Reads a file with words and returns a vector of all the words
std::vector<std::string> get_words(std::string);

#endif
