#include <memory>
#include <cstddef>
#include <stdexcept>

#include <stackl/stackl.hpp>


StackL::StackL(const StackL& src) {
	if (!src.IsEmpty()) {
		head_ = new Node(src.head_->val);
		Node* ptr_src = src.head_->next;
		Node* ptr_head = head_;
		while (ptr_src != nullptr) {
			ptr_head->next = new Node(ptr_src->val);
			ptr_src = ptr_src->next;
			ptr_head = ptr_head->next;
		}
	}
}

StackL& StackL::operator=(const StackL& src) {
	if (this != &src) {
		if (src.IsEmpty()) Clear();
		else {
			Node* ptr_src = src.head_;
			Node* ptr_head = head_;

			if (IsEmpty()) {
				head_ = new Node(src.head_->val);
				ptr_src = ptr_src->next;
				ptr_head = head_;
			}
			else {
				ptr_head->val = ptr_src->val;
				ptr_src = ptr_src->next;
				while (ptr_head->next && ptr_src) {
					ptr_head = ptr_head->next;
					ptr_head->val = ptr_src->val;
					ptr_src = ptr_src->next;
				}
			}
			if (ptr_src == nullptr) {
				Node* node = ptr_head->next;
				ptr_head->next = nullptr;
				while (node) {
					auto temp = node->next;
					delete node;
					node = temp;
				}
			}
			else {				
				while (ptr_src != nullptr) {
					ptr_head->next = new Node(ptr_src->val);
					ptr_src = ptr_src->next;
					ptr_head = ptr_head->next;
				}
			}
		}
	}
	return *this;
}

StackL::~StackL() {
	auto node = head_;
	while (node) {
		auto temp = node->next;
		delete node;
		node = temp;
	}
}

void StackL::Pop() {
	if (!IsEmpty()) {
		Node* temp = head_;
		head_ = head_->next;
		delete temp;
	}
}

void StackL::Push(const std::uint8_t val) {
	Node* newnode = new Node(val);
	newnode->next = head_;
	head_ = newnode;
}

const std::uint8_t& StackL::Top() const {
	if (head_ == nullptr) throw std::logic_error("stack is empty");
	return head_->val;
}

bool StackL::IsEmpty() const noexcept {
	return head_ == nullptr;
}

void StackL::Clear() {
	while (head_) Pop();
}