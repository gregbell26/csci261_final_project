#ifndef TEXTURE_H
#define TEXTURE_H

namespace THS {

    class Texture {
    public:
        Texture();
        Texture(const Texture& SRC);

        ~Texture();

        Texture& operator=(const Texture& SRC);
        Texture& operator=(Pixel** _SRC);


        Pixel** getData() const;
        Size* getTextureSize() const;
        Size* getRenderLoaction() const;


        
    private:
        Pixel** m_data;
        Size* m_textSize;
        Size* m_renderLocation;
    };


};


#endif // TEXTURE_H