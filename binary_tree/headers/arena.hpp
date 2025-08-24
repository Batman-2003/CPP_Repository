#ifndef _ARENA_HPP_
#define _ARENA_HPP_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

#define STRINGIFY(x) #x

// TODO: migrate to iostream from stdio

struct Arena {
	const size_t m_ARENA_SIZE;
	void* m_arena_p;
	size_t m_curr_ind;

	void* vp_allocate(const size_t _num_of_bytes);
	void printArena(void);
	void resetArena(void);
	// ~Arena(void);



	Arena(const size_t _arena_size): m_ARENA_SIZE(_arena_size) {
		m_arena_p = calloc(m_ARENA_SIZE, 1);
		*(reinterpret_cast<size_t*>(m_arena_p)) = reinterpret_cast<size_t>(m_arena_p);
		m_curr_ind = sizeof(this);
		if (!m_arena_p) {
			std::cout << "Error while initializing arena\n";
			throw std::runtime_error("Failed to initialize arena\n");
		}
		std::cout << "Arena of size: " << m_ARENA_SIZE << " was initialized successfully\n";
	}

	~Arena() {
		free(m_arena_p);
		std::cout << "Arena was freed successfully\n";
	}


};

void Arena::printArena(void) {
	std::cout << "\n\n";

	std::cout << "Printing Arena Struct ..\n";
	std::cout << std::setw(28) << "ARENA_SIZE" << ": " << m_ARENA_SIZE << "\n";
	std::cout << std::setw(28) << "arena_p" << ": " << m_arena_p << "\n";
	std::cout << std::setw(28) << "curr_ind" << ": " << m_curr_ind << "\n";
	std::cout << std::setw(28) << "...\n\n";
}

void* Arena::vp_allocate(const size_t _num_of_bytes) {
	void* ret_ptr = m_arena_p + m_curr_ind;
	m_curr_ind += _num_of_bytes;
	return ret_ptr;
}

void Arena::resetArena(void) {
	std::cout << "\n\nResetting the arena\n";
	m_curr_ind = sizeof(Arena*);
	memset(m_arena_p + m_curr_ind, 0, m_ARENA_SIZE - m_curr_ind);
	std::cout << "Arena was reset \n\n";

}

#endif // _ARENA_HPP_