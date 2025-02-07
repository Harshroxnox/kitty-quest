#pragma once 
#include <iostream>
#include <cassert>

// Debug logging and assertions 
#ifdef DEBUG
    #define log(msg)  std::cout<< "[DEBUG] " << msg << std::endl
#else
    #define log(msg)
#endif
