// Manhab Zafar (22I-1957)       
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//Grid of 8x8
string grid[8][8] = {
		{"|R1| ", "|N1| ","|B1| ", "|Q1| " , "|K1| " , "|B1| " , "|N1| " , "|R1| "},
		{"|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | "},
		{"|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | "},
		{"|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | "},
		{"|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | "},
		{"|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | "},
		{"|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | ","|  | "},
		{ "|R2| ", "|N2| ","|B2| ", "|Q2| " , "|K2| " , "|B2| " , "|N2| " , "|R2| "} };


// Displaying the grid				

void Display_board(string grid[8][8])
{
	cout << "  ";
	for (int j = 0; j < 8; ++j) 
	{
		cout << " " << j << "    ";
	}
	cout << endl;

	for (int i = 0; i < 8; ++i)
	{
		cout << i << " ";

		for (int j = 0; j < 8; ++j)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl << endl;
	}
}

//---<Renew it after every movement of piece>---\\			

void Renew(string grid[8][8])
{
	system("cls");
	for (int i = 0; i < 8; ++i) {

		for (int j = 0; j < 8; ++j) {
			if (grid[i][j] == "|0 | ")
			{
				grid[i][j] = "|  | ";
			}
		}
	}
	
	//giving DELAY to system for its turn//
	
	Display_board(grid);
	for (int i = 0; i < 200000; i++)
	{

	}
	for (int i = 0; i < 200000; i++)
	{

	}
	for (int i = 0; i < 200000; i++)
	{

	}
	for (int i = 0; i < 200000; i++)
	{

	}

	
}


//<----------ROCK FUNCTION------------>\\

void user_rock(string Grid[8][8])
{
	Display_board(Grid);
	int r2 = 0, c2 = 0, x2 = 0, y2 = 0, m = 0;

	jump40:
	cout << "Initial position of the rock is: " << endl;
	cout << "Row : ";
	cin >> r2;
	cout << "Column: ";
	cin >> c2;
	const int a = r2;
	const int j = c2;
	m = r2;

	//---<Displaying zeroes according to rock movement>---\\

	if (grid[r2][c2] != "|R2| ")
	{
		cout << "Not correct initial position!!! Enter again!!";
		goto jump40;
	}


	if (grid[r2][c2] == "|R2| ")
	{

		while (r2 > 1)
		{
			if (Grid[r2 - 1][c2] == "|  | ")
			{
				Grid[r2 - 1][c2] = "|0 | ";
			}
			r2--;
		}

		while (r2 < 8)
		{
			if (Grid[r2 + 1][c2] == "|  | ")
			{
				Grid[r2 + 1][c2] = "|0 | ";
			}
			r2++;
		}

		while (c2 > 0)
		{
			if (Grid[m][c2 - 1] == "|  | ")
			{
				Grid[m][c2 - 1] = "|0 | ";

			}

			c2--;
		}

		while (c2 < 7)
		{
			if (Grid[m][c2 + 1] == "|  | ")
			{
				Grid[m][c2 + 1] = "|0 | ";
			}
			c2++;
		}

		//---<Again displaying the board>---\\

		jump10:
		Display_board(Grid);
		cout << "At what index you want to move rock: " << endl;
		cout << "Row: ";
		cin >> x2;
		cout << "Column: ";
		cin >> y2;

		if (Grid[x2][y2] != "|0 | "&& Grid[x2][y2]!="|R1| " && Grid[x2][y2] != "|N1| " && Grid[x2][y2] != "|B1| " && Grid[x2][y2] != "|Q1| " && Grid[x2][y2] != "|K1| ")
		{
			cout << "Out of range! Enter again!!" << endl;
			goto jump10;
		}
		if (Grid[x2][y2] == "|K1| ")
		{
			Grid[x2][y2] = "|R2| ";
			Grid[a][j] = "|  | ";
			Display_board(Grid);
			Renew(Grid);
			cout << endl << endl << endl << endl;
			cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
			cout << endl << endl << endl << endl;

		
			exit(1);
			
			
		}
		else
		{
			Grid[x2][y2] = "|R2| ";
			Grid[a][j] = "|  | ";
			Renew(Grid);
		}
		
		

		
	}

	else
	{
		cout << "---------!!Invalid input!!---------" << endl;
	}
	
}

//<----------KNIGHT FUNCTION------------>//

