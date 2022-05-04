#include "ConsoleBuddy/Pixel.h"

#include "ConsoleBuddy/HelperStructures.h"

THS::Size::Size(unsigned int _height, unsigned int _width) :
    height(_height), width(_width)
{}

bool THS::Size::operator != (const Size& SIZE) const {
    return !(this->height == SIZE.height && this->width == SIZE.width);
}

bool THS::Size::operator == (const Size& SIZE) const {
    return this->height == SIZE.height && this->width == SIZE.width;
}

bool THS::Size::operator >  (const Size& SIZE) const {
    return this->height > SIZE.height || this->width  > SIZE.width;
}
bool THS::Size::operator <  (const Size& SIZE) const {
    return this->height < SIZE.height || this->width  < SIZE.width;

}


THS::Buffer::Buffer(Pixel** _buffer, const Size* _size) :
    buffer(_buffer), size(_size)
{}