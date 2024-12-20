#pragma once
#ifndef QUEUEA
#define QUEUEA

#include <cstddef>
#include <cstdint>

class QueueA {
public:
	QueueA() = default;
	QueueA(const QueueA& src);
	~QueueA();
	QueueA& operator=(const QueueA& src);

	bool IsEmpty() const noexcept;
	void Clear() noexcept;

	void Pop() noexcept;
	void Push(const std::uint8_t val);
	const std::uint8_t& Top() const;

private:
	std::ptrdiff_t size_ = 0;
	std::uint8_t* data_ = nullptr;
	std::ptrdiff_t head_ = -1;
	std::ptrdiff_t tail_ = -1;
};

#endif