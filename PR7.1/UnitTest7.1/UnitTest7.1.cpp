#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1/PR7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
	TEST_CLASS(UnitTest71)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 8;
			int colCount = 5;
			int Low = -17;
			int High = 14;

			int** T = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				T[i] = new int[colCount];

			Create(T, rowCount, colCount, Low, High);

			// Перевірка, чи всі елементи в межах [Low, High]
			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					Assert::IsTrue(T[i][j] >= Low && T[i][j] <= High, L"Element out of range!");

			for (int i = 0; i < rowCount; i++)
				delete[] T[i];
			delete[] T;
		}

		// Тестування функції Sort
		TEST_METHOD(TestSort)
		{
			int rowCount = 3;
			int colCount = 5;

			// Вихідна матриця для тестування сортування
			int testMatrix[3][5] = {
				{ 3, 2, 1, 0, 0 },
				{ 2, 2, 1, 0, 0 },
				{ 1, 2, 1, 0, 0 }
			};

			int** T = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				T[i] = new int[colCount];

			// Копіюємо дані у динамічну матрицю
			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					T[i][j] = testMatrix[i][j];

			// Викликаємо функцію сортування
			Sort(T, rowCount, colCount);

			// Перевіряємо, чи відсортовано за першим, другим і третім стовпцями
			Assert::IsTrue(T[0][0] <= T[1][0] && T[1][0] <= T[2][0], L"First column not sorted");
			Assert::IsTrue(T[0][1] <= T[1][1] && T[1][1] <= T[2][1], L"Second column not sorted");
			Assert::IsTrue(T[0][2] <= T[1][2] && T[1][2] <= T[2][2], L"Third column not sorted");

			for (int i = 0; i < rowCount; i++)
				delete[] T[i];
			delete[] T;
		}

		// Тестування функції Calc
		TEST_METHOD(TestCalc)
		{
			int rowCount = 3;
			int colCount = 5;

			// Вихідна матриця для тестування Calc
			int testMatrix[3][5] = {
				{ -5, -4, 12, -3, 7 },
				{ -8, 3, 9, -2, 10 },
				{ -7, 2, -4, 11, -6 }
			};

			int** T = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				T[i] = new int[colCount];

			// Копіюємо дані у динамічну матрицю
			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					T[i][j] = testMatrix[i][j];

			int S = 0;
			int k = 0;

			// Викликаємо функцію Calc
			Calc(T, rowCount, colCount, S, k);

			// Перевіряємо суму та кількість
			Assert::AreEqual(S, -23, L"Incorrect sum");
			Assert::AreEqual(k, 5, L"Incorrect count of elements");

			for (int i = 0; i < rowCount; i++)
				delete[] T[i];
			delete[] T;
		}
	};
}
