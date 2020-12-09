#include "pch.h"
#include "CppUnitTest.h"
#include "..\poker\poker.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pokerunittest
{
	TEST_CLASS(pokerunittest)
	{
	public:
		
		TEST_METHOD(Test_rename_texas)
		{
			// Arrange
			string str = "1234567890___23456789TJ QKAc";
			int* mas = new int[1 * 4 + 12];
			int m[16] = { 1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,21};
			int i = 0;

			// Act
			mas = rename_texas(str);

			// Assert
			while (i < 16) {
				Assert::IsTrue(m[i] == mas[i]);
				i++;
			}
		}

		TEST_METHOD(Test_rename_omaha)
		{
			// Arrange
			string str = "1234567890___23456789TJ QKAcJdhs";
			int* mas = new int[1 * 8 + 12];
			int m[20] = { 2,1,2,3,4,5,6,7,8,9,10,11,12,13,14,21,11,22,23,24 };
			int i = 0;

			// Act
			mas = rename_omaha(str);

			// Assert
			while (i < 20) {
				Assert::IsTrue(m[i] == mas[i]);
				cout << m[i] << ' ' << mas[i];
				i++;
			}
		}

		TEST_METHOD(Test_rename_five)
		{
			// Arrange
			string str = "123456789012___23456789TJ QKAcJdhs4s";
			int* mas = new int[2 * 10 + 2];
			int m[22] = { 3,2,2,3,4,5,6,7,8,9,10,11,12,13,14,21,11,22,23,24,4,24 };
			int i = 0;

			// Act
			mas = rename_five(str);

			// Assert
			while (i < 22) {
				Assert::IsTrue(m[i] == mas[i]);
				cout << m[i] << ' ' << mas[i];
				i++;
			}
		}

		TEST_METHOD(Test_texas_data_to_class)
		{
			// Arrange
			gamer* gem = new gamer[1];
			int m[16] = { 1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,21 };
			int i = 0;
			gamer g;

			g.game = m[0];
			g.icard[0] = m[2];
			g.icard[1] = m[3];
			g.icard[2] = m[4];
			g.icard[3] = m[5];
			g.icard[4] = m[6];
			g.icard[5] = m[7];
			g.icard[6] = m[8];
			g.icard[7] = m[9];
			g.icard[8] = m[10];
			g.icard[9] = m[11];

			g.icard[10] = g.card[0] = m[12];
			g.icard[11] = g.card[1] = m[13];
			g.icard[12] = g.card[2] = m[14];
			g.icard[13] = g.card[3] = m[15];

			// Act
			gem = texas_data_to_class(m, gem);

			// Assert
			Assert::IsTrue(g.game == gem[0].game);
			while (i < 14) {
				Assert::IsTrue(g.icard[i] == gem[0].icard[i]);
				i++;
			}
			i = 0;
			while (i < 4) {
				Assert::IsTrue(g.icard[i + 10] == g.card[i] && g.card[i] == gem[0].card[i] && g.card[i] == gem[0].icard[i+10]);
				i++;
			}

		}

		TEST_METHOD(Test_omaha_data_to_class)
		{
			// Arrange
			gamer* gem = new gamer[60];
			int m[20] = { 2,1, 2,3,4,5, 6,7,8,9,10,11, 12,13,14,15, 16,17,18,19 };
			int i = 0;
			gamer g;

			g.game = m[0];
			g.icard[0] = m[12];
			g.icard[1] = m[13];
			g.icard[2] = m[14];
			g.icard[3] = m[15];

			g.icard[4] = m[6];
			g.icard[5] = m[7];
			g.icard[6] = m[8];
			g.icard[7] = m[9];
			g.icard[8] = m[10];
			g.icard[9] = m[11];

			 g.card[0] = m[12];
			 g.card[1] = m[13];
			 g.card[2] = m[14];
			 g.card[3] = m[15];
			 g.card[4] = m[16];
			 g.card[5] = m[17];
			 g.card[6] = m[18];
			 g.card[7] = m[19];

			// Act
			gem = omaha_data_to_class(m, gem);
		
			// Assert
			Assert::IsTrue(g.game == gem[0].game);


			while (i < 10) {
				Assert::IsTrue(g.icard[i] == gem[0].icard[i]);
				i++;
			}
			i = 0;
			while (i < 8) {
				Assert::IsTrue(g.card[i] == gem[0].card[i]);
				i++;
			}
			
		}

		TEST_METHOD(Test_five_data_to_class)
		{
			// Arrange
			gamer* gem = new gamer[1];
			int m[12] = { 3,1,2,3,4,5,6,7,8,9,10,11 };
			int i = 0;
			gamer g;

			g.game = m[0];
			g.icard[0] = g.card[0] = m[2];
			g.icard[1] = g.card[1] = m[3];
			g.icard[2] = g.card[2] = m[4];
			g.icard[3] = g.card[3] = m[5];
			g.icard[4] = g.card[4] = m[6];
			g.icard[5] = g.card[5] = m[7];
			g.icard[6] = g.card[6] = m[8];
			g.icard[7] = g.card[7] = m[9];
			g.icard[8] = g.card[8] = m[10];
			g.icard[9] = g.card[9] = m[11];

			g.icard[10] = -2;
			g.icard[11] = 25;
			g.icard[12] = -3;
			g.icard[13] = 25;

			// Act
			gem = five_data_to_class(m, gem);

			// Assert
			Assert::IsTrue(g.game == gem[0].game);
			while (i < 14) {
				Assert::IsTrue(g.icard[i] == gem[0].icard[i]);
				i++;
			}
			i = 0;
			while (i < 4) {
				Assert::IsTrue(g.card[i] == gem[0].card[i] );
				i++;
			}

		}

		TEST_METHOD(Test_flush_sort)
		{
			// Arrange
			gamer g;

			g.icard[0] = 2;
			g.icard[1] = 22;
			g.icard[2] = 4;
			g.icard[3] = 24;
			g.icard[4] = 9;
			g.icard[5] = 23;
			g.icard[6] = 13;
			g.icard[7] = 22;
			g.icard[8] = 12;
			g.icard[9] = 21;
			g.icard[10] = 7;
			g.icard[11] = 24;
			g.icard[12] = 11;
			g.icard[13] = 21;

			// Act
			g = flush_sort(g);

			// Assert
			Assert::IsTrue(g.icard[0] == 12);
			Assert::IsTrue(g.icard[1] == 21);
			Assert::IsTrue(g.icard[2] == 11);
			Assert::IsTrue(g.icard[3] == 21);
			Assert::IsTrue(g.icard[4] == 13);
			Assert::IsTrue(g.icard[5] == 22);
			Assert::IsTrue(g.icard[6] == 2);
			Assert::IsTrue(g.icard[7] == 22);
			Assert::IsTrue(g.icard[8] == 9);
			Assert::IsTrue(g.icard[9] == 23);
			Assert::IsTrue(g.icard[10] == 7);
			Assert::IsTrue(g.icard[11] == 24);
			Assert::IsTrue(g.icard[12] == 4);
			Assert::IsTrue(g.icard[13] == 24);
		}

		TEST_METHOD(Test_steet_sort)
		{
			// Arrange
			gamer g;
			int m[14];
			int i = 0;

			g.icard[0] = 2;
			g.icard[1] = 22;
			g.icard[2] = 4;
			g.icard[3] = 24;
			g.icard[4] = 9;
			g.icard[5] = 23;
			g.icard[6] = 13;
			g.icard[7] = 22;
			g.icard[8] = 12;
			g.icard[9] = 21;
			g.icard[10] = 7;
			g.icard[11] = 24;
			g.icard[12] = 11;
			g.icard[13] = 21;

			// Act
			while (i < 14)
			{
				m[i] = streetsort(g)[i];
				i++;
			}


			// Assert
			Assert::IsTrue(m[0] == 13);
			Assert::IsTrue(m[1] == 22);
			Assert::IsTrue(m[2] == 12);
			Assert::IsTrue(m[3] == 21);
			Assert::IsTrue(m[4] == 11);
			Assert::IsTrue(m[5] == 21);
			Assert::IsTrue(m[6] == 9);
			Assert::IsTrue(m[7] == 23);
			Assert::IsTrue(m[8] == 7);
			Assert::IsTrue(m[9] == 24);
			Assert::IsTrue(m[10] == 4);
			Assert::IsTrue(m[11] == 24);
			Assert::IsTrue(m[12] == 2);
			Assert::IsTrue(m[13] == 22);
		}

		TEST_METHOD(Test_street_flush)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 5;
			g.icard[3] = 22;
			g.icard[4] = 4;
			g.icard[5] = 22;
			g.icard[6] = 3;
			g.icard[7] = 22;
			g.icard[8] = 2;
			g.icard[9] = 22;
			g.icard[10] = 3;
			g.icard[11] = 23;
			g.icard[12] = 11;
			g.icard[13] = 23;

			// Act
			g = street_flush(g);

			// Assert
			Assert::IsTrue(g.power == 9);

			Assert::IsTrue(g.pcard[0] == 5);
			Assert::IsTrue(g.pcard[1] == 22);
			Assert::IsTrue(g.pcard[2] == -5);
			Assert::IsTrue(g.pcard[3] == -5);
			Assert::IsTrue(g.pcard[4] == -5);
			Assert::IsTrue(g.pcard[5] == -5);
			Assert::IsTrue(g.pcard[6] == -5);
			Assert::IsTrue(g.pcard[7] == -5);
			Assert::IsTrue(g.pcard[8] == -5);
			Assert::IsTrue(g.pcard[9] == -5);
		}

		TEST_METHOD(Test_square)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 13;
			g.icard[3] = 22;
			g.icard[4] = 10;
			g.icard[5] = 23;
			g.icard[6] = 10;
			g.icard[7] = 21;
			g.icard[8] = 10;
			g.icard[9] = 24;
			g.icard[10] = 10;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = square(g);

			// Assert
			Assert::IsTrue(g.power == 8);

			Assert::IsTrue(g.pcard[0] == 10);
			Assert::IsTrue(g.pcard[2] == 14);
			Assert::IsTrue(g.pcard[3] == 22);
			Assert::IsTrue(g.pcard[4] == -5);
			Assert::IsTrue(g.pcard[5] == -5);
			Assert::IsTrue(g.pcard[6] == -5);
			Assert::IsTrue(g.pcard[7] == -5);
			Assert::IsTrue(g.pcard[8] == -5);
			Assert::IsTrue(g.pcard[9] == -5);
		}

		TEST_METHOD(Test_full_house)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 10;
			g.icard[3] = 22;
			g.icard[4] = 10;
			g.icard[5] = 23;
			g.icard[6] = 10;
			g.icard[7] = 21;
			g.icard[8] = 8;
			g.icard[9] = 24;
			g.icard[10] = 8;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = full_house(g);

			// Assert
			Assert::IsTrue(g.power == 7);

			Assert::IsTrue(g.pcard[0] == 10);
			Assert::IsTrue(g.pcard[2] == 8);
			Assert::IsTrue(g.pcard[4] == -5);
			Assert::IsTrue(g.pcard[5] == -5);
			Assert::IsTrue(g.pcard[6] == -5);
			Assert::IsTrue(g.pcard[7] == -5);
			Assert::IsTrue(g.pcard[8] == -5);
			Assert::IsTrue(g.pcard[9] == -5);
		}

		TEST_METHOD(Test_flush)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 21;
			g.icard[2] = 10;
			g.icard[3] = 22;
			g.icard[4] = 10;
			g.icard[5] = 22;
			g.icard[6] = 9;
			g.icard[7] = 22;
			g.icard[8] = 8;
			g.icard[9] = 22;
			g.icard[10] = 8;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = flush(g);

			// Assert
			Assert::IsTrue(g.power == 6);

			Assert::IsTrue(g.pcard[0] == 10);
			Assert::IsTrue(g.pcard[1] == 22);
			Assert::IsTrue(g.pcard[2] == 10);
			Assert::IsTrue(g.pcard[3] == 22);
			Assert::IsTrue(g.pcard[4] == 9);
			Assert::IsTrue(g.pcard[5] == 22);
			Assert::IsTrue(g.pcard[6] == 8);
			Assert::IsTrue(g.pcard[7] == 22);
			Assert::IsTrue(g.pcard[8] == 8);
			Assert::IsTrue(g.pcard[9] == 22);
		}

		TEST_METHOD(Test_street)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 10;
			g.icard[3] = 22;
			g.icard[4] = 9;
			g.icard[5] = 23;
			g.icard[6] = 8;
			g.icard[7] = 21;
			g.icard[8] = 7;
			g.icard[9] = 24;
			g.icard[10] = 6;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = street(g);

			// Assert
			Assert::IsTrue(g.power == 5);

			Assert::IsTrue(g.pcard[0] == 10);
			Assert::IsTrue(g.pcard[1] == 22);
			Assert::IsTrue(g.pcard[2] == -5);
			Assert::IsTrue(g.pcard[4] == -5);
			Assert::IsTrue(g.pcard[5] == -5);
			Assert::IsTrue(g.pcard[6] == -5);
			Assert::IsTrue(g.pcard[7] == -5);
			Assert::IsTrue(g.pcard[8] == -5);
			Assert::IsTrue(g.pcard[9] == -5);
		}

		TEST_METHOD(Test_set)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 10;
			g.icard[3] = 22;
			g.icard[4] = 10;
			g.icard[5] = 23;
			g.icard[6] = 10;
			g.icard[7] = 21;
			g.icard[8] = 7;
			g.icard[9] = 24;
			g.icard[10] = 6;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = set(g);

			// Assert
			Assert::IsTrue(g.power == 4);

			Assert::IsTrue(g.pcard[0] == 10);
			Assert::IsTrue(g.pcard[1] == 23);
			Assert::IsTrue(g.pcard[2] == 14);
			Assert::IsTrue(g.pcard[3] == 22);
			Assert::IsTrue(g.pcard[4] == 7);
			Assert::IsTrue(g.pcard[5] == 24);
			Assert::IsTrue(g.pcard[6] == -5);
			Assert::IsTrue(g.pcard[7] == -5);
			Assert::IsTrue(g.pcard[8] == -5);
			Assert::IsTrue(g.pcard[9] == -5);
		}

		TEST_METHOD(Test_two_pair)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 10;
			g.icard[3] = 22;
			g.icard[4] = 10;
			g.icard[5] = 23;
			g.icard[6] = 9;
			g.icard[7] = 21;
			g.icard[8] = 7;
			g.icard[9] = 24;
			g.icard[10] = 7;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = two_pair(g);

			// Assert
			Assert::IsTrue(g.power == 3);

			Assert::IsTrue(g.pcard[0] == 10);
			Assert::IsTrue(g.pcard[2] == 7);
			Assert::IsTrue(g.pcard[4] == 14);
			Assert::IsTrue(g.pcard[5] == 22);
			Assert::IsTrue(g.pcard[6] == -5);
			Assert::IsTrue(g.pcard[7] == -5);
			Assert::IsTrue(g.pcard[8] == -5);
			Assert::IsTrue(g.pcard[9] == -5);
		}

		TEST_METHOD(Test_one_pair)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 11;
			g.icard[3] = 22;
			g.icard[4] = 10;
			g.icard[5] = 23;
			g.icard[6] = 10;
			g.icard[7] = 21;
			g.icard[8] = 7;
			g.icard[9] = 24;
			g.icard[10] = 6;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = one_pair(g);

			// Assert
			Assert::IsTrue(g.power == 2);

			Assert::IsTrue(g.pcard[0] == 10);
			Assert::IsTrue(g.pcard[2] == 14);
			Assert::IsTrue(g.pcard[3] == 22);
			Assert::IsTrue(g.pcard[4] == 11);
			Assert::IsTrue(g.pcard[5] == 22);
			Assert::IsTrue(g.pcard[6] == 7);
			Assert::IsTrue(g.pcard[7] == 24);
			Assert::IsTrue(g.pcard[8] == -5);
			Assert::IsTrue(g.pcard[9] == -5);
		}

		TEST_METHOD(Test_high_card)
		{
			// Arrange
			gamer g;

			g.icard[0] = 14;
			g.icard[1] = 22;
			g.icard[2] = 10;
			g.icard[3] = 22;
			g.icard[4] = 9;
			g.icard[5] = 23;
			g.icard[6] = 8;
			g.icard[7] = 21;
			g.icard[8] = 6;
			g.icard[9] = 24;
			g.icard[10] = 5;
			g.icard[11] = 22;
			g.icard[12] = 3;
			g.icard[13] = 23;

			// Act
			g = high_card(g);

			// Assert
			Assert::IsTrue(g.power == 1);

			Assert::IsTrue(g.pcard[0] == 14);
			Assert::IsTrue(g.pcard[1] == 22);
			Assert::IsTrue(g.pcard[2] == 10);
			Assert::IsTrue(g.pcard[3] == 22);
			Assert::IsTrue(g.pcard[4] == 9);
			Assert::IsTrue(g.pcard[5] == 23);
			Assert::IsTrue(g.pcard[6] == 8);
			Assert::IsTrue(g.pcard[7] == 21);
			Assert::IsTrue(g.pcard[8] == 6);
			Assert::IsTrue(g.pcard[9] == 24);
		}


	};
}
