/* MAZE.cpp

int path_exists_wrapper(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int up, down, left, right, middle, boundary, found = 0;

	middle = x1*columns + y1;
	up = (x1 - 1)*columns + y1;
	down = (x1 + 1)*columns + y1;
	left = x1*columns + (y1 - 1);
	right = x1*columns + (y1 + 1);

	maze[middle] = -1;

	if (x1 == x2 && y1 == y2)
		return 1;

	// Moving Up
	if ((x1 - 1) >= 0)
	{
		if (maze[up] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1 - 1, y1, x2, y2);
		if (found != 0)
			return 1;
	}

	// Moving Down
	if ((x1 + 1) < rows)
	{
		if (maze[down] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1 + 1, y1, x2, y2);
		if (found != 0)
			return 1;
	}

	// Moving Left
	if ((y1 - 1) >= 0)
	{
		if (maze[left] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1, y1 - 1, x2, y2);
		if (found != 0)
			return 1;
	}

	// Moving Right
	if ((y1 + 1) < columns)
	{
		if (maze[right] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1, y1 + 1, x2, y2);
		if (found != 0)
			return 1;
	}

	return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int i, k;
	if (rows <= 0 || columns <= 0)
		return 0;
	if (x1 < 0 || x1 > rows)
		return 0;
	if (y1 < 0 || y2 > columns)
		return 0;
	k = path_exists_wrapper(maze, rows, columns, x1, y1, x2, y2);
	
	for (i = 0; i < rows*columns; i++)
		if (maze[i] == -1)
			maze[i] = 1;

	return k
	}
	*/


/*
N SNIPPERS
int is_crct_place(int *battlefield, int row, int column, int order)
{
	int i, j;

	// column check
	for (i = 0; i < order; i++)
	{
		if (*((battlefield + i*order) + column))
			return 0;			
	}

	// diagonal check (y = x)
	for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
	{
		if (*((battlefield + i*order) + j))
			return 0;
	}

	//diagonal check (y = -x)
	for (i = row, j = column; i < order && j >= 0; i++, j--)
	{
		if (*((battlefield + i*order) + j))
			return 0;
	}
	
	return 1;
}


// wrapper function
int nsnipers_placements(int *battlefield, int row, int order)
{
	int i;

	if (row >= order)
		return 1;

	for (i = 0; i < order; i++)
	{
		if (is_crct_place(battlefield, row, i, order))
		{
			*((battlefield + row*order) + i) = 1;

			if (nsnipers_placements(battlefield, row + 1, order))
				return 1;

			*((battlefield + row*order) + i) = 0;
		}
	}
	return 0;
}

int solve_nsnipers(int *battlefield, int n)
{
	if (battlefield == NULL || n <= 3)
		return 0;
	return nsnipers_placements(battlefield, 0, n);
}*/

/*
int *spiral_wrapper(int rows, int columns, int **input_array, int rounds, int *ans, int index)
{
	int i;

	for (i = rounds; i < columns - 1 - rounds; i++, index++)
		ans[index] = input_array[rounds][i];
	if (index >= rows*columns)
		return ans;

	for (i = rounds; i < rows - 1  - rounds; i++, index++)
		ans[index] = input_array[i][columns - 1 - rounds];
	if (index >= rows*columns)
		return ans;

	for (i = columns - 1 - rounds; i >= 1 + rounds; i--, index++)
		ans[index] = input_array[rows - 1 - rounds][i];
	if (index >= rows*columns)
		return ans;

	for (i = rows - 1 - rounds; i >= 1 + rounds; i--, index++)
		ans[index] = input_array[i][rounds];
	if (index >= rows*columns)
		return ans;

	rounds++;
	if (index == rows*columns - 1 && rows % 2 == 1 && columns % 2 == 1)
	{
		if (columns - rounds - 1 >= 0)
			ans[index] = input_array[rounds][columns - rounds - 1];
		index++;
		return ans;
	}

	return spiral_wrapper(rows, columns, input_array, rounds, ans, index);
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;

	int *ans = (int*)calloc(rows*columns, sizeof(int));
	if (rows == 1 && columns == 1)
	{
		ans[0] = input_array[0][0];
		return ans;
	}
	return spiral_wrapper(rows, columns, input_array, 0, ans, 0);
}*/


/* STEPS.CPP

int factorial(int N)
{
	if (N == 1 || N == 0)
		return 1;
	else
		return N * factorial(N - 1);
}

int num_of_permutations(int ones, int twos)
{
	return factorial(ones + twos) / (factorial(ones)*factorial(twos));
}

int get_steps_recur(int ones, int twos)
{
	if (ones == 1)
		return ones + twos;
	if (ones == 0)
		return 1;
	return num_of_permutations(ones, twos) + get_steps_recur(ones - 2, twos + 1);
}

int get_steps(int s)
{
	return get_steps_recur(s, 0);
}*/

