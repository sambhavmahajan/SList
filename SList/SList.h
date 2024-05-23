#ifndef SLIST_H
#define SLIST_H
template<typename T>
class SList {
private:
	int _size;
	int _maxIdx;
	T* arr;
	T defaultBuffer;
public:
	SList();
	bool push_back(T ele);
	bool push_front(T ele);
	bool insertAt(T ele, int i);
	int size() const;
	bool isSorted() const;
	bool popAt(T ele, int index);
	bool pop_back();
	bool pop_front();
	bool isPalindromic() const;
	void reverse();
	int find(T ele);
	int binarySearch(T ele);
	T& at(int index) const;
	T* begin() const;
	T* end() const;
	~SList();
};

#endif