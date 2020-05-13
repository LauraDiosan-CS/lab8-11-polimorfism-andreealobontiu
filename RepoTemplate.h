#pragma once
#include <list>
using namespace std;

template <class T>class RepoTemplate {
protected:
	list<T> elem;
public:
	RepoTemplate<T>() {}
	virtual int addElem(T el);
	virtual int deleteElem(T el);
	int findElem(T el);
	int getSize();
	virtual void updateElem(T vechi, T nou);
	list<T> getAll();
	T getElemIndex(int index);
	void clearElem();
	~RepoTemplate();
};


template<class T>
int RepoTemplate<T>::addElem(T el)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == el->toString())
		{
			return -1;
		}
	}
	elem.push_back(el->clone());
	return 0;
}

template<class T>
int RepoTemplate<T>::deleteElem(T el)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == el->toString())
		{
			elem.erase(it);
			return 0;
		}
	}
	return -1;
}

template<class T>
int RepoTemplate<T>::findElem(T el)
{
	typename list<T>::iterator it;
	int pos = 0;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == el->toString())
		{
			return pos;
		}
		pos++;
	}
	return -1;
}

template<class T>
int RepoTemplate<T>::getSize()
{
	return elem.size();
}

template<class T>
void RepoTemplate<T>::updateElem(T vechi, T nou)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == vechi->toString())
		{
			*it = nou->clone();
		}
	}

}

template<class T>
list<T> RepoTemplate<T>::getAll()
{
	return elem;
}

template<class T>
T RepoTemplate<T>::getElemIndex(int index) {
	typename list<T>::iterator it;
	int pos = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (pos == index)
			return *it;
		pos++;

	}
}
template<class T> void RepoTemplate<T>::clearElem() {
	elem.clear();
}
template <class T> RepoTemplate<T>::~RepoTemplate()
{
}