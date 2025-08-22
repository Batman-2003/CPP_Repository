#include "../headers/arena.hpp"

int main(void) {
	{
		Arena arena1 = Arena(4096);
		arena1.printArena();
		arena1.resetArena();
	}
}
