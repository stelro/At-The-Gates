#include <iostream>
#include "src/MainClass.h"

using namespace std;

int main() {

    tok::MainClass *game = new tok::MainClass("Template of Katharsis", 0,0,1024,768);
    game->GameLoop();

    delete game;

    return 0;
}