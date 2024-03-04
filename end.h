#ifndef END_H
#define END_H
#include <SFML/Graphics.hpp>
#include "assets.h"
#include <string>
#include "game.h"
#include "menu.h"


void end(sf::RenderWindow& window, int score, int state, std::string difficulty, int pejsek){

    std::string text;
    switch(state){
        case 0:
        text = "GAME OVER!";
        break;
        case 1:
        text = "YOU WIN!!";
        break;
    }

    sf::Color darkBlue(0, 0, 130);
    sf::Color lightBlue(173, 215, 230);

    Assets assets;
    sf::Font font = assets.getFont();
    sf::Sprite pozadi(assets.getplochamenu());
    sf::Texture backgroundTexture = assets.getplochamenu();
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Text title(text, font, 110);
    title.setPosition(45, 80);
    title.setFillColor(darkBlue);
    title.setOutlineColor(lightBlue);
    title.setOutlineThickness(3);

    sf::Text menu("Menu", font, 70);
    menu.setPosition(300, 270);
    menu.setFillColor(darkBlue);
    menu.setOutlineColor(lightBlue);
    menu.setOutlineThickness(3);

    sf::Text play_again("Play again", font, 70);
    play_again.setPosition(240, 370);
    play_again.setFillColor(darkBlue);
    play_again.setOutlineColor(lightBlue);
    play_again.setOutlineThickness(3);

    std::string str = std::to_string(score);
    sf::Text score("Score:  " + str, font, 40);
    score.setPosition(90, 730);
    score.setFillColor(darkBlue);
    score.setOutlineColor(lightBlue);
    score.setOutlineThickness(3);

    
    sf::Text quit("Quit", font, 70);
    quit.setPosition(300, 470);
    quit.setFillColor(darkBlue);
    quit.setOutlineColor(lightBlue);
    quit.setOutlineThickness(3);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            void start_game(sf::RenderWindow& window, std::string difficulty, int pejsek);
            void menu1();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (menu.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                        menu1();      
                    }
                    if (play_again.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        start_game(window, difficulty, pejsek);
                    }
                    if (quit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                    }
                }
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(title);
        window.draw(menu);
        window.draw(play_again);
        window.draw(score);
        window.draw(quit);
        window.display();
    }
}


#endif // END_H