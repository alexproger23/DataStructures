#ifndef ARRAYT_ARRAYT_HPP_20241202
#define ARRAYT_ARRAYT_HPP_20241202

#include <cstddef>
#include <memory>

template<class T>
class ArrayT {
private:
	std::ptrdiff_t capacity_{ 0 };
	std::ptrdiff_t size_{ 0 };
	std::unique_ptr<T[]> data_{nullptr};
public:
	ArrayT() = default;

	ArrayT(const ArrayT& d);

	ArrayT(std::ptrdiff_t n);
	ArrayT& operator=(const ArrayT& d);

	~ArrayT() = default;

	T& operator[](std::ptrdiff_t ind);
	T operator[](std::ptrdiff_t ind) const;

	std::ptrdiff_t Size() const noexcept { return size_; }

	void Resize(std::ptrdiff_t size);
	void Insert(std::ptrdiff_t index, const T elem);
	void Remove(const std::ptrdiff_t ind);
};

template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& src) : capacity_(src.size_), size_(capacity_) {
	data_.reset(new T[size_]{T()});
	std::copy(src.data_.get(), src.data_.get() + size_, data_.get());
}

template<class T>
ArrayT<T>::ArrayT(std::ptrdiff_t n) : capacity_(n), size_(n) {
	if (n <= 0) throw std::invalid_argument("ArrayD::ArrayD - non positive size");
	data_.reset(new T[n] {T()});
}

#endif