#include <circlequeuel.hpp>

CircleQueueL::CircleQueueL(const CircleQueueL& src);

void CircleQueueL::push() {
	if (isEmpty()) {

	}
}

bool isEmpty() {
	return head_ == nullptr;
}