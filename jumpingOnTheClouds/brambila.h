/*
 * C++ header file 
 * Includes the all C++03 standard libraries and brings them to the global
 * namespace.
 *  Created: 07/03/20
    Modified: 07/07/20
    Completed: 
 */
#ifndef CPP_03_STD_H
#define CPP_03_STD_H // #define variable value (macro-Constant)
                    // #define funtion(pareamiters) (valueReturned) (macro-Function)

#include <unordered_set>

#include <format>
#include <boost/format.hpp>

/* Utilities */
#include <cstdlib> // able to generate some random integers
#include <bitset>
#include <utility>
#include <ctime>
#include <cstddef>
#include <iterator> // for iterators

/* Dynamic memory management */
#include <new>
#include <memory>

/* Numeric limits */
#include <climits>
#include <cfloat>
#include <limits>

/* Error handling */
#include <exception>
#include <stdexcept>
#include <cassert>

/* Strings */
#include <cctype>
#include <cstring>
#include <string>

/* Containers */
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

/* Algorithms */
#include <algorithm>

/* Numerics */
#include <cmath>
#include <complex>
#include <valarray>
#include <numeric>

/* Input/Output */
#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <streambuf>
#include <cstdio>

/* Localization */
#include <locale>
#include <clocale>

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

using namespace std;

#endif


