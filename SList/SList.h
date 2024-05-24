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
	bool push_back(const T& ele);
	bool push_front(const T &ele);
	bool insertAt(const T &ele, const int &i);
	int size() const;
	bool isSorted() const;
	bool popAt(const T &ele,const int &index);
	bool pop_back();
	bool pop_front();
	bool isPalindromic() const;
	void reverse();
	int find(const T &ele) const;
	int findAfter(const T &ele, int index) const;
	int count(const T &ele) const;
	int binarySearch(const T &ele);
	T& at(const int &index) const;
	T* begin() const;
	T* end() const;
	~SList();
};

#endif