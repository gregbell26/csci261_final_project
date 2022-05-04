#include "ConsoleBuddy/Pixel.h"
#include "ConsoleBuddy/HelperStructures.h"
#include "ConsoleBuddy/Texture.h"


THS::Texture::Texture() :
    m_data(nullptr), m_textSize(new Size(0,0)), m_renderLocation(new Size(0,0))
{}




THS::Texture::Texture(const Texture& SRC) :
    m_data(nullptr), m_textSize(new Size(SRC.m_textSize->height, SRC.m_textSize->width)), 
    m_renderLocation(new Size(SRC.m_renderLocation->height, SRC.m_renderLocation->width))
{

    m_data = new Pixel*[SRC.m_textSize->height];

    for(unsigned int i = 0; i < SRC.m_textSize->height; i++){
        m_data[i] = new Pixel[SRC.m_textSize->width];
        for(unsigned int j = 0; j < SRC.m_textSize->width; j++){
            m_data[i][j] = SRC.m_data[i][j]; // deep copy w/ assingment op
        }
    }

}

THS::Texture::~Texture() {
    for(unsigned int i = 0; i < m_textSize->height; i++){
        delete m_data[i];
        m_data[i] = nullptr;
    }

    delete m_data;
    m_data = nullptr;

    delete m_renderLocation;
    m_renderLocation = nullptr;

    delete m_textSize;
    m_textSize = nullptr; 

}

THS::Texture& THS::Texture::operator=(const Texture& SRC) {
    // because this is completely reassigning it - we can delete the old object
    this->~Texture();

    //deep copy time!

    m_textSize = new Size(SRC.m_textSize->height, SRC.m_textSize->width);
    m_renderLocation= new Size(SRC.m_renderLocation->height, SRC.m_renderLocation->width);

    m_data = new Pixel*[SRC.m_textSize->height];

    for(unsigned int i = 0; i < SRC.m_textSize->height; i++){
        m_data[i] = new Pixel[SRC.m_textSize->width];
        for(unsigned int j = 0; j < SRC.m_textSize->width; j++){
            m_data[i][j] = SRC.m_data[i][j]; // deep copy w/ assingment op
        }
    }
    
    return *this;
    
}
THS::Texture& THS::Texture::operator=(Pixel** _src) {
    // for this assignmnet opperater we are only updating the pixel data 
    // we are keeping the size and everything the same
    // could lead to some issues later if the sizes are mis matched-- but we will burn that bridge when we get there

    for(unsigned int i = 0; i < m_textSize->height; i++){
        delete m_data[i];
        m_data[i] = nullptr;
    }

    delete m_data;
    // we dont need to set m_data to a null bc we are reassinging it anyway 
    m_data = new Pixel*[m_textSize->height];

    for(unsigned int i = 0; i < m_textSize->height; i++){
        m_data[i] = new Pixel[m_textSize->width];
        for(unsigned int j = 0; j < m_textSize->width; j++){
            m_data[i][j] = _src[i][j]; // deep copy w/ assingment op
        }
    }


    return *this;
}

void THS::Texture::setSize(const Size& SIZE){
    m_textSize = new Size(SIZE.height, SIZE.width);
}

void THS::Texture::setPosition(const Size& POS){
    m_renderLocation = new Size(POS.height, POS.width);
}

void THS::Texture::setData(Pixel** _data){
    m_data = _data;
}


THS::Pixel** THS::Texture::getData() const { return m_data; }
THS::Size* THS::Texture::getTextureSize() const { return m_textSize; }
THS::Size* THS::Texture::getRenderLoaction() const { return m_renderLocation; }