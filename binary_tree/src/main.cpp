#include "../headers/arena.hpp"
#include "../headers/binary_tree.hpp"

int main(void) {
	{
		Arena arena1 = Arena(4096);
		Node node1 = Node<size_t>(2);
		arena1.printArena();
		arena1.resetArena();
	}
}
