#ifndef PEJSEK_H
#define PEJSEK_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "assets.h"
#include <SFML/System/Clock.hpp>

class Pejsek {

    private:
    sf::Texture texture; 
    sf::Sprite sprite;
    int score = 0;
    float CELL_SIZE = 25.0f;
    sf::Clock moveClock;
    float moveDelay = 0.1f; 
    public:
    void setMoveDelay(float delay) {
        moveDelay = delay;
    }
    Pejsek(int druhpejska) {
        Assets assets;
        switch (druhpejska) {
        case 0:
            texture = assets.getpejsek1();
            this->texture = texture;
            break;
        case 1:
             texture = assets.getpejsek2();
             this->texture = texture;
            break;
        case 2:
             texture = assets.getpejsek3();
             this->texture = texture;
            break;
       
        }
        sprite.setTexture(this->texture);
    }
    std::vector <sf::Vector2i> pohyb (std::vector <sf::Vector2i> move, std::vector <sf::Vector2i> position, std::vector<std::string>& maze)
    {
       
        for (size_t i = 0; i < position.size() && i < move.size(); ++i) {
        bool validmoved;
        int newX = position[i].x + move[i].x;
        int newY = position[i].y + move[i].y;
        if (moveClock.getElapsedTime().asSeconds() < moveDelay) {
        return position; 
        }
        moveClock.restart();
        if (newX >= 0 && newX < static_cast<int>(maze[0].size()) && newY >= 0 && newY < static_cast<int>(maze.size())) {
            
            if (maze[newY][newX] == '.'|| maze[newY][newX] == 'x'|| maze[newY][newX] == 'G') {
                validmoved = true;
            }
        }
                
        if (validmoved) {
            if (maze[newY][newX] == 'G') {
                for (size_t y = 0; y < maze.size(); ++y) {
                    for (size_t x = 0; x < maze[y].size(); ++x) {
                        if (maze[y][x] == 'G' && !(x == newX && y == newY)) {
                            newX = x;
                            newY = y;
                            goto foundG; 
                        }
                    }
                }
                    foundG:;
            }

            position[i] = sf::Vector2i(newX, newY);
            if (maze[newY][newX] == '.') {
                maze[newY][newX] = 'x';
                score++;
                std::cout << score << std::endl;
            }
        }
    }
    return position;

    }

    void kresli ( sf::RenderWindow& window, std::vector <sf::Vector2i>& position)
    {
        int ymov, xmov;
        xmov = position[0].x;
        ymov = position[0].y;

        float topLeftX =1.25f + xmov * CELL_SIZE;
        float topLeftY =1.25f + ymov * CELL_SIZE;

        sf::FloatRect spriteBounds = sprite.getGlobalBounds();
        float offsetX = (CELL_SIZE - spriteBounds.width) / 2;
        float offsetY = (CELL_SIZE - spriteBounds.height) / 2;

        sprite.setPosition(topLeftX + offsetX, topLeftY + offsetY);

         window.draw(sprite);
    }

    int getscore()
    {
        return score;
    }
};

#endif // PEJSEK_H