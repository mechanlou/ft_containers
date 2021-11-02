#pragma once

#include "externals.hpp"

template<bool Cond, class T> struct ft::enable_if {};
template<class T> struct ft::enable_if<true, T> { typedef T type; };