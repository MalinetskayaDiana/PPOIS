#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class GraphMatrix
{
public:
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* pointer;
	typedef const T* const_pointer;

	typedef typename vector<value_type>::iterator iterator;
	typedef typename vector<value_type>::const_iterator const_iterator;

	GraphMatrix();
	GraphMatrix(const GraphMatrix& other);

	~GraphMatrix();
	
	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;

	bool isEmpty() const;
	void clearMatrix();

	GraphMatrix& operator=(const GraphMatrix& other);
	bool operator==(const GraphMatrix& other) const;
	bool operator!=(const GraphMatrix& other) const;
	bool operator>(const GraphMatrix& other) const;
	bool operator<(const GraphMatrix& other) const;
	bool operator>=(const GraphMatrix& other) const;
	bool operator<=(const GraphMatrix& other) const;

	friend ostream& operator<<(ostream& os, const GraphMatrix& gm);

	bool hasVertex(size_t i) const;
	bool hasEdge(size_t i, size_t j) const;

	size_t vertexCount() const;
	size_t edgeCount() const;

	size_t vertexDegree(size_t i) const;
	size_t edgeDegree(size_t i, size_t j) const;

	void addVertex();
	void addEdge(size_t i, size_t j, T value);

	void removeVertex(size_t i);
	void removeEdge(size_t i, size_t j);
	void removeVertex(iterator it);
	void removeEdge(iterator it);

	iterator vertexBegin();
	iterator vertexEnd();
	const_iterator cvertexBegin() const;
	const_iterator cvertexEnd() const;

	iterator edgeBegin();
	iterator edgeEnd();
	const_iterator cedgeBegin() const;
	const_iterator cedgeEnd() const;

	iterator adjacentBegin(size_t i);
	iterator adjacentEnd(size_t i);
	const_iterator cadjacentBegin(size_t i) const;
	const_iterator cadjacentEnd(size_t i) const;
	
private:
	vector<vector<T>> matrix;
};