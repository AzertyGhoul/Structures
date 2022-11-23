#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

const int maxV = 122;
const int minV = 97;

int hash(char secondName)
{
    return ((((secondName - 96) * 20) + (secondName - 96 - 21)) * sizeof(char));
}

int main()
{
    srand(time(NULL));

    char letter = rand() % (maxV - minV + 1) + minV;

    int keys[526];
    int help[26];
    int counter = 0;
    int xPos = 20;

    for (int i = 0; i < 526; i++)
    {
        keys[i] = 0;
    }

    for (int i = 0; i < 10000; i++)
    {
        char letter = rand() % (maxV - minV + 1) + minV;
        int numberOfAddress = hash(letter);
        keys[numberOfAddress]++;
    }

    for (int i = 0; i < 526; i++)
    {
        if (keys[i] != 0)
        {
            help[counter] = i;
            counter++;
        }
    }

    sf::RenderWindow window(sf::VideoMode(580, 400), "5Lab");

    sf::VertexArray curve(sf::LinesStrip, 26);

    sf::VertexArray Ox(sf::LinesStrip, 2);
    sf::VertexArray Oy(sf::LinesStrip, 2);

    sf::Text legendOx;
    sf::Text legendOy;
    sf::Font font;

    font.loadFromFile("Roboto-Black.ttf");

    legendOx.setString("Address");
    legendOy.setString("Collisions");

    legendOy.setFont(font);
    legendOy.setFillColor(sf::Color::White);
    legendOy.setCharacterSize(15);
    legendOy.rotate(90);

    legendOx.setFont(font);
    legendOx.setFillColor(sf::Color::White);
    legendOx.setCharacterSize(15);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (int i = 0; i < 26; i++)
        {
            curve[i].position = sf::Vector2f((i + 2) * 20, 350 - keys[help[i]]);
            window.draw(curve);
        }

        Oy[0].position = sf::Vector2f(40, 20);
        Oy[1].position = sf::Vector2f(40, 350);
        legendOy.setPosition(40, 20);

        window.draw(legendOy);
        window.draw(Oy);

        Ox[0].position = sf::Vector2f(40, 350);
        Ox[1].position = sf::Vector2f(540, 350);
        legendOx.setPosition(260, 350);

        window.draw(legendOx);
        window.draw(Ox);

        window.display();
    }
    return 0;
}