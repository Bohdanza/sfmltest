#include <bits/stdc++.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "myclass.hpp"

using namespace sf;

void convertImage(Image &source, Image &result)
{
    Vector2 resultSize=result.getSize();

    for(unsigned int i=0; i<resultSize.y; i++)
        for(unsigned int j=0; j<resultSize.x; j++)
        {
            unsigned char r=(source.getPixel({j*3, i}).r>0)*255;
            unsigned char g=(source.getPixel({j*3+1, i}).r>0)*255;
            unsigned char b=(source.getPixel({j*3+2, i}).r>0)*255;
            
            result.setPixel({j,i}, Color(r, g, b));
        }
}

int main()
{
    // create the window
    RenderWindow window(sf::VideoMode({500, 600}), "My window");
    
    Image sourceImage("Content/source.png");

    Vector2 rsz=sourceImage.getSize();

    Image resultImage({rsz.x/3, rsz.y}, Color::Black);

    convertImage(sourceImage, resultImage);

    Texture mainTexture;
    mainTexture.loadFromImage(resultImage);
    Sprite mainSprite(mainTexture);

    mainSprite.setPosition({50, 50});

    while (window.isOpen())
    {
        // check all the window's events that wer e triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        window.draw(mainSprite);

        // end the current frame
        window.display();
    }

    return 0;
}