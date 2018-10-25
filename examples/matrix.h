// matrix.h -- class definition for the matrix ADT

#ifndef MATRIX_H_
#define MATRIX_H_

template <typename T>
class Matrix
{
private:
	T * Val;
public:
    int M;
	int N;
	Matrix(int m, int n);
	~Matrix();
	T read(int i, int j);
	bool write(int i, int j, T e);
	void dump();
	Matrix<T> transpose();
	Matrix<T>& operator =(const Matrix &Q);
	Matrix<T> operator +(const Matrix &Q);
	Matrix<T> operator -(const Matrix &Q);
	Matrix<T> operator *(const T &q);
	Matrix<T> operator *(const Matrix &Q);
	void operator +=(const Matrix &Q);
	void operator -=(const Matrix &Q);
	void operator *=(const T &q);
	T& operator ()(const int i, const int j);
};

#endif

template <typename T>
Matrix<T>::Matrix(int m, int n)
{
	M = m, N = n;
	Val = new T[m * n];
	for (int i = 0; i < M * N; i++) {
        Val[i] = 0;
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
	M = N = 0;
	if (Val != NULL) {
        delete [] Val;
	}
}

template <typename T>
T Matrix<T>::read(int i, int j)
{
	if (i >= M || j >= N) {
		return -31415;
	}
	return *(Val + i * N + j);
}

template <typename T>
bool Matrix<T>::write(int i, int j, T e)
{
	if (i >= M || j >= N) {
		return false;
	}
	*(Val + i * N + j) = e;
	return true;
}

template <typename T>
void Matrix<T>::dump()
{
    using std::cout;
    using std::endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (j) cout << ' ';
			cout << *(Val + i * N + j);
		}
		cout << endl;
	}
}

template <typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> P(N, M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            *(P.Val + j * M + i) = *(Val + i * N + j);
        }
    }
    return P;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T> &Q)
{
    for (int i = 0; i < M * N; i++) {
        Val[i] = Q.Val[i];
	}
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &Q)
{
	Matrix<T> P(M, N);
	for (int i = 0; i < M * N; i++) {
		P.Val[i] = Val[i] + Q.Val[i];
	}
	return P;
}

template <typename T>
Matrix<T> Matrix<T>::operator -(const Matrix<T> &Q)
{
	Matrix<T> P(M, N);
	for (int i = 0; i < M * N; i++) {
		P.Val[i] = Val[i] - Q.Val[i];
	}
	return P;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const T &q)
{
    Matrix<T> P(M, N);
    for (int i = 0; i < M * N; i++) {
        P.Val[i] = Val[i] * q;
    }
    return P;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T> &Q)
{
    Matrix<T> P(M, Q.N);
    if (N != Q.M) {
        return P;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < Q.N; j++) {
            T row = 0;
            for (int k = 0; k < N; k++) {
                row += *(this->Val + i * N + k) * *(Q.Val + k * Q.N + j);
            }
            *(P.Val + i * Q.N + j) = row;
        }
    }
    return P;
}

template <typename T>
void Matrix<T>::operator +=(const Matrix<T> &Q)
{
	for (int i = 0; i < M * N; i++) {
        Val[i] += Q.Val[i];
	}
}

template <typename T>
void Matrix<T>::operator -=(const Matrix<T> &Q)
{
	for (int i = 0; i < M * N; i++) {
        Val[i] -= Q.Val[i];
	}
}

template <typename T>
void Matrix<T>::operator *=(const T &q)
{
	for (int i = 0; i < M * N; i++) {
        Val[i] *= q;
	}
}

template <typename T>
T& Matrix<T>::operator ()(const int i, const int j)
{
	return *(Val + i * N + j);
}
