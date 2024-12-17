#pragma once
#ifndef STACKL_STACKL_HPP_20241203
#define STACKL_STACKL_HPP_20241203

#include <cstddef>
#include <cstdint>

class StackL {
private:
	struct Node {
		std::uint8_t val = 0;
		Node* next = nullptr;
		
		Node(std::uint8_t vl, Node* nxt = nullptr) : val(vl), next(nxt) {}
		~Node() = default;
	};

	Node* head_ = nullptr;
public:
	StackL() = default;
	StackL(const StackL& src);
	StackL& operator=(const StackL& src);
	~StackL();

	void Pop();
	void Push(const std::uint8_t val);
	void Clear();
	bool IsEmpty() const noexcept;

	const std::uint8_t& Top() const;
};

#endif