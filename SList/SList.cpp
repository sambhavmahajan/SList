#include "SList.h"

template<typename T>
SList<T>::SList()
{
	_size = 0;
	_maxIdx = -1;
	arr = nullptr;
	defaultBuffer = T();
}
template<typename T>
bool SList<T>::push_back(T ele)
{
	return insertAt(ele, _size);
}

template<typename T>
bool SList<T>::push_front(T ele)
{
	return insertAt(ele, 0);
}

template<typename T>
bool SList<T>::insertAt(T ele, int i)
{
	if (_size == 0) {// list if empty
		if (i == 0) {
			_size = 1;
			arr = new T[1];
			_maxIdx = 1;
			return true;
		}
		else return false;
	}
	else if (i > _size || i < 0) {
		return false;//invalid index
	}
	else {
		if (i + 1 == _size) {//list is full
			T* temp = new T[_size * 2];
			for (int k = 0; k <  i; k++) {
				temp[k] = arr[k];
			}
			temp[i] = ele;
			for (int k = i + 1; k < _size; k++) {
				temp[k] = arr[k - 1];
			}
			delete[] arr;
			arr = temp;
			_size *= 2;
			++_max_idx;
		}
		else {
			++_maxIdx;
			for (int k = max_idx + 1; k > i; k++) {//Shift ele to right
				arr[k] = arr[k - 1];
			}
			arr[i] = ele;
		}
		return true;
	}
}

template<typename T>
bool SList<T>::popAt(T ele, int index)
{
	if (index < 0 || index > _maxIdx) return false;
	for (int i = index; i < _maxIndex; i++) {
		arr[i] = arr[i + 1];
	}
	return true;
}

template<typename T>
bool SList<T>::pop_back()
{
	if (_size == 0) return false;
	_maxIdx--;
	return true;
}

template<typename T>
bool SList<T>::pop_front()
{
	if (_size == 0) return false;
	for (int i = 0; i < maxIdx; i++) {
		arr[i] = arr[i + 1];
	}
	return true;
}

template<typename T>
T& SList<T>::at(int index) const
{
	if (index < 0 || index >= _size) return defaultBuffer;
	else if (_size == 0) return defaultBuffer;
	return arr[index];
}

template<typename T>
SList<T>::~SList()
{
	delete[] arr;
}
