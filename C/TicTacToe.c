#include <stdio.h>
#include <stdlib.h>

void Create_Blank_Array(char table[][3]);
void Print_Structure(char table[][3]);
void Select_Player(char* player, char table[][3]);
void Check_Winner(char table[][3]);
void Check_Row(char table[][3]);
void Check_Col(char table[][3]);
void Check_Diagonal(char table[][3]);
void Check_Draw(char table[][3]);

int main()
{
	system("cls");
	
	char table[3][3];
	char player = 'A';

	Create_Blank_Array(table);
	Print_Structure(table);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			Select_Player(&player, table);
			system("cls");
			Print_Structure(table);
			Check_Winner(table);
		}
	}
}

void Create_Blank_Array(char table[][3])
{
	for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			table[i][j]= ' ';
		}
	}
}

void Print_Structure(char table[][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(j!=2)
			{
				printf("    %c   |", table[i][j]);
			}
			else
			{
				printf("    %c", table[i][j]);
			}
			

		}
		if(i!=2)
		{
			printf("\n----------------------------\n");
		}
		
	}
}

void Select_Player(char* player, char table[][3])
{
	int row, col;

	if(*player == 'A')
	{
		printf("\nPlayer A (row and column) ->> ");
		scanf("%d %d", &row, &col);

		table[row][col] = 'X';

		*player = 'B';
	}
	else
	{
		printf("\nPlayer B (row and column) ->> ");
		scanf("%d %d", &row, &col);

		table[row][col] = 'O';

		*player = 'A';
	}
}

void Check_Winner(char table[][3])
{
	Check_Row(table);
	Check_Col(table);
	Check_Diagonal(table);
	Check_Draw(table);
}

void Check_Row(char table[][3])
{
	int count_X = 0;
	int count_O = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (table[i][j] == 'X')
			{
				count_X += 1; 
				count_O = 0;
			}
			else if (table[i][j] == 'O')
			{
				count_O += 1;
				count_X = 0; 
			}
			else
			{
				count_X = 0;
				count_O = 0;
				break;
			}
		}

		if (count_X == 3)
		{
			printf("\n\nPlayer A is winner\n\n");
			exit(0);
		}
		else if (count_O == 3)
		{
			printf("\n\nPlayer B is winner\n\n");
			exit(0);
		}
	}
}

void Check_Col(char table[][3])
{
	int count_X = 0;
	int count_O = 0;

	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (table[i][j] == 'X')
			{
				count_X += 1; 
				count_O = 0;
			}
			else if (table[i][j] == 'O')
			{
				count_O += 1;
				count_X = 0; 
			}
			else
			{
				count_X = 0;
				count_O = 0;
				break;
			}
		}

		if (count_X == 3)
		{
			printf("\n\nPlayer A is winner\n\n");
			exit(0);
		}
		else if (count_O == 3)
		{
			printf("\n\nPlayer B is winner\n\n");
			exit(0);
		}
	}
}

void Check_Diagonal(char table[][3])
{
	int count_X = 0;
	int count_O = 0;

	int i, j;
	i = j = 0;

	for (int flag = 0; flag < 3; ++flag)//left to right
	{
		if(table[i][j] == 'X')
		{
			count_X += 1;
			i = i + 1;
			j = j + 1;
		}
		else if (table[i][j] == 'O')
		{
			count_O += 1;
			i = i + 1;
			j = j + 1;
		}
		else
		{
			break;
		}
	}

	i = 2;
	j = 0;
	count_O = count_X = 0;
	
	for (int flag = 0; flag < 3; ++flag) // right to left
	{
		if(table[i][j] == 'X')
		{
			count_X += 1;
			i = i - 1;
			j = j + 1;
		}
		else if (table[i][j] == 'O')
		{
			count_O += 1;
			i = i - 1;
			j = j + 1;
		}
		else
		{
			break;
		}
	}

	if (count_X == 3)
	{
		printf("\n\nPlayer A is winner\n\n");
		exit(0);
	}
	else if (count_O == 3)
	{
		printf("\n\nPlayer B is winner\n\n");
		exit(0);
	}
}

void Check_Draw(char table[][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (table[i][j] == ' ')
			{
				return;
			}
		}
	}

	printf("\n\nGame is draw\n\n");
	exit(0);
}
