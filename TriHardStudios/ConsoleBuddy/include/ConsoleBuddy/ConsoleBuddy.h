#ifndef CONSOLE_BUDDY_H
#define CONSOLE_BUDDY_H

#ifdef CONSOLE_BUDDY_LIB

#include "Pixel.h"

#include "HelperStructures.h"

#include "Texture.h"


#include "Console.h"

#endif

namespace THS {


    Console* initalizeConsole();

    void addTexturesToBuffer(Buffer*& _buffer, Texture*& _textures, const unsigned int& NUM_TEXTURES);

    void addTexturesToBuffer(Pixel**& _buffer, const Size& BUFFER_SIZE, Texture*& _textures, const unsigned int& NUM_TEXTURES);



    void test(Console*& _console);

    


};

#endif // CONSOLE_BUDDY_H