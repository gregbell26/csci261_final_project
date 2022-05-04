#include "ConsoleBuddy/Pixel.h"
#include "ConsoleBuddy/HelperStructures.h"
#include "ConsoleBuddy/Texture.h"
#include "ConsoleBuddy/Console.h"

#include "ConsoleBuddy/ConsoleBuddy.h"

#include <iostream>

THS::Console* THS::initalizeConsole(){
    ConsoleConfig* config = new ConsoleConfig();

    config->bufferSize = new Size(50,100);
    config->name = "Test!";


    return new Console(config);
}


void THS::test(THS::Console*& _console){

    // const std::string str = "I <3 Console Buddy";

    Pixel** textureData = new Pixel*[10];


    Texture test;

    test.setPosition({5,5});
    test.setSize({10,10});


    for(unsigned int i = 0; i <10; i++){
        textureData[i] = new Pixel[10];
        for(unsigned int j = 0; j < 10; j++){
            textureData[i][j] = Pixel::createFromRGB((i*50)%255,0,(j*25)%255, 219); // we are already performing a deep copy so we can let the deconstucture handle it

        }
    }

    test = textureData;

    Texture* textures = new Texture[1];
    textures[0] = test;

    addTexturesToBuffer(_console->getNextBuffer(), *_console->getBufferSize(), textures, 1);

    _console->swapBuffers();

}

void THS::addTexturesToBuffer(Pixel**& _buffer, const Size& BUFFER_SIZE, Texture*& _textures, const unsigned int& NUM_TEXTURES){
    // this code is gonna be so ineffeint - im sorry - this should be done with a queue or linked list or something other than what im doing

    const unsigned int BUFFER_HEIGHT = BUFFER_SIZE.height;

    const unsigned int BUFFER_WIDTH = BUFFER_SIZE.width;

    const Size ZERO_SIZE = {0,0};

    Pixel* blackPixel= new Pixel(0,0,0, 219);

    if(BUFFER_HEIGHT == 0 || BUFFER_WIDTH == 0){
        return;
    }

    if(NUM_TEXTURES == 0) {
        return;
    }

    for(unsigned int i = 0; i < BUFFER_HEIGHT; i++ ){
        for(unsigned int j = 0; j < BUFFER_WIDTH; j++){
            _buffer[i][j] = blackPixel;
        }
    }
    

    for(unsigned int textCounter = 0; textCounter < NUM_TEXTURES; textCounter++){
        if(*_textures[textCounter].getRenderLoaction() > BUFFER_SIZE){
            continue;
        }
        if(*_textures[textCounter].getTextureSize() > BUFFER_SIZE){
            continue;
        }
        if (*_textures[textCounter].getTextureSize() == ZERO_SIZE){
            continue;
        }

        unsigned int endingHeight = _textures[textCounter].getRenderLoaction()->height + _textures[textCounter].getTextureSize()->height;
        unsigned int endingWidth = _textures[textCounter].getRenderLoaction()->width + _textures[textCounter].getTextureSize()->width;

        if( endingHeight > BUFFER_HEIGHT){
            // the end of the height of the texture is out of range
            continue;
        }
        if( endingWidth > BUFFER_WIDTH){
            // the end of the width of the texture is out of range
            continue;
        }

        for(unsigned int i = _textures[textCounter].getRenderLoaction()->height; i < endingHeight; i++){
            for(unsigned int j =_textures[textCounter].getRenderLoaction()->width; j < endingWidth; j++){

                // _buffer[i][j] = &(_textures[textCounter].getData()[i][j]); // this should shallow copy and not seg fault but we shall see
                _buffer[i][j] = _textures[textCounter].getData()[i][j];
            }
        }


    }


}


void THS::addTexturesToBuffer(THS::Buffer*& _buffer, THS::Texture*& _textures, const unsigned int& NUM_TEXTURES){
    addTexturesToBuffer(_buffer->buffer, *_buffer->size, _textures, NUM_TEXTURES);
}

