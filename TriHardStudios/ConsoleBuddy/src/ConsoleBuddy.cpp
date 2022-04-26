#include "../include/ConsoleBuddy/Pixel.h"
#include "../include/ConsoleBuddy/HelperStructures.h"
#include "../include/ConsoleBuddy/Console.h"

#include "../include/ConsoleBuddy/ConsoleBuddy.h"

#include <iostream>

namespace THS {
    Console* initalizeConsole(){
        ConsoleConfig* config = new ConsoleConfig();

        config->bufferSize = new Size(1,18);
        config->name = "Test!";


        return new Console(config);
    }


    void test(Console*& _console){

        const std::string str = "I <3 Console Buddy";

        Pixel**& buffer = _console->getNextBuffer();

        buffer = new Pixel*[1];
        buffer[0] = new Pixel[str.size()];

        for(unsigned int i = 0; i < str.size(); i++){
            buffer[0][i] = Pixel::createFromRGB((i*50)%255,0,(i*25)%255, str[i]); // we are already performing a deep copy so we can let the deconstucture handle it
        }

        _console->swapBuffers();





    }

};