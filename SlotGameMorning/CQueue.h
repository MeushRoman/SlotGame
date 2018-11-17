#pragma once
#include"List_.h"

template<class T>
class CQueue
{
	List_<T> queue;
public:
	void push(const T&obj) {
		queue.push_back(obj);
	}
	void pop(bool toEnd = false) {
		if (queue.size() > 0) {
			if (toEnd)
				queue.push_back(move(queue.front()));
			queue.pop_front();
		}
	}
	const T&front() const {
		return queue.front();
	}
	const T&back() const { return queue.back(); }
	T&front() {
		return queue.front();
	}
	T&back() { return queue.back(); }

	void print() { wcout << queue; }
};
