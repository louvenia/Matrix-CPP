#ifndef SRC_S21_MATRIX_OOP_H__
#define SRC_S21_MATRIX_OOP_H__

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();
  //------------------------------------------------------------
  int GetRows() const noexcept;
  void SetRows(int rows);
  int GetCols() const noexcept;
  void SetCols(int cols);
  //------------------------------------------------------------
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  bool operator==(const S21Matrix& other) const;
  double& operator()(int i, int j) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double& num);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double& num) const;
  //------------------------------------------------------------
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  S21Matrix Transpose() const;
  double Determinant() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;
  // ----------------------Helpers--------------------------------
  void Swap(S21Matrix& other) noexcept;
  void CreateMatrix();
  void ClearMatrix();
  void CopyMatrix(const S21Matrix& other) noexcept;
  void NotEqRowCol() const;
  void CheckRowsCols(const S21Matrix& other) const;
  void Minor(const S21Matrix& minor, int rows_m, int cols_m) const;

  friend S21Matrix operator*(const double& num, const S21Matrix& matrix);

 private:
  int rows_, cols_;
  double** matrix_;
};

#endif  // SRC_S21_MATRIX_OOP_H__
