/***************************************************************************
                                   Matrix.h

    This is where all the matrix operations functions are located.

                             -------------------
    begin                : Fri Apr 12 2002
    copyright            : (C) 2002 by Catalin Avram
    email                : catalin_avram@hotmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


/***************************************************************************/
/* This is the flag that signals the end of a row and/or column
   of a matrix.  The value chosen might be an actual value
   in the matrix, so it is ambigous to use a random number. It needs
   to be set to something else, that will never under any circumstances
   appear inside of a matrix. */

#define FIN 1.101010101f    // <-- FIX ME!!!!
/***************************************************************************/
 class matrix
 {

   public:

    matrix();
      ~matrix();

    void output_matrix(float **matrix, int r, int c);
    float det(float **matrix, int size); //nxn determinant

    float **random(int r, int c, int min, int max);
    float **input_matrix(int r, int c);
    float  **multiplied(float **left_matrix, int left_row_size, int left_col_size, float **right_matrix,
                            int right_row_size, int right_col_size);
    float **add_sub(float **left_matrix, float **right_matrix, int r, int c, int flag);
    float **transposed(float **init_matrix, int row_size, int col_size);
    float **adjoint(float **matrix, int size);
    float **conjugate(float **matrix, int size);
    float **inverse(float **matrix, int size);

    int getRowSize(float **matrix);
    int getColSize(float **matrix);

    float **augment(float **left_matrix, int l_row, int l_col,
                    float **right_matrix, int r_row, int r_col);


   private:

    float **create_matrix(int r, int c);
    float **submatrix(float **matrix, int size, int i, int j);

    float det2(float **matrix);
    float det3(float **matrix);



 };

/*
  Constructor of matrix class
*/
 matrix::matrix() {};



/*
  Destructor of matrix class
*/
 matrix::~matrix() {};


 //-----------------create_matrix---------------------------------

 float **matrix::create_matrix(int r, int c)
 {
    float **matrix;

    matrix = new float *[r+1];

    for (int i = 0; i < r+1; i++)
    {
      matrix[i] = new float [c+1];
    }
    matrix[0][c] = FIN;
    matrix[r][0] = FIN;
    return(matrix);
 }


 //-----------------------output_matrix-----------------------------

 void matrix::output_matrix(float **matrix, int r, int c)
 {

   //cout << "row size: " << r << endl;
   //cout << "col size: " << c << endl;
    for (int i = 0; i < r; i++)
    {

      for (int j = 0; j < c; j++)
      {
        cout << matrix[i][j] << '\t';
      }

      cout << '\n';

    }
  return;
 }


 //------------------------det2------------------------------------

 float matrix::det2(float **matrix)
 {
  float det = 0;

  det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
  return(det);
 }


 //------------------------det3------------------------------------

 float matrix::det3(float **matrix)
 {
    float det = 0;

    det = (matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))) -
          (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))) +
          (matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])));

    return(det);
 }


 //-----------------------det--------------------------------------

 float matrix::det(float **matrix, int size)
 {
    float d = 0;

    int flag = 0;

    if (size <= 3)
    {

      switch (size)
      {
        case 1:
        {
          d = matrix[0][0];
          return(d);
          break;
        }

        case 2:
        {
          d = det2(matrix);
          return(d);
          break;
        }

        case 3:
        {
          d = det3(matrix);
          return(d);
          break;
        }
      }

    }
    else
    {
		float **sub_matrix;

       for (int c = 0; c < size; c++)
       {
			  sub_matrix = submatrix(matrix, size, 0, c);

			  if (flag == 0)
			  {
				  d += (matrix[0][c]) * det(sub_matrix, size-1);
				  flag = 1;
			  }
			  else
			  {
				  d -= (matrix[0][c]) * det(sub_matrix, size-1);
				  flag = 0;
			  }


		   }

	   }

   return(d);

 }

  //---------------------------submatrix-----------------------------

 float **matrix::submatrix(float **matrix, int size, int i, int j)
 {
    float **subm;
    int yy = 0;
    int xx = 0;
    int y1 = 0;
    int x1 = 0;
    subm = create_matrix(size-1, size-1);

    for (int x = 0; x < size; x++)
    {
      if (x != i)
      {
        for (int y = 0; y < size; y++)
        {
          if (y != j)
          {
            subm[xx][yy] = matrix[x1][y1];
            yy++;
            y1++;
          }
          else
          {
            y1++;
          }
        }
        yy=0;
        y1=0;
        xx++;
        x1++;

      }
      else
      {
        x1++;
      }

    }

    return(subm);
 }




 //-----------------------random------------------------

 float **matrix::random(int r, int c, int min, int max)
 {
  float **mat;
  srand((unsigned int)time((time_t *)NULL)); //randomize
  mat = create_matrix(r, c);

  for (int i = 0; i < r; i ++)
  {
    for (int j = 0; j < c; j++)
    {
      mat[i][j] = (float)(rand() % (max - min) + min);  // rand() % (max - min) + min
    }
  }

  return(mat);
 }


 //------------------------input_matrix---------------------------------------

 float **matrix::input_matrix(int r, int c)
 {
  float **matrix;

  cout << "\nEnter value for: " << endl;
  matrix = create_matrix(r, c);

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << "(" << i+1 << ", " << j+1 << "): ";
      cin >> matrix[i][j];
    }

  }

  return(matrix);
 }


 //------------------------------multiplied------------------------------------


