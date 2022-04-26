#ifndef PIXEL_H
#define PIXEL_H

#include <ostream>
#include <string>

namespace THS {
class Pixel {
    public:
        Pixel(const std::string _color, const char _value);

        Pixel(const Pixel& SRC);

        Pixel();

        static Pixel createFromRGB(short _r, short _g, short _b, const char _value);

        friend std::ostream& operator<<(std::ostream& _os, Pixel& SRC);

        Pixel& operator=(const Pixel& SRC);

    private:
        std::string m_color;
        char m_value;
    };
};

#endif // PIXEL_H