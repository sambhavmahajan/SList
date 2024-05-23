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
	bool popAt(T ele, int index);
	bool pop_back();
	bool pop_front();
	T& at(int index) const;
	~SList();
};

#endif