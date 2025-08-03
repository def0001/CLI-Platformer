#include <iostream>

class Map {
  private:
    int size;
    int mapPosX;
    int mapPosY;
  public:
    void DrawMap(int mapSize, int posX, int posY) {
      size = mapSize;
      mapPosX = posX;
      mapPosY = posY;

      std::cout << "\033[" << mapPosY << ";" << mapPosX << "H";
      for (int i = 0; i < size; i++)
        std::cout << "-";
    }
    void DrawNumbersY(int size) {
      for (int i = 0; i < size; i++)
        std::cout << "\033[" << i+1 << ";0H" << i;

    }
    void ClearMap() {
      std::cout << "\033[2J";
    }
};

class Player {
  private:
    int health;
    int positionX;
    int positionY;
  public:
    void MovePlayer(int posX, int posY) {
      positionX = posX;
      positionY = posY;
      std::cout << "\033[" << positionY << ";" << positionX << "H@";
    }

    Player(int healthCount) {
      health = healthCount;
    }
    char GetPlayerInput() {
      return std::getchar();
    }
    void DrawPlayerInput(int infoPosX = 0, int infoPosY = 0) {
      std::cout << "\033[" << infoPosY << ";" << infoPosX << "H Input: ";
    }
};

int main() {
  int mapSize = 32;
  int mapPosX = 5;
  int mapPosY = 3;

  int playerHealth = 23;
  int playerPosX = 5;
  int playerPosY = mapPosY-1;

  int doWhile = 1;

  char PlayerInput = '0';
  
  Map map;
  Player player(23);
  
  map.ClearMap();
  std::cout << "\033[0;0H";
  std::cout << "The game version: 0.1\n";
  std::cout << "The game author: \"the white tea\" (GitHub)\n\n";
  std::cout << "Controls (Key+Enter):\n  Keys:\n";
  std::cout << "    d - move player to right\n";
  std::cout << "    a - move player to left\n";
  std::cout << "    K - exit the game (return 0)\n";
  std::cout << "You can also combine keys. Example: dd+a+K - move to right 2 times, move to left and exit\n";
  std::cout << "\nWelcome to the CLI Platformer! To start the game, press Enter: ";
  
  while (doWhile != 0) {
    PlayerInput = player.GetPlayerInput();

    if (PlayerInput == 'd')
      playerPosX++;
    else if (PlayerInput == 'a')
      playerPosX--;
    else if (PlayerInput == 'K')
      return 0;

    map.ClearMap();
    map.DrawNumbersY(7);
    map.DrawMap(mapSize, mapPosX, mapPosY);
    player.MovePlayer(playerPosX, playerPosY); // X, Y
    player.DrawPlayerInput(3, mapPosY+3);
  }
  return 0;
}
