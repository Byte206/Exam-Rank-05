#include "life.h"



int init_game(t_game *game, char **argv)
{
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);
	game->alive = '0';
	game->dead = ' ';
	game->i = 0;
	game->j = 0;
	game->draw = 0;
	game->board = (char**)malloc((game->height) * sizeof(char *));
	if (!(game->board))
		return (-1);
	for(int i = 0; i < game->height; i++)
	{
		game->board[i] = (char *)malloc((game->width) * sizeof(char));
		if(!(game->board[i]))
		{
			free_board(game);
			return (-1);
		}
		for (int j = 0; i < game->width; j++)
		{
			game->board[i][j] = ' ';
		}
	}
	return (0);
}

void fill_board(t_game *game)
{
	char buffer;
	int flag;

	while(read(STDIN_FILENO, &buffer, 1) == 1)
	{
		flag = 0;

		if (buffer == 'w')
		{
			if(game->i > 0)
				game->i--;
		}
		else if(buffer == 's')
		{
			if (game->i < game->height - 1)
				game->i++;
		}
		else if(buffer == 'a')
		{
			if(game->j > 0)
				game->j--;
		}
		else if(buffer == 'd')
		{
			if(game->j < game->width - 1)
				game->j++;
		}
		else if(buffer == 'x')
		{
			game->draw = !(game->draw);
		}
		else 
		{
			flag = 1;
		}

		if(game->draw && (flag == 0))
		{
			game->board[game->i][game->j] = '0';
		}
	}			
}

int count_neighbors(t_game *game, int i, int j)
{
	int count = 0;
	for(int delta_i = -1; delta_i < 2; delta_i++)
	{
		for(int delta_j = -1; delta_j < 2;delta_j++)
		{
			//saltarse a uno mismo
			if(delta_i == 0 && delta_j == 0)
				continue;
			int ni = i + delta_i;
			int nj = j + delta_j;
			if((ni >= 0) && (nj >= 0) && (ni < game->height) && (nj < game->width))
			{
				if (game->board[ni][nj] == '0')
					count++;
			}
		}
	}
	return (count);
}

void print_board(t_game *game)
{
	for (int i = 0;i < game->height; i++)
	{
		for (int j = 0;j < game->width; j++)
		{
			putchar(game->board[i][j]);
		}
		putchar('\n');
	}
}

void free_board(t_game *game)
{
	if(game->board)
	{
		for(int i = 0; i < game->height;i++)
		{
			if(game->board[i])
				free(game->board[i]);
		}
		free(game->board);
	}
}

int play(t_game *game)
{
	char **temp = (char**)malloc((game->height) * sizeof(char *));
	if(!temp)
		return (-1);
	for(int i = 0; i < game->height; i++)
	{
		temp[i] = ((char *)malloc((game->width) * sizeof(char)));
		if(!(temp[i]))
			return(-1);
	}

	for(int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			int neighbors = count_neighbors(game, i, j);
			if(game->board[i][j] == '0')
			{
				if(neighbors == 2 || neighbors == 3)
				{
					temp[i][j] = '0';
				}
				else
				{
					temp[i][j] = ' ';
				}
			}
			else
			{
				if(neighbors == 3)
				{
					temp[i][j] = '0';
				}
				else 
				{
					temp[i][j] = ' ';
				}
			}
		}
	}
	free_board(game);
	game->board = temp;
	return(0);
}


int main(int argc, char **argv)
{
	printf("Entro en el main\n");
	if (argc != 4)
		return (1);

	t_game game;
	
	printf("Llamo a init_game\n");
	if(init_game(&game, argv) == -1)
		return(-1);

	printf("llamo a fill_board\n");
	fill_board(&game);

	for(int i = 0; i < game.iterations; i++)
	{
		if(play(&game) == -1)
		{
			free_board(&game);
			return(1);
		}
	}
	print_board(&game);
	free_board(&game);
	return (0);
}
