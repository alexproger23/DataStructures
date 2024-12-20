#include <queuea/queuea.hpp>

#include <algorithm>
#include <stdexcept>
#include <memory>

QueueA& QueueA::operator=(const QueueA& src) {
    if (this != &src) {
        std::ptrdiff_t count = src.IsEmpty() ? 0 : (src.tail_ + src.size_ - src.head_) % src.size_ + 1;
        if (0 == count) {
            head_ = -1;
        }
        else {
            if (size_ < count) {
                size_ = count;
                data_ = new uint8_t[count];
            }
            if (src.head_ < src.tail_) {
                std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
            }
            else {
                std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
                std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
            }
            head_ = 0;
            tail_ = count - 1;
        }
    }
    return *this;
}

QueueA::QueueA(const QueueA& src) {
    if (!src.IsEmpty()) {
        std::ptrdiff_t count = IsEmpty() ? 0 : (tail_ + size_ - head_) % size_ + 1;
        head_ = 0;
        tail_ = count - 1;
        size_ = count;
        data_ = new std::uint8_t[size_];
        if (src.head_ < src.tail_) {
            std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
        }
        else {
            std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
            std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
        }
    }
    else QueueA();
}

QueueA::~QueueA() {
    delete[] data_;
}

bool QueueA::IsEmpty() const noexcept {
    return head_ < 0;
}

void QueueA::Pop() noexcept {
    if (!IsEmpty()) {
        if (head_ != tail_) {
            head_ = (head_ + 1) % size_;
        }
        else {
            head_ = -1;
        }
    }
}

void QueueA::Push(const std::uint8_t val) {
    if (nullptr == data_) {
        size_ = 1;
        data_ = new std::uint8_t[size_];
    }
    if (IsEmpty()) {
        head_ = 0;
        tail_ = 0;
    }
    else {
        if (head_ == (tail_ + 1) % size_) {
            std::uint8_t* ndata = new std::uint8_t[size_ + 1];
            if (head_ < tail_) {
                std::memcpy(ndata, data_ + head_, (tail_ + 1) * sizeof(std::uint8_t));
            }
            else {
                std::memcpy(ndata, data_ + head_, (size_ - head_) * sizeof(std::uint8_t));
                std::memcpy(ndata + size_ - head_, data_, tail_ * sizeof(std::uint8_t));
            }
            delete[] data_;
            data_ = ndata;
            size_ += 1;
            head_ = 0;
            tail_ = size_ - 1;
        }
        else {
            tail_ = (tail_ + 1) % size_;
        }
    }
    data_[tail_] = val;
}

const std::uint8_t& QueueA::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueA - try get top form empty queue.");
    }
    return data_[head_];
}

void QueueA::Clear() noexcept {
    head_ = -1;
}