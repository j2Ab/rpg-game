#include<iostream>
#include"game.h"
#include<time.h>


int main(int argc, char *argv[]) {

	srand(static_cast<unsigned>(time(0)));

	game game1;

	game1.run();


	std::cin.get();
}