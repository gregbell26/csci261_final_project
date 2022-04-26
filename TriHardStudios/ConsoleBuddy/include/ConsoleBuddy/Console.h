#ifndef CONSOLE_H
#define CONSOLE_H

namespace THS{
    
    class Console {
    public:
        Console(const ConsoleConfig* _config);

        Console(const Console&) = delete;

        Console() = delete;

        ~Console();

        Pixel**& getNextBuffer() const;

        const Size* getBufferSize() const;

        
        
        void swapBuffers();

    private:
        void drawBuffer() const;

        void clearScreen() const;

        bool setUpConsole() const; 



    private:
        const ConsoleConfig* m_config;
        const Size* m_bufferSize;

        Buffer* m_curBuffer;
        Buffer* m_nextBuffer;

    };

};

#endif // CONSOLE_H