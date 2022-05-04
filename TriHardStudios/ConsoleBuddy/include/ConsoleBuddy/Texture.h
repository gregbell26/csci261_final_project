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

        void setSize(const Size& SIZE);
        void setPosition(const Size& POS);
        void setData(Pixel** _data);


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