void user_knight(string Grid[8][8])
{
	Display_board(Grid);
	int m2 = 0, n2 = 0, v2 = 0, w2 = 0, z = 0;
	jump41:
	cout << "Initial position of the knight is: " << endl;
	cout << "Row : ";
	cin >> m2;
	cout << "Column: ";
	cin >> n2;
	const int b = m2;
	const int k = n2;
	z = m2;
	if (grid[m2][n2] != "|N2| ")
	{
		cout << "Not correct initial position!!! Enter again!!"<<endl;
		goto jump41;
	}
	//---<Displaying zeroes according to knight movement>---\\
	
	else if (grid[m2][n2] == "|N2| ")
	{

		if (Grid[m2 - 1][n2 - 2] == "|  | ")
		{
			Grid[m2 - 1][n2 - 2] = "|0 | ";
		}

		if (Grid[m2 + 1][n2 - 2] == "|  | ")
		{
			Grid[m2 + 1][n2 - 2] = "|0 | ";
		}

		if (Grid[m2 - 2][n2 - 1] == "|  | ")
		{
			Grid[m2 - 2][n2 - 1] = "|0 | ";
		}

		if (Grid[m2 - 2][n2 + 1] == "|  | ")
		{
			Grid[m2 - 2][n2 + 1] = "|0 | ";
		}

		if (Grid[m2 - 1][n2 + 2] == "|  | ")
		{
			Grid[m2 - 1][n2 + 2] = "|0 | ";
		}

		if (Grid[m2 + 1][n2 + 2] == "|  | ")
		{
			Grid[m2 + 1][n2 + 2] = "|0 | ";
		}

		if (Grid[m2 + 2][n2 - 1] == "|  | ")
		{
			Grid[m2 + 2][n2 - 1] = "|0 | ";
		}

		if (Grid[m2 + 2][n2 + 1] == "|  | ")
		{
			Grid[m2 + 2][n2 + 1] = "|0 | ";
		}


		//---<Again displaying the board>---\\

		jump11:
		Display_board(Grid);
		cout << "At what index you want to move knight: " << endl;
		cout << "Row: ";
		cin >> v2;
		cout << "Column: ";
		cin >> w2;

		if (Grid[v2][w2] != "|0 | " && Grid[v2][w2] != "|R1| " && Grid[v2][w2] != "|N1| " && Grid[v2][w2] != "|B1| " && Grid[v2][w2] != "|Q1| " && Grid[v2][w2] != "|K1| ")
		{
			cout << "Out of range! Enter again!!" << endl;
			goto jump11;
		}
		if (Grid[v2][w2] == "|K1| ")
		{
			Grid[v2][w2] = "|N2| ";
			Grid[b][k] = "|  | ";
			Display_board(Grid);
			Renew(Grid);
			cout << endl << endl << endl << endl;
			cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
			cout << endl << endl << endl << endl;


			exit(1);
		}

		else
		{
			Grid[v2][w2] = "|N2| ";
			Grid[b][k] = "|  | ";
			Renew(Grid);
		}

		
	}
	else
	{
		cout << "---------!!Invalid input!!---------" << endl;
	}

}
//<----------BISHOP FUNCTION------------>//


void user_bishop(string Grid[8][8])
{
	Display_board(Grid);
	int i2 = 0, j2 = 0, o2 = 0, p2 = 0, y = 0, u = 0;
	jump42:
	cout << "Initial position of the bishop is: " << endl;
	cout << "Row : ";
	cin >> i2;
	cout << "Column: ";
	cin >> j2;
	const int f = i2;
	const int l = j2;
	y = i2;
	u = j2;

	if (grid[i2][j2] != "|B2| ")
	{
		cout << "Not correct initial position!!! Enter again!!"<<endl;
		goto jump42;
	}

	//---<Displaying zeroes according to bishop movement>---\\

	else if (grid[i2][j2] == "|B2| ")
	{
		while (i2 > 0 && j2 > 0)
		{
			if (Grid[i2 - 1][j2 - 1] == "|  | ")
			{
				Grid[i2 - 1][j2 - 1] = "|0 | ";
			}
			i2--;
			j2--;
		}


		while (i2 < 7 && j2 < 7)
		{
			if (Grid[i2 + 1][j2 + 1] == "|  | ")
			{
				Grid[i2 + 1][j2 + 1] = "|0 | ";
			}
			i2++;
			j2++;
		}

		while (u < 7 && y>0)
		{
			if (Grid[y - 1][u + 1] == "|  | ")
			{
				Grid[y - 1][u + 1] = "|0 | ";

			}
			y--;
			u++;
		}

		while (u > 0 && y < 7)
		{

			if (Grid[y + 1][u - 1] == "|  | ")
			{
				Grid[y + 1][u - 1] = "|0 | ";
			}
			y++;
			u--;
		}


		//---<Again displaying the board>---\\

		jump12:
		Display_board(Grid);
		cout << "At what index you want to move bishop: " << endl;
		cout << "Row: ";
		cin >> o2;
		cout << "Column: ";
		cin >> p2;

		if (Grid[o2][p2] != "|0 | " && Grid[o2][p2] != "|R1| " && Grid[o2][p2] != "|N1| " && Grid[o2][p2] != "|B1| " && Grid[o2][p2] != "|Q1| " && Grid[o2][p2] != "|K1| ")
		{
			cout << "Out of range! Enter again!!" << endl;
			goto jump12;
		}

		if (Grid[o2][p2] == "|K1| ")
		{
			Grid[o2][p2] = "|B2| ";
			Grid[f][l] = "|  | ";
			Display_board(Grid);
			Renew(Grid);
			cout << endl << endl << endl << endl;
			cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
			cout << endl << endl << endl << endl;


			exit(1);
		}
		else
		{
			Grid[o2][p2] = "|B2| ";
			Grid[f][l] = "|  | ";
			Renew(Grid);
		}

		
	}
	else
	{

		cout << "---------!!Invalid input!!---------" << endl;

	}


}

//<----------QUEEN FUNCTION------------>//