float  **matrix::multiplied(float **left_matrix, int left_row_size, int left_col_size, float **right_matrix,
                 int right_row_size, int right_col_size)

{

  float **result_matrix;
  if (left_col_size != right_row_size)
  {
    cout << "Cannot multiply matrices." << endl;
    return NULL;
  }

  result_matrix = create_matrix(left_row_size, right_col_size);

  for(int h = 0; h < left_row_size; h++)
  {
         for(int j = 0; j < right_col_size; j++)
         {

                for(int i = 0; i < left_col_size; i++)
                {

                        result_matrix[h][j] = result_matrix[h][j] + left_matrix[h][i]*right_matrix[i][j];
                }

        }
  }

  return(result_matrix);
}



//------------------------------add/substract------------------------------------
float **matrix::add_sub(float **left_matrix, float **right_matrix, int r, int c, int flag)
{
  float **result_matrix;

  result_matrix = create_matrix(r, c);

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {

      if (flag == 0)
      {
        result_matrix[i][j] = left_matrix[i][j] + right_matrix[i][j];
      }
      else if (flag == 1)
      {
        result_matrix[i][j] = left_matrix[i][j] - right_matrix[i][j];
      }
    }
  }

  return(result_matrix);
}



//-----------------------TRANSPOSE----------------------------------------------

float **matrix::transposed(float **init_matrix, int row_size, int col_size)
{

  float **trans_matrix;

  trans_matrix = create_matrix(col_size, row_size);


  for (int j = 0; j < col_size; j++)
  {
        for (int h = 0; h < row_size; h++)
        {
                trans_matrix[j][h] = init_matrix[h][j];
        }
  }

return(trans_matrix);
}


//-----------------------conjugate------------------------------------------------
float **matrix::conjugate(float **matrix, int size)
{
  float **conjugate;
  //float ** adj_matrix;

  int flag = 0;

  conjugate = create_matrix(size, size);
//  adj_matrix = create_matrix(size, size);

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (flag == 0)
      {
        conjugate[i][j] = det(submatrix(matrix, size, i, j), size-1);
        flag = 1;
      }
      else
      {
        conjugate[i][j] = (det(submatrix(matrix, size, i, j), size-1) * (-1));
        flag = 0;
      }
    }
  }

  //adj_matrix = transposed(conjugate, size, size);

  return(conjugate);
}



//--------------------------Inverse---------------------------------------
float **matrix::inverse(float **matrix, int size)
{
  float d = 0;
  float **inv;
  float **adj;
  d = det(matrix, size);

  if (d == 0)
  {
    cout << "Determinant of the matrix = 0, => the matrix is not invertable!" << endl;
    return NULL;
  }
  else
  {


    inv = create_matrix(size, size);
    adj = create_matrix(size, size);

    adj = adjoint(matrix, size);

    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        inv[i][j] = (1/d) * (adj[i][j]);
      }
    }


  }

  return(inv);
}


//------------------------------augment------------------------------------------------

float **matrix::augment(float **left_matrix, int l_row, int l_col, float **right_matrix, int r_row, int r_col)
{

  float **matrix;

  if (l_row != r_row)
  {
    cout << "Error!  Different row size!" << endl;
    return NULL;
  }
  else
  {
    matrix = create_matrix(l_row, l_col + r_col);

    for (int i = 0; i < l_row; i++)
    {
      for (int j = 0; j < (l_col + r_col); j++)
      {
        if (j < l_col)
        {
          matrix[i][j] = left_matrix[i][j];
        }
        else
        {
          matrix[i][j] = right_matrix[i][j - l_col];
        }
      }
    }
    return (matrix);
  }

 return NULL;
}



//----------------------------------------getRowSize-----------------------------------

int matrix::getRowSize(float **matrix)
{
  int r = 0;
  //  cout << EOF << endl;
  //cout << "TESTING: " << matrix[10][10] << endl;
  while (matrix[r][0] != FIN)
  {
    r++;
  }
  //r = sizeof(**matrix);
  //cout << "row in getRowSize: " << r  << endl;
  return (r);
}

//----------------------------------------getColSize-----------------------------------

int matrix::getColSize(float **matrix)
{
  int c = 0;

  while (matrix[0][c] != FIN)
  {
    c++;
  }

  return(c);
}

//-------------------------------------adjoint----------------------------------------
float** matrix::adjoint(float** matrix, int size)
{
  float** conj;
  float** adj;

  conj = create_matrix(size, size);
  adj = create_matrix(size, size);
  conj = conjugate(matrix, size);
  adj = transposed(conj, size, size);

  return(adj);

}




