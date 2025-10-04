#pragma once
#include <iostream>

// size: 0xC (12 bytes)
struct Input_impl {
	float value_;
	bool debounce_;

	// padding for the bool to be 4 bytes
	char field2_0x5;
	char field3_0x6;
	char field4_0x7;

	uintptr_t m_pSelf;
};

// size: 0x8 (8 bytes)
struct Input__10_25798 {
	struct Input_impl* input_;
	bool was_pressed_;

	// padding for the bool to be 4 bytes
	char field2_0x5;
	char field3_0x6;
	char field4_0x7;
};