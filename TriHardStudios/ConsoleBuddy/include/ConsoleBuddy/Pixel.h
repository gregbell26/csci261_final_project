#ifndef PIXEL_H
#define PIXEL_H

#include <ostream>
#include <istream>
#include <string>

namespace THS {
class Pixel {
    public:
        Pixel(const std::string _color, const char _value);

        Pixel(const Pixel& SRC);

        Pixel();

        static Pixel createFromRGB(short _r, short _g, short _b, const char _value);

        friend std::ostream& operator << (std::ostream& _os, Pixel& src);

        friend std::istream& operator >> (std::istream& _is, Pixel& trgt);

        Pixel& operator=(const Pixel& SRC);

    private:
        static std::string createEscapeSeqFromRGB(short _r, short _g, short _b);

    private:
        std::string m_color;
        char m_value;
    };
};

#endif // PIXEL_H