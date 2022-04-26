
#include "ConsoleBuddy/Pixel.h"

THS::Pixel::Pixel(const std::string _color, const char _value) :
    m_color(_color), m_value(_value)
{}

THS::Pixel::Pixel() : 
    m_color(""), m_value('\0')
{}

THS::Pixel::Pixel(const Pixel& SRC) :
    m_color(SRC.m_color), m_value(SRC.m_value)
{}

THS::Pixel THS::Pixel::createFromRGB(short _r, short _g, short _b, const char _value) {
    // do bounds check on r,g,b
    std::string strColor = createEscapeSeqFromRGB(_r, _g, _b);

    return Pixel(strColor, _value);
}  

std::string THS::Pixel::createEscapeSeqFromRGB(short _r, short _g, short _b) {
    std::string strColor = "\x1b[38;2;";
    strColor += std::to_string(_r) + ';';
    strColor += std::to_string(_g) + ';';
    strColor += std::to_string(_b);
    strColor += 'm';

    return strColor;
}

namespace THS{
    std::ostream& operator<<(std::ostream& _os, Pixel& src){
        _os << src.m_color << src.m_value;
        return _os;
    }

    std::istream& operator >> (std::istream& _is, Pixel& trgt){
        short r = 0, g = 0, b = 0;

        _is >> r >> g >> b;

        trgt.m_color = Pixel::createEscapeSeqFromRGB(r,g,b);
        trgt.m_value = 219;

        return _is;
    }
}

THS::Pixel& THS::Pixel::operator=(const Pixel& SRC) {
    this->~Pixel();

    this->m_color = SRC.m_color;
    this->m_value = SRC.m_value;

    return *this;
}