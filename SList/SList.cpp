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
bool SList<T>::push_back(const T &ele)
{
	return insertAt(ele, _size);
}

template<typename T>
bool SList<T>::push_front(const T &ele)
{
	return insertAt(ele, 0);
}

template<typename T>
bool SList<T>::insertAt(const T &ele, const int &i)
{
	if (arr == nullptr) {// list if empty
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
			++_maxIdx;
		}
		else {
			++_maxIdx;
			for (int k = _maxIdx + 1; k > i; k++) {//Shift ele to right
				arr[k] = arr[k - 1];
			}
			arr[i] = ele;
		}
		return true;
	}
}

template<typename T>
int SList<T>::size() const
{
	return _maxIdx + 1;
}

template<typename T>
bool SList<T>::isSorted() const
{
	if (_maxIdx == -1) return true;
	for (int i = 0; i < _maxIdx; i++) {
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
}

template<typename T>
bool SList<T>::popAt(const T &ele, const int &index)
{
	if (index < 0 || index > _maxIdx) return false;
	for (int i = index; i < _maxIdx; i++) {
		arr[i] = arr[i + 1];
	}
	_maxIdx--;
	return true;
}

template<typename T>
bool SList<T>::pop_back()
{
	if (_maxIdx == -1) return false;
	_maxIdx--;
	return true;
}

template<typename T>
bool SList<T>::pop_front()
{
	if (_maxIdx == -1) return false;
	for (int i = 0; i < _maxIdx; i++) {
		arr[i] = arr[i + 1];
	}
	return true;
}

template<typename T>
bool SList<T>::isPalindromic() const
{
	if (_maxIdx == -1) return true;//empty list is palindromic
	int l = 0;
	int r = _maxIdx;
	while (l < r) {
		if (arr[l++] != arr[r--]) return false;
	}
	return true;
}

template<typename T>
void SList<T>::reverse()
{
	if (_maxIdx == -1) return;
	T temp;
	const int n = _maxIdx / 2;
	for (int i = 0; i < n; i++) {
		temp = arr[i];
		arr[i] = arr[_maxIdx - i];
		arr[_maxIdx] = temp;
	}
}

template<typename T>
int SList<T>::find(const T &ele) const
{
	if (_maxIdx == -1) return -1;
	for (int i = 0; i <= _maxIdx; i++) {
		if (arr[i] == ele) return i;
	}
	return -1;
}

template<typename T>
int SList<T>::findAfter(const T &ele, int index) const
{
	++index;
	if (index < 0 || index > _maxIdx) return -1;
	while (index <= _maxIdx) {
		if (arr[index] == ele) return index;
		index++;
	}
	return -1;
}

template<typename T>
int SList<T>::count(const T &ele) const
{
	int res = 0;
	for (int i = 0; i <= _maxIdx; i++) {
		if (arr[i] == ele) ++res;
	}
	return res;
}

template<typename T>
int SList<T>::binarySearch(const T &ele)
{
	if (_maxIdx == -1) return -1;
	int l = 0;
	int r = _maxIdx;
	int m;
	while (l < r) {
		m = (l + r) / 2;
		if (arr[m] == ele) return m;
		else if (arr[m] > ele) r = m - 1;
		else l = m + 1;
	}
	return -1;
}

template<typename T>
T& SList<T>::at(const int &index) const
{
	if (index < 0 || index >= _size) return defaultBuffer;
	else if (_size == 0) return defaultBuffer;
	return arr[index];
}

template<typename T>
T* SList<T>::begin() const
{
	if (_maxIdx == -1) return nullptr;
	else return arr;
}

template<typename T>
T* SList<T>::end() const
{
	if (_maxIdx == -1) return nullptr;
	else return (arr + _maxIdx);
}

template<typename T>
SList<T>::~SList()
{
	delete[] arr;
}
