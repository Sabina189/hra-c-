#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "assets.h"

void menu1(){

    sf::Color darkBlue(0, 0, 130);
    sf::Color lightBlue(173, 215, 230);

    sf::RenderWindow window(sf::VideoMode(750, 850), "Main Menu");
    window.setFramerateLimit(20);

    Assets assets;
    sf::Font font = assets.getFont();
    sf::Sprite pozadi(assets.getplochamenu());
    sf::Texture backgroundTexture = assets.getplochamenu();
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Text title("MAIN MENU", font, 120);
    title.setPosition(45, 80);
    title.setFillColor(darkBlue);
    title.setOutlineColor(lightBlue);
    title.setOutlineThickness(3);

    sf::Text play("Play", font, 70);
    play.setPosition(300, 300);
    play.setFillColor(darkBlue);
    play.setOutlineColor(lightBlue);
    play.setOutlineThickness(3);

    sf::Text options("Options", font, 70);
    options.setPosition(250, 400);
    options.setFillColor(darkBlue);
    options.setOutlineColor(lightBlue);
    options.setOutlineThickness(3);

    sf::Text quit("Quit", font, 70);
    quit.setPosition(300, 500);
    quit.setFillColor(darkBlue);
    quit.setOutlineColor(lightBlue);
    quit.setOutlineThickness(3);

    sf::Text back("Back", font, 30);
    back.setPosition(650, 20);
    back.setFillColor(darkBlue);
    back.setOutlineColor(lightBlue);
    back.setOutlineThickness(3);

    sf::Text chooseYourCharacter("Choose your character:", font, 60);
    chooseYourCharacter.setPosition(60, 100);
    chooseYourCharacter.setFillColor(darkBlue);
    chooseYourCharacter.setOutlineColor(lightBlue);
    chooseYourCharacter.setOutlineThickness(3);

    sf::Text easy("Easy", font, 70);
    easy.setPosition(300, 300);
    easy.setFillColor(darkBlue);
    easy.setOutlineColor(lightBlue);
    easy.setOutlineThickness(3);

    sf::Text medium("Medium", font, 70);
    medium.setPosition(250, 400);
    medium.setFillColor(darkBlue);
    medium.setOutlineColor(lightBlue);
    medium.setOutlineThickness(3);

    sf::Text hard("Hard", font, 70);
    hard.setPosition(300, 500);
    hard.setFillColor(darkBlue);
    hard.setOutlineColor(lightBlue);
    hard.setOutlineThickness(3);

    sf::Sprite sprites[3];
    sf::CircleShape selectionCircle(115);
    selectionCircle.setFillColor(sf::Color::Transparent);
    selectionCircle.setOutlineColor(darkBlue);
    selectionCircle.setOutlineThickness(10);

    sf::Texture textures[3] = {assets.getpes1(),assets.getpes2(),assets.getpes3() };
    
    for (int i = 0; i < 3; ++i) {
        sprites[i].setTexture(textures[i]);
        
    }
    
    sprites[0].setPosition(5, 230);
    sprites[1].setPosition(235, 230);
    sprites[2].setPosition(500, 235);

    bool menuActive = true; 
    bool showBackButton = false; 
    bool showOptions = false;
    bool characterSelected = false;
    bool difficultySelected = false;
    bool showDifficulty = false;
    int selectedCharacterIndex = -1;

    
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                    if (menuActive && quit.getGlobalBounds().contains(mousePosF)) {
                        window.close(); 
                    } else if (menuActive && options.getGlobalBounds().contains(mousePosF)) {
                        menuActive = false;
                        showBackButton = true; 
                        showOptions = true;
                        showDifficulty = false;
                    } else if (menuActive && play.getGlobalBounds().contains(mousePosF)) {
                        menuActive = false;
                        showBackButton = true;
                        showDifficulty = true;
                    } else if (showBackButton && back.getGlobalBounds().contains(mousePosF)) {
                        menuActive = true;
                        showBackButton = false;
                        showOptions = false;
                        showDifficulty = false;
                    } else if (showDifficulty && characterSelected == true) {
                        if (easy.getGlobalBounds().contains(mousePosF)) {
                            start_game(window, "easy", selectedCharacterIndex);
                        } else if (medium.getGlobalBounds().contains(mousePosF)) {
                            start_game(window,"medium", selectedCharacterIndex);
                        } else if (hard.getGlobalBounds().contains(mousePosF)) {
                            start_game(window, "hard", selectedCharacterIndex);
                    }
                     
                       } else if (showOptions) {
                            if (sprites[0].getGlobalBounds().contains(mousePosF)) {
                                characterSelected = true;
                                selectedCharacterIndex = 0;
                                assets.getpes1haf().play();
                            } else if (sprites[1].getGlobalBounds().contains(mousePosF)) {
                                characterSelected = true;
                                selectedCharacterIndex = 1;
                                assets.getpes2haf().play();
                            } else if (sprites[2].getGlobalBounds().contains(mousePosF)) {
                                characterSelected = true;
                                selectedCharacterIndex = 2;
                                assets.getpes3haf().play();
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);


        if (menuActive) {
            window.draw(title);
            window.draw(play);
            window.draw(options);
            window.draw(quit);
        } 
        
         if (showOptions) {
            window.draw(chooseYourCharacter);
            window.draw(back);
            for (int i = 0; i < 3; ++i) {
                window.draw(sprites[i]);
            }

           if (characterSelected) {
                selectionCircle.setPosition(sprites[selectedCharacterIndex].getPosition().x + sprites[selectedCharacterIndex].getGlobalBounds().width / 2 - selectionCircle.getRadius(),
                sprites[selectedCharacterIndex].getPosition().y + sprites[selectedCharacterIndex].getGlobalBounds().height / 2 - selectionCircle.getRadius());
                window.draw(selectionCircle);
            }
        } else if (showDifficulty) {
            window.draw(easy);
            window.draw(medium);
            window.draw(hard);
            window.draw(back);
        
        }

        window.display();
    }
}


#endif // MENU_H