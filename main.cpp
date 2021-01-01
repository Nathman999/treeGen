//To compile
// g++ main.cpp -o main -LC:/SFML/lib -IC:/SFML/include -lsfml-system -lsfml-graphics -lsfml-window -lopenal32 -mwindows

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    // sf::CircleShape shape(100.f);
    sf::RectangleShape rect(sf::Vector2f(100.f,100.f));
    // shape.setFillColor(sf::Color::Green);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}