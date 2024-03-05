#pragma once


#include <SFML/Graphics.hpp>
#include "duch.h"
#include "pejsek.h"
#include <vector>
#include "assets.h"
#include "end.h"

// kontroluje podmínky pro ukončení hry
bool checkForEndCondition(const std::vector<std::string>& maze) {
    for (const auto& row : maze) {
        if (row.find('.') != std::string::npos) {
            return false; 
        }
    }
    return true; 
}

// hra
void start_game(sf::RenderWindow& window, std::string difficulty, int pejsek) {
    Assets assets;
    assets.gethra_pisnicka().play();
    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 850;
    
    window.setFramerateLimit(60);
    Pejsek Alex(pejsek);
    sf::Clock clock;
   
    sf::Color Blue(0, 0, 139);
    sf::Color lightBlue(33, 44, 143);
    sf::Color black(0, 0, 0);
    std::vector<std::string> maze = {
        "##############################",
        "##############################",
        "#x............##.............#",
        "#.####.######.##.######.####.#",
        "#.####.######.##.######.####.#",
        "#.####.######.##.######.####.#",
        "#............................#",
        "#.####.###.########.###.####.#",
        "#.####.###.########.###.####.#",
        "#......###...####...###......#",
        "#.####.#####.####.#####.####.#",
        "#.####.#####.####.#####.####.#",
        "#.####.###..........###.####.#",
        "#.####.###.###..###.###.####.#",
        "#.####.###.#......#.###.####.#",
        "G..........#......#..........G",
        "######.###.#......#.###.######",
        "######.###.########.###.######",
        "######.###..........###.######",
        "######.###.########.###.######",
        "######.###.########.###.######",
        "#.............##.............#",
        "#.####.######.##.######.####.#",
        "#.####.######.##.######.####.#",
        "#...##..................##...#",
        "###.##.##.##########.##.##.###",
        "###.##.##.##########.##.##.###",
        "#......##.....##.....##......#",
        "#.###########.##.###########.#",
        "#.###########.##.###########.#",
        "#.###########.##.###########.#",
        "#............................#",
        "##############################",
        "##############################",
    };

    int cellSize = std::min(SCREEN_WIDTH / static_cast<int>(maze[0].size()), SCREEN_HEIGHT / static_cast<int>(maze.size()));
    int outlineThickness = cellSize / 20;
   
    std::vector <sf::Vector2i> moveset;
    moveset.clear(); 
    moveset.push_back(sf::Vector2i(0, 0));

    std::vector <sf::Vector2i> currentpos;
    currentpos.clear(); 
    currentpos.push_back(sf::Vector2i(1, 2));

    sf::Font font = assets.getFont();
    
    int score = Alex.getscore();
    
    Duch duch(difficulty);
    sf::Texture duch1 = assets.getduch1();
    sf::Sprite duch1s(duch1);
    sf::Texture duch2 = assets.getduch2();
    sf::Sprite duch2s(duch2);
    sf::Texture duch3 = assets.getduch3();
    sf::Sprite duch3s(duch3);
    sf::Texture duch4 = assets.getduch4();
    sf::Sprite duch4s(duch4);
    sf::Texture duch5 = assets.getduch5();
    sf::Sprite duch5s(duch5);
    
    
    std::vector<sf::Vector2i> duchposition = duch.getlastknown();
    bool keypressed = false;
    bool contact = false;

    // hlavní smyčka hry
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed||keypressed == false) {
                moveset.clear(); 
                

                if (event.key.code==sf::Keyboard::Up) 
                {
                    moveset.clear(); 
                    moveset.push_back(sf::Vector2i( 0, -1));
                }
                if (event.key.code==sf::Keyboard::Down)
                {
                    moveset.clear(); 
                    moveset.push_back(sf::Vector2i(0, 1));
                }
                if (event.key.code==sf::Keyboard::Left)
                {
                    moveset.clear(); 
                    moveset.push_back(sf::Vector2i(-1, 0));
                }
                if (event.key.code==sf::Keyboard::Right)
                {
                    moveset.clear(); 
                    moveset.push_back(sf::Vector2i(1, 0));
                }
                keypressed = true;  
                currentpos = Alex.pohyb(moveset, currentpos, maze);
            }    
        }

        window.clear(black);

        for (size_t i = 0; i < maze.size(); ++i) {
            for (size_t j = 0; j < maze[i].size(); ++j) {
                if (maze[i][j] == '#') {
                    sf::RectangleShape outline(sf::Vector2f(cellSize, cellSize));
                    outline.setPosition(j * cellSize, i * cellSize);
                    outline.setFillColor(lightBlue);
                    window.draw(outline);

                    sf::RectangleShape wall(sf::Vector2f(cellSize - 2 * outlineThickness, cellSize - 2 * outlineThickness));
                    wall.setPosition(j * cellSize + outlineThickness, i * cellSize + outlineThickness);
                    wall.setFillColor(Blue);
                    window.draw(wall);  
                }
                if (maze[i][j] == '.') {
                    sf::CircleShape circle(cellSize / 8);
                    circle.setFillColor(sf::Color::White);
                    circle.setPosition(j * cellSize + cellSize / 2.0f, i * cellSize + cellSize / 2.0f);
                    circle.setOrigin(cellSize / 5, cellSize / 5);
                    window.draw(circle);
                    
                }
            }
        }
         if (clock.getElapsedTime().asSeconds() >= 0.1f){
            clock.restart();
            duchposition = duch.pohybduch(duchposition, maze);
            keypressed = false;
         }
         
        if (duchposition[0] == currentpos[0] || duchposition[1] == currentpos[0] || duchposition[2] == currentpos[0] || duchposition[3] == currentpos[0] || duchposition[4] == currentpos[0]) {
            contact = true;
        }
        duch1s.setPosition(duch.kresliducha(duchposition[0]));
        duch2s.setPosition(duch.kresliducha(duchposition[1]));
        duch3s.setPosition(duch.kresliducha(duchposition[2]));
        if (difficulty == "medium")
        {
        duch4s.setPosition(duch.kresliducha(duchposition[3]));
        }
        if (difficulty == "hard")
        {
        duch4s.setPosition(duch.kresliducha(duchposition[3]));
        duch5s.setPosition(duch.kresliducha(duchposition[4]));
        }

        score = Alex.getscore();
        sf::Text points("Score: " + std::to_string(score), font, 25);
        points.setPosition(10, 0);
        window.draw(points);
       
        Alex.kresli(window, currentpos);
        window.draw(duch1s);
        window.draw(duch2s);
        window.draw(duch3s);
        if (difficulty == "medium")
        {
             window.draw(duch4s);
        }
        if (difficulty == "hard")
        {
            window.draw(duch4s);
            window.draw(duch5s);
        }
        
        
        window.display();
        
        // konec hry v případě kontaktu charakteru s duchy
        if (contact == true) {
            assets.gethra_pisnicka().stop();
            assets.getprohra_song().play();
        end(window, score, 0, difficulty, pejsek); 
        }
        
        // konec hry v případě sesbíraných všech "." v bludišti
        if (checkForEndCondition(maze)) {
            assets.gethra_pisnicka().stop();
            assets.getwin_song().play();
        end(window, score, 1, difficulty, pejsek); 
        }
    }
}

