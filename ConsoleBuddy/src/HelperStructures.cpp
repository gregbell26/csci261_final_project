#include "../include/ConsoleBuddy/HelperStructures.h"

THS::Size::Size(unsigned int _hieght, unsigned int _width) :
    hieght(_hieght), width(_width)
{}

bool THS::Size::operator != (const Size& SIZE) const {
    return !(this->hieght == SIZE.hieght && this->width == SIZE.width);
}


THS::Buffer::Buffer(Pixel**& _buffer, const Size* _size) :
    buffer(_buffer), size(_size)
{}