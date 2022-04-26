#include "ConsoleBuddy/Pixel.h"
#include "ConsoleBuddy/HelperStructures.h"
#include "ConsoleBuddy/Console.h"

#include "ConsoleBuddy/ConsoleBuddy.h"

#include <iostream>

namespace THS {
    Console* initalizeConsole(){
        ConsoleConfig* config = new ConsoleConfig();

        config->bufferSize = new Size(50,100);
        config->name = "Test!";


        return new Console(config);
    }


    void test(Console*& _console){

        // const std::string str = "I <3 Console Buddy";

        Pixel**& buffer = _console->getNextBuffer();

        buffer = new Pixel*[50];
        buffer[0] = new Pixel[100];

        for(unsigned int i = 0; i <50; i++){
            buffer[i] = new Pixel[100];
            for(unsigned int j = 0; j < 100; j++){
                buffer[i][j] = Pixel::createFromRGB((i*50)%255,0,(j*25)%255, 219); // we are already performing a deep copy so we can let the deconstucture handle it
            }
        }

        _console->swapBuffers();





    }

};