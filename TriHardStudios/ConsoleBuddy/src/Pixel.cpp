
#include "../include/ConsoleBuddy/Pixel.h"

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
    std::string strColor = "\x1b[38;2;";
    strColor += std::to_string(_r) + ';';
    strColor += std::to_string(_g) + ';';
    strColor += std::to_string(_b);
    strColor += 'm';

    return Pixel(strColor, _value);
}  

namespace THS{
    std::ostream& operator<<(std::ostream& _os, Pixel& SRC){
        _os << SRC.m_color << SRC.m_value;
        return _os;
    }
}

THS::Pixel& THS::Pixel::operator=(const Pixel& SRC) {
    this->~Pixel();

    this->m_color = SRC.m_color;
    this->m_value = SRC.m_value;

    return *this;
}