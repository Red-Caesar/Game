#include <iostream>
#include <SFML/Graphics.hpp>
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 700;
using namespace sf;
RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Doodle jump");

class Player{
private:
    float dx;
    float dy;
    float speed;
    Sprite player_sprite;
public:
    Player(Texture &player_texture){
        player_sprite.setTexture(player_texture);
        player_sprite.setTextureRect(IntRect(20,66,160,190));
        dx = WINDOW_WIDTH/2;
        dy = WINDOW_HEIGHT-190;
        player_sprite.setPosition(dx,dy);
    };
//    Sprite get_sprite(){
//        return player_sprite;
//    };
    void draw_player(){
        window.draw(player_sprite);
    }
};

int main() {



    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        Texture player_texture;
        player_texture.loadFromFile("..\\images/character_femaleAdventurer_cheer0.png");
//        Sprite player_sprite;
//        player_sprite.setTexture(player_texture);
//        player_sprite.setTextureRect(IntRect(20,66,160,190));
//        float dx = WINDOW_WIDTH/2;
//        float dy = WINDOW_HEIGHT;
//        player_sprite.setPosition(dx,dy);



        window.clear();
        Player girl(player_texture);
//        window.draw(girl.get_sprite());
        girl.draw_player();
//        window.draw(player_sprite);
        window.display();
    }
    return 0;
}