void user_queen(string Grid[8][8])
{
	Display_board(Grid);
	int d2 = 0, e2 = 0, g2 = 0, h2 = 0, k = 0, q = 0, x2 = 0, y2 = 0, s = 0;
	jump43:
	cout << "Initial position of the Queen is: " << endl;
	cout << "Row : ";
	cin >> d2;
	cout << "Column: ";
	cin >> e2;
	const int f = d2;
	const int l = e2;
	k = d2;
	s = d2;
	q = e2;
	x2 = d2;
	y2 = e2;

	if (grid[d2][e2] != "|Q2| ")
	{
		cout << "Not correct initial position!!! Enter again!!"<<endl;
		goto jump43;
	}
	
	//---<Displaying zeroes according to queen movement>---\\

	
	else if (grid[d2][e2] == "|Q2| ")
	{

		while (d2 > 1)
		{
			if (Grid[d2 - 1][e2] == "|  | ")
			{
				Grid[d2 - 1][e2] = "|0 | ";
			}
			d2--;
		}

		while (d2 < 8)
		{
			if (Grid[d2 + 1][e2] == "|  | ")
			{
				Grid[d2 + 1][e2] = "|0 | ";
			}
			d2++;
		}

		while (e2 > 0)
		{
			if (Grid[k][e2 - 1] == "|  | ")
			{
				Grid[k][e2 - 1] = "|0 | ";

			}

			e2--;
		}

		while (e2 < 7)
		{
			if (Grid[k][e2 + 1] == "|  | ")
			{
				Grid[k][e2 + 1] = "|0 | ";
			}
			e2++;
		}

		while (x2 > 0 && y2 > 0)
		{
			if (Grid[x2 - 1][y2 - 1] == "|  | ")
			{
				Grid[x2 - 1][y2 - 1] = "|0 | ";
			}
			x2--;
			y2--;
		}


		while (x2 < 7 && y2 < 7)
		{
			if (Grid[x2 + 1][y2 + 1] == "|  | ")
			{
				Grid[x2 + 1][y2 + 1] = "|0 | ";
			}
			x2++;
			y2++;
		}

		while (q < 7 && s>0)
		{
			if (Grid[s - 1][q + 1] == "|  | ")
			{
				Grid[s - 1][q + 1] = "|0 | ";

			}
			s--;
			q++;
		}

		while (q > 0 && s < 7)
		{

			if (Grid[s + 1][q - 1] == "|  | ")
			{
				Grid[s + 1][q - 1] = "|0 | ";
			}
			s++;
			q--;
		}

		//---<Again displaying the board>---//

		jump13:
		Display_board(Grid);
		cout << "At what index you want to move Queen: " << endl;
		cout << "Row: ";
		cin >> g2;
		cout << "Column: ";
		cin >> h2;

		if (Grid[g2][h2] != "|0 | " && Grid[g2][h2] != "|R1| " && Grid[g2][h2] != "|N1| " && Grid[g2][h2] != "|B1| " && Grid[g2][h2] != "|Q1| " && Grid[g2][h2] != "|K1| "&& Grid[g2][h2] != "|K2| ")
		{
			cout << "Out of range! Enter again!!" << endl;
			goto jump13;
		}
		if (Grid[g2][h2] == "|K1| ")
		{
			Grid[g2][h2] = "|Q2| ";
			Grid[f][l] = "|  | ";
			Display_board(Grid);
			Renew(Grid);
			cout << endl << endl << endl << endl;
			cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
			cout << endl << endl << endl << endl;


			exit(1);
		}
		if (Grid[g2][h2] == "|K2| ")
		{
			if (Grid[g2 + 1][h2] == "|K2| " && Grid[g2 - 1][h2] == "|K2| " && Grid[g2][h2 + 1] == "|K2| " && Grid[g2][h2 - 1] == "|K2| ")
			{
				Grid[g2][h2] = "|Q2| ";
				Grid[f][l] = "|K2| ";
				Display_board(Grid);
				Renew(Grid);

			}
		}
		else
		{
			Grid[g2][h2] = "|Q2| ";
			Grid[f][l] = "|  | ";
			Renew(Grid);
		}

		
	}

	else
	{

		cout << "---------!!Invalid input!!---------" << endl;

	}

}

//<-----KING FUNCTION------>//

void  user_king(string Grid[8][8])
{
	Display_board(Grid);
	int r2 = 0, t2 = 0, c2 = 0, u2 = 0, w = 0;
	jump44:
	cout << "Initial position of the KING is: " << endl;
	cout << "Row : ";
	cin >> r2;
	cout << "Column: ";
	cin >> t2;
	const int b = r2;
	const int k = t2;
	w = r2;

	if (grid[r2][t2] != "|K2| ")
	{
		cout << "Not correct initial position!!! Enter again!!"<<endl;
		goto jump44;
	}
	//---<Displaying zeroes according to KING movement>---\\

	else if (grid[r2][t2] == "|K2| ")
	{

		if (Grid[r2 - 1][t2] == "|  | ")
		{
			Grid[r2 - 1][t2] = "|0 | ";
		}

		if (Grid[r2 + 1][t2] == "|  | ")
		{
			Grid[r2 + 1][t2] = "|0 | ";
		}

		if (Grid[r2][t2 - 1] == "|  | ")
		{
			Grid[r2][t2 - 1] = "|0 | ";
		}

		if (Grid[r2][t2 + 1] == "|  | ")
		{
			Grid[r2][t2 + 1] = "|0 | ";
		}

		if (Grid[r2 - 1][t2 - 1] == "|  | ")
		{
			Grid[r2 - 1][t2 - 1] = "|0 | ";
		}

		if (Grid[r2 + 1][t2 + 1] == "|  | ")
		{
			Grid[r2 + 1][t2 + 1] = "|0 | ";
		}

		if (Grid[r2 + 1][t2 - 1] == "|  | ")
		{
			Grid[r2 + 1][t2 - 1] = "|0 | ";
		}

		if (Grid[r2 - 1][t2 + 1] == "|  | ")
		{
			Grid[r2 - 1][t2 + 1] = "|0 | ";
		}


		//---<Again displaying the board>---\\

	jump14:
		Display_board(Grid);
		cout << "At what index you want to move KING: " << endl;
		cout << "Row: ";
		cin >> c2;
		cout << "Column: ";
		cin >> u2;

		if (Grid[c2][u2] != "|0 | " && Grid[c2][u2] != "|R1| " && Grid[c2][u2] != "|N1| " && Grid[c2][u2] != "|B1| " && Grid[c2][u2] != "|Q1| " && Grid[c2][u2] != "|K1| " && Grid[c2][u2] != "|Q2| ")
		{
			cout << "Out of range! Enter again!!" << endl;
			goto jump14;
		}


		if (Grid[c2 - 1][u2] != "|  | " && Grid[c2 - 1][u2 + 1] != "|  | " && Grid[c2 - 1][u2 - 1] != "|  | " && Grid[c2][u2 - 1] != "|  | " && Grid[c2][u2 + 1] != "|  | " && Grid[c2 + 1][u2 - 1] != "|  | " && Grid[c2 + 1][u2] != "|  | " && Grid[c2 + 1][u2 + 1] != "|  | ")
		{
			cout << endl << endl << endl << endl;
			cout << "---------C H E C K M A T E!   K I N G  I S  T R A P P E D!!------------" << endl;
			cout << endl << endl << endl << endl;


			exit(1);
		}
		if (Grid[c2][u2] == "|K1| ")
		{
			Grid[c2][u2] = "|K2| ";
			Grid[b][k] = "|  | ";
			Display_board(Grid);
			Renew(Grid);
			cout << endl << endl << endl << endl;
			cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
			cout << endl << endl << endl << endl;


			exit(1);
		}
		if (Grid[c2-1][u2] == "|Q2| " && Grid[c2 + 1][u2] == "|Q2| " && Grid[c2][u2 - 1] == "|Q2| "&& Grid[c2][u2+1] == "|Q2| ")
		{
			Grid[c2][u2] = "|K2| ";
			Grid[b][k] = "|Q2| ";
			Display_board(Grid);
			Renew(Grid);

		}
		
		else
		{
			Grid[c2][u2] = "|K2| ";
			Grid[b][k] = "|  | ";
			Renew(Grid);
		}

	}
	else
	{
		cout << "---------!!Invalid input!!---------" << endl;
	}


}

