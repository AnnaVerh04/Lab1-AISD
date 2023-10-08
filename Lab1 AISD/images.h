#pragma once
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
	Image& operator(Image a);

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




