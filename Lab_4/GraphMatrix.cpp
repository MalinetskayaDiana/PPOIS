#include "GraphMatrix.h"

template<typename T>
GraphMatrix<T>::GraphMatrix() : matrix(){}

template<typename T>
GraphMatrix<T>::GraphMatrix(const GraphMatrix& other) : matrix(other.matrix){}

template<typename T>
GraphMatrix<T>::~GraphMatrix(){}

template<typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::begin()
{
	return matrix.begin();
}

template <typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::end()
{
	return matrix.end();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cbegin() const
{
	return matrix.cbegin();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cend() const
{
	return matrix.cend();
}

template <typename T>
bool GraphMatrix<T>::isEmpty() const
{
	return matrix.empty();
}

template <typename T>
void GraphMatrix<T>::clearMatrix()
{
	matrix.clear();
}

template <typename T>
GraphMatrix<T>& GraphMatrix<T>::operator=(const GraphMatrix& other)
{
	if (this != &other) {
		matrix = other.matrix;
	}
	return *this;
}

template <typename T>
bool GraphMatrix<T>::operator==(const GraphMatrix& other) const
{
	return matrix == other.matrix;
}

template <typename T>
bool GraphMatrix<T>::operator!=(const GraphMatrix& other) const
{
	return !(*this == other);
}

template <typename T>
bool GraphMatrix<T>::operator>(const GraphMatrix& other) const
{
	if (!(this <= other))
		return true;
	else
		return false;
}

template <typename T>
bool GraphMatrix<T>::operator<(const GraphMatrix& other) const
{
	if (!(this >= other))
		return true;
	else
		return false;
}

template <typename T>
bool GraphMatrix<T>::operator>=(const GraphMatrix& other) const
{
	if (vertexCount() > other.vertexCount() || vertexCount() == other.vertexCount())
		return true;
	else if (edgeCount() > other.edgeCount() || edgeCount() == other.edgeCount())
		return true;
	else
		return false;
}

template <typename T>
bool GraphMatrix<T>::operator<=(const GraphMatrix& other) const
{
	if (vertexCount() < other.vertexCount() || vertexCount() == other.vertexCount())
		return true;
	else if (edgeCount() < other.edgeCount() || edgeCount() == other.edgeCount())
		return true;
	else
		return false;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const GraphMatrix<T>& gm)
{
	auto print = [&os](const T& n) { os << n << ' '; };
	for_each(gm.matrix.cbegin(), gm.matrix.cend(), print);
	return os;
}

template <typename T>
bool GraphMatrix<T>::hasVertex(size_t i) const
{
	return i < matrix.size();
}

template <typename T>
bool GraphMatrix<T>::hasEdge(size_t i, size_t j) const
{
	return hasVertex(i) && hasVertex(j) && matrix[i][j] != 0;
}

template <typename T>
size_t GraphMatrix<T>::vertexCount() const
{
	return matrix.size();
}

template <typename T>
size_t GraphMatrix<T>::edgeCount() const
{
	size_t count = 0;
	for (const auto& row : matrix) 
	{
		for (const auto& value : row) 
		{
			if (value != 0) 
				++count;
		}
	}
	return count / 2; 
}

template <typename T>
size_t GraphMatrix<T>::vertexDegree(size_t i) const
{
	if (!hasVertex(i)) {
		throw std::out_of_range("Vertex not found");
	}
	size_t degree = 0;
	for (const auto& value : matrix[i]) {
		if (value != 0) {
			++degree;
		}
	}
	return degree;
}

template <typename T>
size_t GraphMatrix<T>::edgeDegree(size_t i, size_t j) const
{
	if (!hasEdge(i, j)) {
		throw out_of_range("Edge not found");
	}
	return matrix[i][j];
}

template <typename T>
void GraphMatrix<T>::addVertex()
{
	size_t n = matrix.size();
	matrix.resize(n + 1);
	for (auto& row : matrix) 
	{
		row.push_back(0);
	}
}

template <typename T>
void GraphMatrix<T>::addEdge(size_t i, size_t j, T value)
{
	if (i >= matrix.size() || j >= matrix.size()) 
		throw out_of_range("Vertex does not exists!");
	if (i == j)
		throw invalid_argument("Same Vertex!");
	matrix[i][j] = value;
	matrix[j][i] = value;
}

template <typename T>
void GraphMatrix<T>::removeVertex(size_t i)
{
	if (!hasVertex(i)) {
		throw out_of_range("Vertex not found");
	}
	matrix.erase(matrix.begin() + i);
	for (auto& row : matrix) {
		row.erase(row.begin() + i);
	}
}

template <typename T>
void GraphMatrix<T>::removeEdge(size_t i, size_t j)
{
	if (!hasEdge(i, j)) {
		throw out_of_range("Edge not found");
	}
	matrix[i][j] = 0;
	matrix[j][i] = 0;
}

template <typename T>
void GraphMatrix<T>::removeVertex(iterator it)
{
	size_t i = std::distance(matrix.begin(), it);
	if (i < matrix.size()) {
		matrix.erase(matrix.begin() + i);
		for (auto& row : matrix) {
			row.erase(row.begin() + i);
		}
	}
}

template <typename T>
void GraphMatrix<T>::removeEdge(iterator it)
{
	if (it != matrix.end()) {
		size_t i = std::distance(matrix.begin(), it);
		size_t j = std::distance(matrix[i].begin(), it);
		matrix[i][j] = 0;
		matrix[j][i] = 0;
	}
}
template <typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::vertexBegin()
{
	return matrix.begin();
}

template <typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::vertexEnd()
{
	return matrix.end();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cvertexBegin() const
{
	return matrix.cbegin();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cvertexEnd() const
{
	return matrix.cend();
}

template <typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::edgeBegin()
{
	return matrix.begin();
}

template <typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::edgeEnd()
{
	return matrix.end();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cedgeBegin() const
{
	return matrix.cbegin();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cedgeEnd() const
{
	return matrix.cend();
}

template <typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::adjacentBegin(size_t i)
{
	return matrix[i].begin();
}

template <typename T>
typename GraphMatrix<T>::iterator GraphMatrix<T>::adjacentEnd(size_t i)
{
	return matrix[i].end();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cadjacentBegin(size_t i) const
{
	return matrix[i].cbegin();
}

template <typename T>
typename GraphMatrix<T>::const_iterator GraphMatrix<T>::cadjacentEnd(size_t i) const
{
	return matrix[i].cend();
}