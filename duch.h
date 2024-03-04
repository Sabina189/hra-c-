#ifndef DUCH_H
#define DUCH_H

#include "assets.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <algorithm>

class Duch{
    std::vector<sf::Vector2i> lastknown = { {28,1}, {16,12}, {1,28}, {16,12}, {28,1} };
    private: 
    
    public:
    Duch(std::string obtiznost){
       if (obtiznost == "easy"){
           lastknown = { {28,1}, {16,12}, {1,28} };
       } 
       else if (obtiznost == "medium"){
           lastknown = { {28,1}, {16,12}, {1,28}, {16,12} };
       }
       else if (obtiznost == "hard"){
           lastknown = { {28,1}, {16,12}, {1,28}, {16,12}, {28,1} };
       }
    };

    std::vector<sf::Vector2i> getlastknown()
    {
        return lastknown;
    }

    std::vector<sf::Vector2i> pohybduch(std::vector<sf::Vector2i> current, const std::vector<std::string>& maze) {
        std::vector<sf::Vector2i> newPositions; 
        std::vector<sf::Vector2i> directions = {
            sf::Vector2i(0, -1), 
            sf::Vector2i(0, 1),  
            sf::Vector2i(-1, 0), 
            sf::Vector2i(1, 0)   
        };

        for (size_t i = 0; i < current.size(); ++i) {
            auto& curPos = current[i];
            std::vector<sf::Vector2i> validDirections;

            for (const auto& dir : directions) {
                sf::Vector2i newPos = curPos + dir;

                if ((maze[newPos.y][newPos.x] == 'x' || maze[newPos.y][newPos.x] == '.') &&
                    (lastknown.empty() || (lastknown.size() > i && newPos != lastknown[i])) &&
                    newPos != curPos) {
                    validDirections.push_back(dir);
                }
            }

            if (!validDirections.empty()) {
                int randomIndex = rand() % validDirections.size(); 
                sf::Vector2i chosenDirection = validDirections[randomIndex];
                sf::Vector2i newPosition = curPos + chosenDirection;
                newPositions.push_back(newPosition);
            } else {
                newPositions.push_back(curPos);
            }
        }

        lastknown = current;

        return newPositions;
    }
    sf::Vector2f kresliducha ( sf::Vector2i current)
    {
        int CELL_SIZE = 25;
        int ymov, xmov;
        xmov = current.x;
        ymov = current.y;

        float topLeftX =1.25f + xmov * CELL_SIZE;
        float topLeftY =1.25f + ymov * CELL_SIZE;
         
        float offsetX = (CELL_SIZE - 40) / 2;
        float offsetY = (CELL_SIZE - 40) / 2;

        sf::Vector2f pozice = sf::Vector2f(topLeftX + offsetX, topLeftY + offsetY);
        
        return pozice;
    }
};

#endif // DUCH_H