#include <bits/stdc++.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "myclass.hpp"

using namespace sf;

int main()
{
    Texture bullsBody("Content/bull.png");
    bullsBody.setSmooth(false);

    Sprite bull(bullsBody);
    bull.setPosition({10, 10});
    bull.scale({4, 4});

    // create the window 
    RenderWindow window(sf::VideoMode({500, 600}), "My window");

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
        window.clear(sf::Color::Black);

        window.draw(bull);

        // end the current frame
        window.display();
    }

    return 0;
}