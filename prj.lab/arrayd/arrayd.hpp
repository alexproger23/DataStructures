#ifndef ARRAYD
#define ARRAYD

class ArrayD {
private:
	std::ptrdiff_t capacity_{ 0 };
	std::ptrdiff_t size_{ 0 };
	double* data_{ nullptr };
public:
	ArrayD() = default;

	ArrayD(const ArrayD& d);

	ArrayD(std::ptrdiff_t n);
	ArrayD& operator=(const ArrayD& d);

	~ArrayD();

	double operator[](std::ptrdiff_t ind) const;
	double& operator[](std::ptrdiff_t ind);
	

	std::ptrdiff_t Size() const noexcept;

	void Resize(std::ptrdiff_t size);
	void Insert(std::ptrdiff_t index, const double elem);
	void Remove(const std::ptrdiff_t ind);
};

#endif
