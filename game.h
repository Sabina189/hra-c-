#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "game.cpp"

 // spouští start_game
void start_game(sf::RenderWindow& window, std::string difficulty, int pejsek);

#endif // GAME_H
