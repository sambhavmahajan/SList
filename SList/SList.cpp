#include "SList.h"


template<typename T>
SList<T>::SList()
{
	_size = 0;
	_maxIdx = -1;
	arr = nullptr;
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
			for (int k = 0; k < _size; k++) {
				temp[k] = arr[k];
			}
			delete[] arr;
			arr = temp;
			_size *= 2;
		}
		arr[++_maxIdx] = ele;
		return true;
	}
}
