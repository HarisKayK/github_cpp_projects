#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <iostream>

// Clear input buffer
inline void clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Check for un-extracted input
inline bool unextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

// Check for failed input extraction
inline bool clearFailedExtraction()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            std::exit(0);
        }

        std::cin.clear();
        clearBuffer();

        return true;
    }

    return false;
}

#endif
