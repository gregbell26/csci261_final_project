#include "../include/ConsoleBuddy/ConsoleBuddy.h"



THS::Console* THS::initalizeConsole(){
    ConsoleConfig* config = new ConsoleConfig();

    config->bufferSize = new Size(64,64);
    config->name = "Test!";


    return new Console(config);
}


void THS::test(THS::Console*& _console){

    const std::string str = "I <3 Console Buddy";

    Pixel** buffer = _console->getNextBuffer();

    buffer = new Pixel*[1];
    buffer[0] = new Pixel[str.size()];

    for(unsigned int i = 0; i < str.size(); i++){
        buffer[0][i] = Pixel::createFromRGB(255,255,255, str[i]); // we are already performing a deep copy so we can let teh deconstucture handle it
    }

    _console->swapBuffers();





}