#include <random>
#include <time.h>

template <typename T>
class Image
{
private:
	int size_x;
	int size_y;
	T** image;

public:
	Image(int x, int y, bool flag);
	T& operator()(int x, int y);
	Image& operator+(T a);
	Image& operator*(T a);
	Image& operator*(Image a);
	Image& operator+(Image a);
	Image& operator!();
	bool operator==(Image a);
	double image_koefficient();
};

template <typename T>
Image<T>::Image(int x, int y, bool flag)
{
	image = new T* [x];
	for (int i = 0; i < x; i++)
	{
		image[i] = new T[y];
	}
	size_x = x;
	size_y = y;
	if (flag == true)
	{
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = rand();
			}
		}
	}
	else {
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++) {
				image[i][j] = 0;
			}
		}
	}
}

template <typename T>
T& Image<T>::operator()(int x, int y)
{
	return image[x][y];
}

template <typename T>
Image<T>& Image<T>::operator+(T a) {
	Image<T> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; i < size_y; j++) {
			result.image[i][j] = image[x][j] + a;
		}
	}
	return result;
}

template <typename T>
Image<T>& Image<T>::operator*(T a) {
	Image<T> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; i < size_y; j++) {
			result.image[i][j] = image[x][j] * a;
		}
	}
	return result;
}

Image<bool>& Image<bool>::operator*(Image<bool> a){
	if (a.size_x != size_x || a.size_y != size_y) {
		//исключение 
	}
	Image<bool> result(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result.image[i][j] = (bool)(image[i][j] & a.image[i][j]);
		}
	}
	return result;
}

Image<bool>& Image<bool>::operator+(Image<bool> a) {
	if (a.size_x != size_x || a.size_y != size_y) {
		//исключение 
	}
	Image<bool>* result = new Image<bool>(size_x, size_y, false);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			result->image[i][j] = (bool)(image[i][j] || a.image[i][j]);
		}
	}
	return *result;
}

Image<bool>& Image<bool>::operator!() {
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			image[i][j] = !image[i][j];
		}
	}
	return *this;
}

template <typename T>
bool Image<T>::operator==(Image<T> a)
{
	if (a.size_x != size_x || a.size_y != size_y) {
		//искл
	}
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			if (a.image[i][j] != image[i][j]) {
				return false;
			}
		}
	}
	return true;
}

double Image<bool>::image_koefficient() {
	double sum = 0;
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			sum += image[i][j];
		}
	}
	return sum / (size_x * size_y * 1);
}

double Image<int>::image_koefficient() {
	double sum = 0;
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			sum += image[i][j];
		}
	}
	return sum / (size_x * size_y * INT_MAX);
}

double Image<short>::image_koefficient() {
	double sum = 0;
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			sum += image[i][j];
		}
	}
	return sum / (size_x * size_y * SHRT_MAX);
}

double Image<double>::image_koefficient() {
	double sum = 0;
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			sum += image[i][j];
		}
	}
	return sum / (size_x * size_y * DBL_MAX);
}
