
#include <Mainframe.h>
#include <iostream>
#include <Ship.h>
#include <Wall.h>
#include <ClientActionEnum.h>

Mainframe::Mainframe(Client* client) {
    this->client = client;
}

void Mainframe::run()
{
    int windowWidth = 800;
    int windowHeight = 400;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "R-Type");



    while (window.isOpen())
    {
        sf::Event event;
        ClientActionEnum action = IDLE;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            action = UP;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            action = LEFT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            action = DOWN;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            action = RIGHT;

        std::cout << "action : " << action << std::endl;
        window.clear();

        for (auto &entity : entities)
            window.draw(entity.sprite);

        window.display();
        this->client->send_action(action);
    }

}