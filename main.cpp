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
    float speed_down;

public:
    Sprite player_sprite;
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

    Texture player_texture;
    Player girl(player_texture);
    player_texture.loadFromFile("..\\images/character_femaleAdventurer_cheer0.png");

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                girl.player_sprite.move(-50, 0);
            } //первая координата Х отрицательна =>идём влево
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                girl.player_sprite.move(50, 0);
            } //первая координата Х положительна =>идём вправо
            if (Keyboard::isKeyPressed(Keyboard::Up)){
                girl.player_sprite.move(0, -50);
            } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
            if (Keyboard::isKeyPressed(Keyboard::Down)){
                girl.player_sprite.move(0, 50);

            }
            girl.player_sprite.setTextureRect(IntRect(20,66,160,190));
        }


        window.clear();

        girl.draw_player();
        window.display();
    }
    return 0;
}
