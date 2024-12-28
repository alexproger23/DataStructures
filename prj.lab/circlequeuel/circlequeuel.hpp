#pragma once
#ifndef CIRCLEQUEUEL
#define CIRCLEQUEUEL
class CircleQueueL {
private:
	struct Node {
		std::int32_t data_ = 0;
		Node* prev_ = nullptr;
		Node* next_ = nullptr;
	};
	Node* head_ = nullptr;
public:
	CircleQueueL() = default;
	CircleQueueL(const CircleQueueL& src);
	CircleQueueL& operator=(const CircleQueueL& src);

	void push(std::int32_t);
	void pop();
	std::int32_t top();
	std::int32_t back();
	
	bool isEmpty();
	void clear();
};
#endif