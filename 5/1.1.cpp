#include <SFML/Graphics.hpp>
#include <iostream>

const int maxV = 122;
const int minV = 97;

int hash(char secondName)
{
    return ((((secondName - 96) * 20) + (secondName - 96 - 21)) * sizeof(char));
}

int main()
{
    system("chcp 1251");
    srand(time(NULL));

    char letter = rand() % (maxV - minV + 1) + minV;

    int keys[526];

    for (int i = 0; i <= 526; i++)
    {
        keys[i] = 0;
    }

    for (int i = 0; i < 1000; i++)
    {
        char letter = rand() % (maxV - minV + 1) + minV;
        int numberOfAddress = hash(letter);
        keys[numberOfAddress]++;
    }

    sf::RenderWindow window(sf::VideoMode(525, 400), "5Lab");
    sf::VertexArray curve(sf::Lines, 800);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (int i = 0; i < 800; i++)
        {
            curve.append(sf::Vertex(sf::Vector2f(i, 350 - keys[i])));
            window.draw(curve);
        }
        window.display();
    }
    return 0;
}