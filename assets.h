#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Inicializace všech používaných obrázků|zvuků ve hře.
class Assets {
private:
    sf::Font font;
    sf::Texture plochamenu;
    sf::Texture pes1;
    sf::Texture pes2;
    sf::Texture pes3;
    sf::Texture duch1;
    sf::Texture duch2;
    sf::Texture duch3;
    sf::Texture duch4;
    sf::Texture duch5;
    sf::Texture pejsek1;
    sf::Texture pejsek2;
    sf::Texture pejsek3;
    sf::Music pes1haf;
    sf::Music pes2haf;
    sf::Music pes3haf;
    sf::Music hra_pisnicka;
    sf::Music win_pisnicka;
    sf::Music prohra_pisnicka;

public:
    Assets() {};


    sf::Font getFont() {
        font.loadFromFile("asset/aptos-black.ttf");
        return font;
    }

    sf::Texture getplochamenu() {
        plochamenu.loadFromFile("asset/plochamenu.png");
        return plochamenu;
    }

    sf::Texture getpes1() {
        pes1.loadFromFile("asset/pes_velky1.png");
        return pes1;
    }
    

    sf::Texture getpes2() {
        pes2.loadFromFile("asset/pes_velky2.png");
        return pes2;
    }

    sf::Texture getpes3() {
        pes3.loadFromFile("asset/pes_velky3.png");
        return pes3;
    }

    sf::Texture getduch1() {
        duch1.loadFromFile("asset/duch1.png");
        return duch1;
    }

    sf::Texture getduch2() {
        duch2.loadFromFile("asset/duch2.png");
        return duch2;
    }

    sf::Texture getduch3() {
        duch3.loadFromFile("asset/duch3.png");
        return duch3;
    }

    sf::Texture getduch4() {
        duch4.loadFromFile("asset/duch4.png");
        return duch4;
    }

    sf::Texture getduch5() {
        duch5.loadFromFile("asset/duch5.png");
        return duch5;
    }

    sf::Texture getpejsek1() {
        pejsek1.loadFromFile("asset/pes_maly1.png");
        return pejsek1;
    }

    sf::Texture getpejsek2(){
        pejsek2.loadFromFile("asset/pes_maly2.png");
        return pejsek1;
    }

    sf::Texture getpejsek3(){
        pejsek3.loadFromFile("asset/pes_maly3.png");
        return pejsek3;
    }

    sf::Music& getpes1haf() {
        pes1haf.openFromFile("asset/pes1_haf.mp3");
        return pes1haf;
    }

    sf::Music& getpes2haf() {
        pes2haf.openFromFile("asset/pes2_haf.mp3");
        return pes2haf;
    }

    sf::Music& getpes3haf() {
        pes3haf.openFromFile("asset/pes3_haf.mp3");
        return pes3haf;
    }
    sf::Music& gethra_pisnicka() {
        hra_pisnicka.openFromFile("asset/hra_pisnicka.mp3");
        return hra_pisnicka;
    }

    sf::Music& getwin_song() {
        win_pisnicka.openFromFile("asset/win_song.mp3");
        return win_pisnicka;
    }

    sf::Music& getprohra_song() {
        prohra_pisnicka.openFromFile("asset/game_over1.mp3");
        return prohra_pisnicka;
    }
};

#endif // ASSETS_H
