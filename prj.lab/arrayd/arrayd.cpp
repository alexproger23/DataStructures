#include <iostream>
#include <cstddef>


#include "arrayd.h"


ArrayD::ArrayD(const ArrayD& d) : capacity_(d.size_), size_(capacity_) {
	data_ = new double[size_];
	memcpy(data_, d.data_, size_ * sizeof(double));
}

ArrayD::ArrayD(std::ptrdiff_t n) : capacity_(n), size_(n) {
	if (n <= 0) throw std::invalid_argument("ArrayD::ArrayD - non positive size");
	data_ = new double[n] {0.0};
}

ArrayD& ArrayD::operator=(const ArrayD& d) {
	this->Resize(d.size_);
	std::memcpy(data_, d.data_, d.size_ * sizeof(double));

	return *this;
}


ArrayD::~ArrayD() {
	delete[] data_;
}

double& ArrayD::operator[](std::ptrdiff_t ind) {
	if (ind >= size_ || ind < 0) throw (std::invalid_argument("ArrayD::ArrayD - index out of range"));
	return data_[ind];
}

double ArrayD::operator[](std::ptrdiff_t ind) const {
	if (ind >= size_ || ind < 0) throw (std::exception("arrayd out of range"));
	return data_[ind];
}

std::ptrdiff_t ArrayD::Size() const noexcept {
	return size_;
}

void ArrayD::Resize(std::ptrdiff_t size) {
	if (0 >= size) throw std::invalid_argument("ArrayD::ArrayD - non positive size");
	
	if (capacity_ < size) {
		double* ndata = new double[size] {0.0};
		std::memcpy(ndata, data_, size_ * sizeof(double));
		std::swap(data_, ndata);
		delete[] ndata;
		capacity_ = size;
		size_ = size;
	}
	else {
		if (size > size_) {
			std::memset(data_ + size_, 0.0, (size - size_) * sizeof(double));
			size_ = size;
		}
		else size_ = size;
	}
}

void ArrayD::Insert(std::ptrdiff_t index, const double elem) {
	if (index > size_ || index < 0) throw std::exception("ArrayD::Insert - invalid argument");

	this->Resize(size_ + 1);

	for (ptrdiff_t i = size_ - 1; i > index; i--)
		data_[i] = data_[i - 1];

	data_[index] = elem;
}

void ArrayD::Remove(const std::ptrdiff_t ind) {
	if (ind >= size_) throw (std::exception("arrayd out of range"));

	for (ptrdiff_t i = ind; i < size_ - 1; i++)
		data_[i] = data_[i + 1];

	this->Resize(size_ - 1);
}