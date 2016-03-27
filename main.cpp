#include <iostream>
#include "src/MainClass.h"

using namespace std;

int main() {

    atg::MainClass *game = new atg::MainClass("At The Gates", 0,0,1024,768);
    game->GameLoop();

    delete game;

    return 0;
}