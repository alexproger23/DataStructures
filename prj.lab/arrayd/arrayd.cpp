#include <iostream>
#include <cstddef>


#include "arrayd.h"

int main() {
	ArrayD d(3);
	for (int i = 0; i < 3; i++) d[i] = i;
	std::cout << d[0] << std::endl;
	d.Resize(4);
	d[3] = 213;
	for (int i = 0; i < d.Size(); i++) std::cout << d[i];
}


ArrayD::ArrayD(std::ptrdiff_t n) : size_(n), capacity_(n) {
	data_ = new double[n];
}

ArrayD::~ArrayD() {
	delete [] data_;
}

double& ArrayD::operator[](std::ptrdiff_t ind) { //записывает даже если инд больше сайза?
	if (ind >= capacity_) throw (std::exception("arrayd out of range"));
	return data_[ind];
}

double ArrayD::operator[](std::ptrdiff_t ind) const {
	if (ind >= capacity_) throw (std::exception("arrayd out of range"));
	return data_[ind];
}

std::ptrdiff_t ArrayD::Size() const {
	return size_;
}

void ArrayD::Resize(std::ptrdiff_t size) { //изменят size_ или капасити?
	if (size < size_) throw (std::exception("arrayd count elements more than new size"));
	double* temp = new double[size];
	for (ptrdiff_t i = 0; i < size_; i++)
		temp[i] = data_[i];
	data_ = temp;
	capacity_ = size;
}

void ArrayD::Insert(std::ptrdiff_t index, const double& elem) {
	if (index > size_) throw (std::exception("arrayd out of range"));

	if (size_ == capacity_)
		(*this).Resize(capacity_ * 2);

	double temp = data_[index];
	double temp2 = 0.0;
	for (ptrdiff_t i = size_; i > index; i--)
		data_[i] = data_[i - 1];

	size_++;
	data_[index] = elem;
}

void ArrayD::Remove(const std::ptrdiff_t ind) {
	if (ind >= size_) throw (std::exception("arrayd out of range"));

	for (ptrdiff_t i = ind; i < size_ - 1; i++)
		data_[i] = data_[i + 1];

	size_--;
}