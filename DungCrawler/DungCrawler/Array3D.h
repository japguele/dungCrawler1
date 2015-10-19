#pragma once
#include <iostream>

class Array3D
{
public:

	Array3D(size_t, size_t, size_t);
	Array3D(const Array3D&);
	Array3D(Array3D&&);
	Array3D();

	Array3D& operator=(const Array3D&);
	Array3D& operator=(Array3D&&);
	bool operator==(const Array3D&);

	size_t get_x_size() const;
	size_t get_y_size() const;
	size_t get_z_size() const;

	void put(int, size_t, size_t, size_t);
	int get(size_t, size_t, size_t) const;

	~Array3D();
private:
	size_t x_size;
	size_t y_size;
	size_t z_size;

	int* array;

	size_t Index(size_t, size_t, size_t) const;
};

