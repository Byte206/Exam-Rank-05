#include "life.h"

void  free_board(t_game *game)
{
  if (game->board)
  {
    for(int i = 0; i < game->height; i++)
    {
      if(game->board[i])
        free(game->board[i]);
    }
    free(game->board);
  }
}

void print_board(t_game *game)
{
  for(int i = 0;i < game->height; i++)
  {
    for(int j = 0;j < game->width; j++)
      putchar(game->board[i][j]);
    putchar('\n');
  }
}

int init_board(t_game *game, char **argv)
{
  game->width = atoi(argv[1]);
  game->height = atoi(argv[2]);
  game->iterations = atoi(argv[3]);
  game->i = 0;
  game->j = 0;
  game->draw = 0;
  game->alive = 'O';
  game->dead = ' ';
  game->board = malloc(game->height * sizeof(char *));
  if(!game->board)
    return(1);
  for(int i = 0; i < game->height; i++)
  {
    game->board[i] = malloc(game->width * sizeof(char));
    if(!game->board[i])
    {
      free_board(game);
      return(1);
    }
    for(int j = 0; j < game->width; j++)
    {
      game->board[i][j] = ' ';
    }
  }
  return(0);
}


void fill_board(t_game *game)
{
  char buffer;
  int flag;

  while(read(STDIN_FILENO, &buffer, 1) == 1)
  {
    flag = 0;
    if(buffer == 'w')
    {
      if(game->i > 0)
        game->i--;
    }
    else if(buffer == 's')
    {
      if(game->i < game->height - 1)
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
      game->draw = !game->draw;
    }
    else {
      flag = 1;
    }

    if(flag == 0 && game->draw)
      game->board[game->i][game->j] = 'O';
  }
}

int count_neighbors(t_game *game, int i, int j)
{
  int count = 0;
  for(int delta_i = -1; delta_i < 2; delta_i++)
  {
    for(int delta_j = -1; delta_j < 2; delta_j++)
    {
      if(delta_i == 0 && delta_j == 0)
        continue;
      int n1 = i + delta_i;
      int nj = j + delta_j;
      if((n1 >= 0 && nj >= 0) && (n1 < game->height && nj < game->width))
        if(game->board[n1][nj] == game->alive)
          count++;
    }
  }
  return (count);
}


int play(t_game *game)
{
  char  **temp = (char **)malloc(game->height * sizeof(char *));
  if (!temp)
    return(1);
  for(int i = 0;i < game->height; i++)
  {
    temp[i] = malloc(game->width * sizeof(char));
    if (!temp[i])
      return(1);
  }

  for(int i = 0; i < game->height; i++)
  {
    for(int j = 0; j < game->width; j++)
    {
      //Verificamos casilla por casilla contando vecinos
      int neighbors = count_neighbors(game,i, j);
      if(game->board[i][j] == game->alive)
      {
        if (neighbors == 2 || neighbors == 3)
          temp[i][j] = game->alive;
        else 
          temp[i][j] = game->dead;
      }
      else {
        if(neighbors == 3)
          temp[i][j] = game->alive;
        else 
          temp[i][j] = game->dead;
      }
    }
  }
  //Si una celula tiene 2 o 3 vecinos sobrevive,si tiene mas o menos muere
  //Si una casilla muerta tiene 3 vecinos nace celula nueva
  free_board(game);
  game->board = temp;
  return(0);
}

int main(int argc, char **argv)
{
  if (argc != 4)
    return(1);

  t_game game;

  //Iniciamos struct y llenamos board con ' '
  if(init_board(&game, argv))
    return(1);
  
  //Leemos del STDIN byte por byte y rellenamos tablero con celulas vivas
  fill_board(&game);


  //Bucle de iteraciones del juego
  for(int i = 0; i < game.iterations; i++)
  {
    if(play(&game))
    {
      free_board(&game);
      return(1);
    }
  }
  print_board(&game);
  free_board(&game);

  return(0);
}