//-----------<SYSTEM HANDLING>------------//

void system(string Grid[8][8])
{
	
	int a = rand() % 7;

	if (a == 0)
	{

		//Display_board(Grid);
		jump:
		int r2 = 0, c2 = 0, x2 = 0, y2 = 0, m = 0;

		
		r2 = rand() % 7;
		c2 = rand() % 7;

		const int a = r2;
		const int j = c2;
		m = r2;
		if (grid[r2][c2] != "|R1| ")
		{
			goto jump;
		}
		else
		{
			cout << "Initial position of the rock is: " << endl;
			cout << "Row : ";
			cout << r2;
			cout << endl;
			cout << "Column: ";
			cout << c2;
			cout << endl;
			//---<Displaying zeroes according to rock movement>---\\

			if (grid[r2][c2] == "|R1| ")
			{

				while (r2 > 1)
				{
					if (Grid[r2 - 1][c2] == "|  | ")
					{
						Grid[r2 - 1][c2] = "|0 | ";
					}
					r2--;
				}

				while (r2 < 8)
				{
					if (Grid[r2 + 1][c2] == "|  | ")
					{
						Grid[r2 + 1][c2] = "|0 | ";
					}
					r2++;
				}

				while (c2 > 0)
				{
					if (Grid[m][c2 - 1] == "|  | ")
					{
						Grid[m][c2 - 1] = "|0 | ";

					}

					c2--;
				}

				while (c2 < 7)
				{
					if (Grid[m][c2 + 1] == "|  | ")
					{
						Grid[m][c2 + 1] = "|0 | ";
					}
					c2++;
				}

				//---<Again displaying the board>---\\

				Display_board(Grid);
				//srand(time(0));

				jump15:
				x2 = rand() % 7;
				cout << "At what index you want to move rock: " << endl;
				cout << "Row: ";
				cout << x2;
				cout << endl;
				y2 = rand() % 7;
				cout << "Column: ";
				cout << y2;
				cout << endl;
				while (x2 == r2 || y2 == c2)
				{
					x2 = rand() % 7;
					y2 = rand() % 7;
				}

				if (Grid[x2][y2] != "|0 | " && Grid[x2][y2] != "|K2| ")
				{
					
					goto jump15;
				}

				if (Grid[x2][y2] == "|K2| ")
				{
					Grid[x2][y2] = "|R1| ";
					Grid[a][j] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;

					exit(1);
				}
				else
				{

					Grid[x2][y2] = "|R1| ";
					Grid[a][j] = "|  | ";
					Renew(Grid);
				}

			}

			else
			{
				cout << "---------!!Invalid input!!---------" << endl;
			}
		}
	}

	else if (a == 1)
	{
		Display_board(Grid);
	jump1:
		int m2 = 0, n2 = 0, v2 = 0, w2 = 0, z = 0;
	//	srand(time(0));
		m2 = rand() % 7;
		n2 = rand() % 7;

		const int b = m2;
		const int k = n2;
		z = m2;


		if (grid[m2][n2] != "|N1| ")
		{
			goto jump1;
		}
		else
		{
			cout << "Initial position of the knight is: " << endl;
			cout << "Row : ";
			cout << m2;
			cout << endl;
			cout << "Column: ";
			cout << n2;
			cout << endl;
			//---<Displaying zeroes according to knight movement>---\\

			if (grid[m2][n2] == "|N1| ")
			{

				if (Grid[m2 - 1][n2 - 2] == "|  | ")
				{
					Grid[m2 - 1][n2 - 2] = "|0 | ";
				}

				if (Grid[m2 + 1][n2 - 2] == "|  | ")
				{
					Grid[m2 + 1][n2 - 2] = "|0 | ";
				}

				if (Grid[m2 - 2][n2 - 1] == "|  | ")
				{
					Grid[m2 - 2][n2 - 1] = "|0 | ";
				}

				if (Grid[m2 - 2][n2 + 1] == "|  | ")
				{
					Grid[m2 - 2][n2 + 1] = "|0 | ";
				}

				if (Grid[m2 - 1][n2 + 2] == "|  | ")
				{
					Grid[m2 - 1][n2 + 2] = "|0 | ";
				}

				if (Grid[m2 + 1][n2 + 2] == "|  | ")
				{
					Grid[m2 + 1][n2 + 2] = "|0 | ";
				}

				if (Grid[m2 + 2][n2 - 1] == "|  | ")
				{
					Grid[m2 + 2][n2 - 1] = "|0 | ";
				}

				if (Grid[m2 + 2][n2 + 1] == "|  | ")
				{
					Grid[m2 + 2][n2 + 1] = "|0 | ";
				}


				//---<Again displaying the board>---\\

				Display_board(Grid);
				jump16:
				v2 = rand() % 7;
				cout << "At what index you want to move knight: " << endl;
				cout << "Row: ";
				cout << v2;
				cout << endl;
				w2 = rand() % 7;
				cout << "Column: ";
				cout << w2;
				cout << endl;
				while (v2 == m2 || w2 == n2)
				{
					v2 = rand() % 7;
					w2 = rand() % 7;
				}

				if (Grid[v2][w2] != "|0 | " && Grid[v2][w2] != "|K2| ")
				{

					goto jump16;
				}
				if (Grid[v2][w2] == "|K2| ")
				{
					Grid[v2][w2] = "|N1| ";
					Grid[b][k] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;

					exit(1);
				}
				else
				{

					Grid[v2][w2] = "|N1| ";
					Grid[b][k] = "|  | ";
					Renew(Grid);
				}
			}
			else
			{
				cout << "---------!!Invalid input!!---------" << endl;
			}
		}
	}

	else if (a == 2)
	{
		Display_board(Grid);
	jump2:
		int i2 = 0, j2 = 0, o2 = 0, p2 = 0, y = 0, u = 0;

		srand(time(0));
		i2 = rand() % 7;
		j2 = rand() % 7;

		const int f = i2;
		const int l = j2;
		y = i2;
		u = j2;
		if (grid[i2][j2] != "|B1| ")
		{
			goto jump2;
		}
		else
		{
			cout << "Initial position of the bishop is: " << endl;
			cout << "Row : ";
			cout << i2;
			cout << endl;
			cout << "Column: ";
			cout << j2;
			cout << endl;
			//---<Displaying zeroes according to bishop movement>---\\

			if (grid[i2][j2] == "|B1| ")
			{
				while (i2 > 0 && j2 > 0)
				{
					if (Grid[i2 - 1][j2 - 1] == "|  | ")
					{
						Grid[i2 - 1][j2 - 1] = "|0 | ";
					}
					i2--;
					j2--;
				}


				while (i2 < 7 && j2 < 7)
				{
					if (Grid[i2 + 1][j2 + 1] == "|  | ")
					{
						Grid[i2 + 1][j2 + 1] = "|0 | ";
					}
					i2++;
					j2++;
				}

				while (u < 7 && y>0)
				{
					if (Grid[y - 1][u + 1] == "|  | ")
					{
						Grid[y - 1][u + 1] = "|0 | ";

					}
					y--;
					u++;
				}

				while (u > 0 && y < 7)
				{

					if (Grid[y + 1][u - 1] == "|  | ")
					{
						Grid[y + 1][u - 1] = "|0 | ";
					}
					y++;
					u--;
				}


				//---<Again displaying the board>---\\

				Display_board(Grid);
				//srand(time(0));

				jump17:
				o2 = rand() % 7;
				cout << "At what index you want to move bishop: " << endl;
				cout << "Row: ";
				cout << o2;
				cout << endl;
				p2 = rand() % 7;
				cout << "Column: ";
				cout << p2;
				cout << endl;

				while (o2 == i2 || p2 == j2)
				{
					o2 = rand() % 7;
					p2 = rand() % 7;
				}

				if (Grid[o2][p2] != "|0 | "  && Grid[o2][p2] != "|K2| ")
				{

					goto jump17;
				}
				if (Grid[o2][p2] == "|K2| ")
				{
					Grid[o2][p2] = "|B1| ";
					Grid[f][l] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;


					exit(1);
				}

				else
				{

					Grid[o2][p2] = "|B1| ";
					Grid[f][l] = "|  | ";
					Renew(Grid);
				}

			}
			else
			{

				cout << "---------!!Invalid input!!---------" << endl;

			}
		}
	}

	else if (a == 3)
	{
		Display_board(Grid);
	jump3:
		int d2 = 0, e2 = 0, g2 = 0, h2 = 0, k = 0, q = 0, x2 = 0, y2 = 0, s = 0;
		//srand(time(0));
		d2 = rand() % 7;
		e2 = rand() % 7;

		const int f = d2;
		const int l = e2;
		k = d2;
		s = d2;
		q = e2;
		x2 = d2;
		y2 = e2;
		if (grid[d2][e2] != "|Q1| ")
		{
			goto jump3;
		}
		else
		{
			cout << "Initial position of the Queen is: " << endl;
			cout << "Row : ";
			cout << d2;
			cout << endl;
			cout << "Column: ";
			cout << e2;
			cout << endl;

			//---<Displaying zeroes according to queen movement>---\\

			if (grid[d2][e2] == "|Q1| ")
			{

				while (d2 > 1)
				{
					if (Grid[d2 - 1][e2] == "|  | ")
					{
						Grid[d2 - 1][e2] = "|0 | ";
					}
					d2--;
				}

				while (d2 < 8)
				{
					if (Grid[d2 + 1][e2] == "|  | ")
					{
						Grid[d2 + 1][e2] = "|0 | ";
					}
					d2++;
				}

				while (e2 > 0)
				{
					if (Grid[k][e2 - 1] == "|  | ")
					{
						Grid[k][e2 - 1] = "|0 | ";

					}

					e2--;
				}

				while (e2 < 7)
				{
					if (Grid[k][e2 + 1] == "|  | ")
					{
						Grid[k][e2 + 1] = "|0 | ";
					}
					e2++;
				}

				while (x2 > 0 && y2 > 0)
				{
					if (Grid[x2 - 1][y2 - 1] == "|  | ")
					{
						Grid[x2 - 1][y2 - 1] = "|0 | ";
					}
					x2--;
					y2--;
				}


				while (x2 < 7 && y2 < 7)
				{
					if (Grid[x2 + 1][y2 + 1] == "|  | ")
					{
						Grid[x2 + 1][y2 + 1] = "|0 | ";
					}
					x2++;
					y2++;
				}

				while (q < 7 && s>0)
				{
					if (Grid[s - 1][q + 1] == "|  | ")
					{
						Grid[s - 1][q + 1] = "|0 | ";

					}
					s--;
					q++;
				}

				while (q > 0 && s < 7)
				{

					if (Grid[s + 1][q - 1] == "|  | ")
					{
						Grid[s + 1][q - 1] = "|0 | ";
					}
					s++;
					q--;
				}

				//---<Again displaying the board>---//

				Display_board(Grid);
				jump18:
				g2 = rand() % 7;
				cout << "At what index you want to move Queen: " << endl;
				cout << "Row: ";
				cout << g2;
				cout << endl;
				h2 = rand() % 7;
				cout << "Column: ";
				cout << h2;
				cout << endl;
				while (g2 == d2 || h2 == e2)
				{
					g2 = rand() % 7;
					h2 = rand() % 7;
				}

				if (Grid[g2][h2] != "|0 | " && Grid[g2][h2] != "|K2| ")
				{

					goto jump18;
				}
				/*if (Grid[g2 + 1][h2] == "|K1| " && Grid[g2 - 1][h2] == "|K1| " && Grid[g2][h2 + 1] == "|K1| " && Grid[g2][h2 - 1] == "|K1| ")
				{
					Grid[g2][h2] = "|Q1| ";
					Grid[f][l] = "|K1| ";
					Display_board(Grid);
					Renew(Grid);

				}*/
				if (Grid[g2][h2] == "|K2| ")
				{
					Grid[g2][h2] = "|Q1| ";
					Grid[f][l] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;


					exit(1);
				}
				else
				{

					Grid[g2][h2] = "|Q1| ";
					Grid[f][l] = "|  | ";
					Renew(Grid);
				}
			}

			else
			{

				cout << "---------!!Invalid input!!---------" << endl;

			}
		}
	}

	else if (a == 4)
	{
		Display_board(Grid);
	jump4:
		int r2 = 0, t2 = 0, c2 = 0, u2 = 0, w = 0;

		//srand(time(0));
		r2 = rand() % 7;
		t2 = rand() % 7;

		const int b = r2;
		const int k = t2;
		w = r2;

		if (grid[r2][t2] != "|K1| ")
		{
			goto jump4;
		}

		else
		{
			cout << "Initial position of the KING is: " << endl;
			cout << "Row : ";
			cout << r2;
			cout << endl;
			cout << "Column: ";
			cout << t2;
			cout << endl;
			//---<Displaying zeroes according to KING movement>---\\

			if (grid[r2][t2] == "|K1| ")
			{

				if (Grid[r2 - 1][t2] == "|  | ")
				{
					Grid[r2 - 1][t2] = "|0 | ";
				}

				if (Grid[r2 + 1][t2] == "|  | ")
				{
					Grid[r2 + 1][t2] = "|0 | ";
				}

				if (Grid[r2][t2 - 1] == "|  | ")
				{
					Grid[r2][t2 - 1] = "|0 | ";
				}

				if (Grid[r2][t2 + 1] == "|  | ")
				{
					Grid[r2][t2 + 1] = "|0 | ";
				}

				if (Grid[r2 - 1][t2 - 1] == "|  | ")
				{
					Grid[r2 - 1][t2 - 1] = "|0 | ";
				}

				if (Grid[r2 + 1][t2 + 1] == "|  | ")
				{
					Grid[r2 + 1][t2 + 1] = "|0 | ";
				}

				if (Grid[r2 + 1][t2 - 1] == "|  | ")
				{
					Grid[r2 + 1][t2 - 1] = "|0 | ";
				}

				if (Grid[r2 - 1][t2 + 1] == "|  | ")
				{
					Grid[r2 - 1][t2 + 1] = "|0 | ";
				}


				//---<Again displaying the board>---\\

				Display_board(Grid);
		//		srand(time(0));

				jump19:
				c2 = rand() % 7;
				cout << "At what index you want to move KING: " << endl;
				cout << "Row: ";
				cout << c2;
				cout << endl;
				u2 = rand() % 7;
				cout << "Column: ";
				cout << u2;
				cout << endl;
				while (c2 == r2 || u2 == t2)
				{
					c2 = rand() % 7;
					u2 = rand() % 7;
				}

				if (Grid[c2][u2] != "|0 | " && Grid[c2][u2] != "|K2| ")
				{

					goto jump19;
				}
				if (Grid[c2][u2] == "|K2| ")
				{
					Grid[c2][u2] = "|K1| ";
					Grid[b][k] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;


					exit(1);
				}
				if (Grid[c2 - 1][u2] != "|  | " && Grid[c2 - 1][u2 + 1] != "|  | " && Grid[c2 - 1][u2 - 1] != "|  | " && Grid[c2][u2 - 1] != "|  | " && Grid[c2][u2 + 1] != "|  | " && Grid[c2 + 1][u2 - 1] != "|  | " && Grid[c2 + 1][u2] != "|  | " && Grid[c2 + 1][u2 + 1] != "|  | ")
				{
					cout << endl << endl << endl << endl;
					cout << "---------C H E C K M A T E!   K I N G  I S  T R A P P E D!!------------" << endl;
					cout << endl << endl << endl << endl;


					exit(1);
				}
				/*if (Grid[c2-1][u2] == "|Q1| " && Grid[c2 + 1][u2] == "|Q1| " && Grid[c2][u2 - 1] == "|Q1| " && Grid[c2][u2 + 1] == "|Q1| ")
				{
					Grid[c2][u2] = "|Q1| ";
					Grid[b][k] = "|K1| ";
					Display_board(Grid);
					Renew(Grid);

				}*/
				else
				{
					Grid[c2][u2] = "|K1| ";
					Grid[b][k] = "|  | ";
					Renew(Grid);
				}
				


			}
			else
			{
				cout << "---------!!Invalid input!!---------" << endl;
			}
		}
	}

	else if (a == 5)
	{
		Display_board(Grid);
	jump5:
		int i2 = 0, j2 = 0, o2 = 0, p2 = 0, y = 0, u = 0;

		//srand(time(0));
		i2 = rand() % 7;
		j2 = rand() % 7;


		const int f = i2;
		const int l = j2;
		y = i2;
		u = j2;

		if (grid[i2][j2] != "|B1| ")
		{
			goto jump5;
		}

		else
		{
			cout << "Initial position of the bishop is: " << endl;
			cout << "Row : ";
			cout << i2;
			cout << endl;
			cout << "Column: ";
			cout << j2;
			cout << endl;

			//---<Displaying zeroes according to bishop movement>---\\

			if (grid[i2][j2] == "|B1| ")
			{

				while (i2 > 0 && j2 > 0)
				{
					if (Grid[i2 - 1][j2 - 1] == "|  | ")
					{
						Grid[i2 - 1][j2 - 1] = "|0 | ";
					}
					i2--;
					j2--;
				}


				while (i2 < 7 && j2 < 7)
				{
					if (Grid[i2 + 1][j2 + 1] == "|  | ")
					{
						Grid[i2 + 1][j2 + 1] = "|0 | ";
					}
					i2++;
					j2++;
				}

				while (u < 7 && y>0)
				{
					if (Grid[y - 1][u + 1] == "|  | ")
					{
						Grid[y - 1][u + 1] = "|0 | ";

					}
					y--;
					u++;
				}

				while (u > 0 && y < 7)
				{

					if (Grid[y + 1][u - 1] == "|  | ")
					{
						Grid[y + 1][u - 1] = "|0 | ";
					}
					y++;
					u--;
				}


				//---<Again displaying the board>---\\

				Display_board(Grid);
			//	srand(time(0));

				jump20:
				o2 = rand() % 7;
				cout << "At what index you want to move bishop: " << endl;
				cout << "Row: ";
				cout << o2;
				cout << endl;
				p2 = rand() % 7;
				cout << "Column: ";
				cout << p2;
				cout << endl;
				while (o2 == i2 || p2 == j2)
				{
					o2 = rand() % 7;
					p2 = rand() % 7;
				}

				if (Grid[o2][p2] != "|0 | " && Grid[o2][p2] != "|K2| ")
				{

					goto jump20;
				}
				if (Grid[o2][p2] == "|K2| ")
				{
					Grid[o2][p2] = "|B1| ";
					Grid[f][l] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;


					exit(1);
				}

				else
				{
					Grid[o2][p2] = "|B1| ";
					Grid[f][l] = "|  | ";
					Renew(Grid);
				}
			}
			else
			{

				cout << "---------!!Invalid input!!---------" << endl;

			}
		}
	}

	else if (a == 6)
	{
		Display_board(Grid);
		
		
	jump6:
		int m2 = 0, n2 = 0, v2 = 0, w2 = 0, z = 0,s=0;
	//	srand(time(0));
		m2 = rand() % 7;
		n2 = rand() % 7;
		

		const int b = m2;
		const int k = n2;
		z = m2;

		if (grid[m2][n2] != "|N1| ")
		{
			goto jump6;
		}

		else
		{
			cout << "Initial position of the knight is: " << endl;
			cout << "Row : ";
			cout << m2;
			cout << endl;
			cout << "Column: ";
			cout << n2;
			cout << endl;
			//---<Displaying zeroes according to knight movement>---\\
			
			if (grid[m2][n2] == "|N1| ")
			{

				if (Grid[m2 - 1][n2 - 2] == "|  | ")
				{
					Grid[m2 - 1][n2 - 2] = "|0 | ";
				}

				if (Grid[m2 + 1][n2 - 2] == "|  | ")
				{
					Grid[m2 + 1][n2 - 2] = "|0 | ";
				}

				if (Grid[m2 - 2][n2 - 1] == "|  | ")
				{
					Grid[m2 - 2][n2 - 1] = "|0 | ";
				}

				if (Grid[m2 - 2][n2 + 1] == "|  | ")
				{
					Grid[m2 - 2][n2 + 1] = "|0 | ";
				}

				if (Grid[m2 - 1][n2 + 2] == "|  | ")
				{
					Grid[m2 - 1][n2 + 2] = "|0 | ";
				}

				if (Grid[m2 + 1][n2 + 2] == "|  | ")
				{
					Grid[m2 + 1][n2 + 2] = "|0 | ";
				}

				if (Grid[m2 + 2][n2 - 1] == "|  | ")
				{
					Grid[m2 + 2][n2 - 1] = "|0 | ";
				}

				if (Grid[m2 + 2][n2 + 1] == "|  | ")
				{
					Grid[m2 + 2][n2 + 1] = "|0 | ";
				}



				//---<Again displaying the board>---\\

				Display_board(Grid);
				//srand(time(0));

				jump21:
				v2 = rand() % 7;
				cout << "At what index you want to move rock: " << endl;
				cout << "Row: ";
				cout << v2;
				cout << endl;
				w2 = rand() % 7;
				cout << "Column: ";
				cout << w2;
				cout << endl;
				while (v2 == m2 || w2 == n2)
				{
					v2 = rand() % 7;
					w2 = rand() % 7;
				}
				if (Grid[v2][w2] != "|0 | "  && Grid[v2][w2] != "|K2| ")
				{

					goto jump21;
				}
				if (Grid[v2][w2] == "|K2| ")
				{
					Grid[v2][w2] = "|N1| ";
					Grid[b][k] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;


					exit(1);
				}
				else
				{

					Grid[v2][w2] = "|N1| ";
					Grid[b][k] = "|  | ";
					Renew(Grid);
				}
			}
			else
			{
				cout << "---------!!Invalid input!!---------" << endl;
			}
		}
	}

	else if (a == 7)
	{

		//Display_board(Grid);
	jump7:
		int r2 = 0, c2 = 0, x2 = 0, y2 = 0, m = 0;

		//srand(time(0));
		r2 = rand() % 7;
		c2 = rand() % 7;

		const int a = r2;
		const int j = c2;
		m = r2;

		if (grid[r2][c2] != "|R1| ")
		{
			goto jump7;
		}
		else
		{
			cout << "Initial position of the rock is: " << endl;
			cout << "Row : ";
			cout << r2;
			cout << endl;
			cout << "Column: ";
			cout << c2;
			cout << endl;
			//---<Displaying zeroes according to rock movement>---\\

			if (grid[r2][c2] == "|R1| ")
			{

				while (r2 > 1)
				{
					if (Grid[r2 - 1][c2] == "|  | ")
					{
						Grid[r2 - 1][c2] = "|0 | ";
					}
					r2--;
				}

				while (r2 < 8)
				{
					if (Grid[r2 + 1][c2] == "|  | ")
					{
						Grid[r2 + 1][c2] = "|0 | ";
					}
					r2++;
				}

				while (c2 > 0)
				{
					if (Grid[m][c2 - 1] == "|  | ")
					{
						Grid[m][c2 - 1] = "|0 | ";

					}

					c2--;
				}

				while (c2 < 7)
				{
					if (Grid[m][c2 + 1] == "|  | ")
					{
						Grid[m][c2 + 1] = "|0 | ";
					}
					c2++;
				}

				//---<Again displaying the board>---\\

				Display_board(Grid);
			//	srand(time(0));

				jump22:
				x2 = rand() % 7;
				cout << "At what index you want to move rock: " << endl;
				cout << "Row: ";
				cout << x2;
				cout << endl;
				y2 = rand() % 7;
				cout << "Column: ";
				cout << y2;
				cout << endl;
				while (x2 == r2 || y2 == c2)
				{
					x2 = rand() % 7;
					y2 = rand() % 7;
				}
				if (Grid[x2][y2] != "|0 | " &&  Grid[x2][y2] != "|K2| ")
				{

					goto jump22;
				}
				if (Grid[x2][y2] == "|K2| ")
				{
					Grid[x2][y2] = "|R1| ";
					Grid[a][j] = "|  | ";
					Display_board(Grid);
					Renew(Grid);
					cout << endl << endl << endl << endl;
					cout << "--------- C H E C K M A T E!  K I N G  I S  F A L L E N!!------------" << endl;
					cout << endl << endl << endl << endl;


					exit(1);
				}

				else
				{


					Grid[x2][y2] = "|R1| ";
					Grid[a][j] = "|  | ";
					Renew(Grid);
				}

			}

			else
			{
				cout << "---------!!Invalid input!!---------" << endl;
			}
		}
	}


}

