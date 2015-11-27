#include "Array3D.h"


Array3D::Array3D(size_t xLength, size_t yLength, size_t zLength) : x_size{ xLength }, y_size{ yLength }, z_size{ zLength }
{
	int z =(xLength * yLength *zLength);
	//array = new Chamber*[z];

	//array = new (Chamber*)[z];

	for (int x = 0; x < z; x++){
		array[x] = nullptr;
	}


	//std::cout << " - " << xLength*yLength*zLength << " - ";
}
Array3D::Array3D(){

}
Array3D::Array3D(const Array3D& other) : x_size{ other.x_size }, y_size{ other.y_size }, z_size{ other.z_size }{

	int arraySize = x_size * y_size * z_size;

	// eigen buffer maken


	// alle bytes van de ander kopiëren
	std::memcpy(array, other.array, arraySize*sizeof(int));
}

Array3D* Array3D::getArray(){
	return this;
}

Array3D& Array3D::operator=(const Array3D& other) {
	if (this != &other) {
		// cleanup
		//	delete[] array;

		x_size = other.x_size;
		y_size = other.y_size;
		z_size = other.z_size;

		int arraySize = x_size * y_size * z_size;
		// eigen buffer maken


		// alle bytes van de ander kopiëren
		std::memcpy(array, other.array, arraySize);
	}

	return *this;
}

Array3D::Array3D(Array3D&& other)
{
	// steal resources
	array[0] = other.array[0];
	int z = other.x_size * other.y_size * other.z_size;

	for (int x = 0; x < z; x++){
		array[x] = other.array[x];
		other.array[x] = nullptr;
	}
	x_size = other.x_size;
	y_size = other.y_size;
	z_size = other.z_size;

}

Array3D& Array3D::operator=(Array3D&& other){
	if (this != &other){
		//	delete[] array;

		operator=(other);
	}

	return *this;
}





Chamber* Array3D::get(size_t x, size_t y, size_t z) const{
	size_t index = Index(x, y, z);
	return array[index];
}

void Array3D::put(Chamber* input, size_t x, size_t y, size_t z){
	size_t index = Index(x, y, z);
	array[index] = input;
}

size_t Array3D::Index(size_t x, size_t y, size_t z) const{
	//std::cout << " - " << x_size * y_size * z + x_size * y + x << " - ";
	{ return x_size * y_size * z + x_size * y + x; }
}

size_t Array3D::get_x_size() const{
	return x_size;
}

size_t Array3D::get_y_size() const{
	return y_size;
}

size_t Array3D::get_z_size() const{
	return z_size;
}


Array3D::~Array3D()
{
	delete[] array;
}



