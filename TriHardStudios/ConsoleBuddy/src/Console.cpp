#include "ConsoleBuddy/Pixel.h"
#include "ConsoleBuddy/HelperStructures.h"
#include "ConsoleBuddy/Console.h"

#include <iostream>
#include <cassert>

#ifdef WINDOWS 
#include <Windows.h>

    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING // fix for campus computers bc the windows SDK is not the current version
        #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif

#endif // WINDOWS

THS::Console::Console(const THS::ConsoleConfig* _config):
    m_config(_config), m_bufferSize(_config->bufferSize)
{
    // process config here
    m_curBuffer = new Buffer(nullptr, m_bufferSize);
    m_nextBuffer = new Buffer(nullptr, m_bufferSize);

    if(!setUpConsole()){
        exit(-1);
    }
}

THS::Console::~Console() {
    // clean up all the shit
    delete m_config;
    delete m_curBuffer;
    delete m_nextBuffer;
    delete m_bufferSize;

    std::cout << "\033[?1049l";
    std::cout << "\033[?25h";
}


THS::Pixel**& THS::Console::getNextBuffer() const { return m_nextBuffer->buffer; }

const THS::Size* THS::Console::getBufferSize() const { return m_bufferSize; }


void THS::Console::swapBuffers() {
    // check if buffer is valid and then draw
    if(*m_bufferSize != *m_nextBuffer->size){
        std::cout << "An Error occurred while swapping buffers" << std::endl;
        return;
    }

    std::cout << m_curBuffer->buffer << std::endl;

    
    delete m_curBuffer; // clean up old buffer 
    m_curBuffer = m_nextBuffer;

    m_nextBuffer = new Buffer(nullptr, m_bufferSize);


    drawBuffer();
}


void THS::Console::drawBuffer() const {
    clearScreen();

    for(unsigned int i = 0; i < m_bufferSize->hieght; i++){
        for (unsigned int j = 0; j < m_bufferSize->width; j++){
            std::cout << m_curBuffer->buffer[i][j];
        }
        std::cout << '\n';
    }

    std::wcout.flush(); // after writing the buffer completely, send it to be displayed

}

void THS::Console::clearScreen() const{
    std::cout << "\033c";
}

bool THS::Console::setUpConsole() const {
    #ifdef WINDOWS
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE)
        {
            return false;
        }

        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode))
        {
            return false;
        }

        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (!SetConsoleMode(hOut, dwMode))
        {
            return false;
        }
    #endif // WINDOWS


    std::cout << "\033[?1049h";
    std::cout << "\033[?25l";
    clearScreen();
    return true;
}