int user_peice()
{
	

			//<---Asking user to choose a piece for the movement--->\\

	string piece = "\0";
	while (piece != "f")
	{
		
	
			Renew(grid);

			cout << "Which piece do you want to select: " << endl;
			cout << "R2 : Rock " << endl;
			cout << "N2 : Knight " << endl;
			cout << "B2 : Bishop " << endl;
			cout << "Q2 : Queen " << endl;
			cout << "K2 : King " << endl;
			cout << "B2 : Bishop " << endl;
			cout << "N2 : Knight " << endl;
			cout << "R2 : Rock " << endl;
			cout << "f. finish" << endl;
			cout << "Piece: ";
			cin >> piece;

			if (piece == "R2")
			{
				user_rock(grid);
				Display_board(grid);
				system(grid);
			}

			else if (piece == "N2")
			{
				user_knight(grid);
				Display_board(grid);
				system(grid);
			}

			else if (piece == "B2")
			{
				user_bishop(grid);
				Display_board(grid);
				system(grid);
			}


			else if (piece == "Q2")
			{
				user_queen(grid);
				Display_board(grid);			
				system(grid);
			}


			else if (piece == "K2")
			{
				user_king(grid);
				Display_board(grid);
				system(grid);
			}

			else if (piece == "B2")
			{
				user_bishop(grid);
				Display_board(grid);
				system(grid);
			}

			else if (piece == "N2")
			{
				user_knight(grid);
				Display_board(grid);
				system(grid);
			}

			else if (piece == "R2")
			{
				user_rock(grid);
				Display_board(grid);
				system(grid);
			}

			//system(grid);
		if (piece == "f")
		{

			cout << "Thanks for finishing!!" << endl;

			return 0;
		}

	}


	//<---For Finishing the game--->\\

	


}

void start()
{

	srand(static_cast<unsigned>(time(nullptr)));

	user_peice();
}

//<-------MAIN FUNCTION------->\\

int main()
{
	
	start();

	
}
