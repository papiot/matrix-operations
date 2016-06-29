/***************************************************************************
                          Flow.h  -  description
                             -------------------
    begin                : Mon May 20 2002
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

//-----------------------------------------------------------------------
/*    Greeting     */
void greeting()
{

  cout << "\nWelcome to Matrix Operations v0.3w (Windows Version)" << endl;
  cout << " ** Author: Catalin Avram (catalin_avram@hotmail.com)" << endl;
  cout << " ** Get latest version from: http://sourceforge.net/projects/mops/" << endl;
  cout << " ** To see a list of all commands, type 'list ?' anytime at the prompt" << endl;
  cout << " ** To view the syntax of a command, type 'list <command>'" << endl;
  cout << " ** To view this message again at any time, type 'help' at the prompt" << endl;


  return;
}



int flow(void)
 {
  char* ch_inputed;
  char* ch_arg;

  int num_args = 0;
  int check = 0;


  Parser pars;
  matrix mat;
  Save s;
  CReff cr;

  ch_inputed = new char[200];
  ch_arg = new char[20];



do
{
  cout << "\nmops> ";
  cin.getline(ch_inputed, 200);
  
  

  check = pars.RemoveExtraSpaces(ch_inputed);
  if (check != 0)
  {
    cout << "Error in function Parse::RemoveExtraSpaces()" << endl;
  }
	//cout << "DEBUG: " << pars.getArgument(ch_inputed, 1);
      strcpy(ch_arg, pars.getArgument(ch_inputed, 1));




	

   if(strcmp(ch_arg, "input") == 0)
    {
      num_args = pars.getNumArgs(ch_inputed);

      if (num_args < 4)
      {
        cout << "Too few argumetns" << endl;
        cout << "Syntax:  input [matrix name] [rows] [columns]" << endl;

      }
      else if(num_args > 4)
      {
        cout << "Too many arguments" << endl;
        cout << "Syntax:  input [matrix name] [rows] [columns]" << endl;

      }
      else
      {
        float **matrix;
        char *c;

        int row = atoi(pars.getArgument(ch_inputed, 3));
        int col = atoi(pars.getArgument(ch_inputed, 4));
        c = pars.getArgument(ch_inputed, 2);
        matrix = mat.input_matrix(row, col);


        s.saveMem(matrix, c);



        cout << "Matrix saved under tha name: " << c << endl;

      }


    }
	
	//---------------------- greeting message ------------------------------
	else if (strcmp(ch_arg, "help") == 0)
	{
		greeting();
	}


    //---------------adding substrating multiplying augment two matrices ------------------------------

    else if( (strcmp(ch_arg, "add") == 0) || (strcmp(ch_arg, "subst") == 0) || (strcmp(ch_arg, "multiply") == 0) || (strcmp(ch_arg, "augment")) ==0)
    {

       float **matrix1;
      float **matrix2;
      float **matrix3;
      int r, c, r_, c_ = 0;
      int flag = 0;

      if (strcmp(ch_arg, "add") == 0)
      {
        flag = 0;//add
      }
      else if (strcmp(ch_arg, "subst") == 0)
      {
        flag = 1;//substract
      }
      else if (strcmp(ch_arg, "multiply") == 0)
      {
        flag = 2;//multiply
      }
      else if (strcmp(ch_arg, "augment") == 0)
      {
        flag = 3;//augment
      }

      num_args = pars.getNumArgs(ch_inputed);

      if ((num_args == 3) || (num_args == 5))
      {
        char *c1;
        char *c2;
        char *c3;
        char *c4;

        c1 = pars.getArgument(ch_inputed, 2);
        c2 = pars.getArgument(ch_inputed, 3);

        if ((s.recall(c1) != NULL) && (s.recall(c2) != NULL))
        {
          matrix1 = s.recall(c1);
          matrix2 = s.recall(c2);
          r = mat.getRowSize(matrix1);
          c = mat.getColSize(matrix1);
          r_ = mat.getRowSize(matrix2);
          c_ = mat.getColSize(matrix2);

          if (flag == 2)
          {


            if (c != r_)
            {
              cout << "Cannot perform multiplication, size missmatch" << endl;
            }
            else
            {
              matrix3 = mat.multiplied(matrix1, r, c, matrix2, r_, c_);
              mat.output_matrix(matrix3, r, c_);
            }

          }
          else if (flag == 3)
          {
            if (r != r_)
            {
              cout << "Cannot performt augmentation, size missmatch" << endl;
            }
            else
            {
              matrix3 = mat.augment(matrix1, r, c, matrix2, r_, c_);
              mat.output_matrix(matrix3, r, mat.getColSize(matrix3));
            }
          }
          else
          {

            if ( (mat.getColSize(matrix1) != mat.getColSize(matrix2)) || (mat.getRowSize(matrix1) != mat.getRowSize(matrix2)) )
            {
              cout << "Cannot perform addition, size missmatch" << endl;
            }
            else
            {
              matrix3 = mat.add_sub(matrix1, matrix2, r, c, flag);
              mat.output_matrix(matrix3, r, c_);
            }
          }



            if (num_args == 5)
            {
             c3 = pars.getArgument(ch_inputed, 4);
             c4 = pars.getArgument(ch_inputed, 5);

             if (*c3 != '>')
             {
               cout << "Invalid argument " << c3 << endl;
             }
             else if (s.recall(c4) == NULL)
             {
                s.saveMem(matrix3, c4);
                cout << "Result saved to: " << c4 << endl;

             }
             else
             {
              cout << "Matrix " << c4 << " already exists.  Please delete it first." << endl;
             }
            }

        }
        else
        {
          cout << "Invalid matrix names." << endl;
        }

       }

      else
      {
       cout << "Syntax ERROR!" << endl;
       cr.showOne(ch_arg);
      }
    }



    //----------------------generate----------------------------------------
    else if(strcmp(ch_arg, "generate") == 0)
    {

      num_args = pars.getNumArgs(ch_inputed);

      if (num_args != 6)
      {
        cout << "Syntax ERROR!" << endl;
        cr.showOne(ch_arg);
      }
      else
      {
        char *ca;
        float **matrix;
        int r = atoi(pars.getArgument(ch_inputed, 3));
        int c = atoi(pars.getArgument(ch_inputed, 4));
        int min = atoi(pars.getArgument(ch_inputed, 5));
        int max = atoi(pars.getArgument(ch_inputed, 6));

        ca = pars.getArgument(ch_inputed, 2);

        if (s.recall(ca) != NULL)
        {
          cout << "Matrix " << c << " already exists." << endl;
        }
        else
        {

           matrix = mat.random(r, c, min, max);

           mat.output_matrix(matrix, r, c);


           s.saveMem(matrix, ca);
        }



      }

    }


    //-----------------DETERMINANT---------------------------------------------

    else if(strcmp(ch_arg, "det") == 0)
    {
      num_args = pars.getNumArgs(ch_inputed);

      if (num_args != 2)
      {
        cout << "Syntax ERROR!" << endl;
        cr.showOne(ch_arg);
      }
      else
      {
        char* c;
        float **matrix;

        c = pars.getArgument(ch_inputed, 2);

        if (s.recall(c) == NULL)
        {
          cout << "Matrix " << c << " does not exist!" << endl;
        }
        else
        {
          matrix = s.recall(c);

          if (mat.getColSize(matrix) != mat.getRowSize(matrix))
          {
            cout << "Not a square matrix" << endl;
          }
          else
          {
            int size = mat.getColSize(matrix);
            float d = mat.det(matrix, size);
            cout << "Determinant: " << d << endl;
          }


        }
      }

      //cout << "Calculating the determinant" << endl;
    }





    else if( (strcmp(ch_arg, "adjoint") == 0) || (strcmp(ch_arg, "conjugate") == 0) || (strcmp(ch_arg, "transpose") == 0) ||
            (strcmp(ch_arg, "inverse") == 0))
    {

     num_args = pars.getNumArgs(ch_inputed);

     if ((num_args != 2) && (num_args != 4))
     {
        cout << "Syntax ERROR!" << endl;
        cr.showOne(ch_arg);
     }
     else
     {
        float** matrix1;
        char* c = pars.getArgument(ch_inputed, 2);
        float** matrix = s.recall(c);

        if (strcmp(ch_arg, "adjoint") == 0)
        {
            if (mat.getColSize(matrix) != mat.getRowSize(matrix))
            {
              cout << "Size missmatch" << endl;
            }
            else
            {
              matrix1 = mat.adjoint(matrix, mat.getColSize(matrix));
            }

        }

        else if (strcmp(ch_arg, "conjugate") == 0)
        {
            if (mat.getColSize(matrix) != mat.getRowSize(matrix))
            {
              cout << "Size missmatch" << endl;
            }
            else
            {
              //matrix1 = mat.co
              //cout << "conjugate" << endl;
              matrix1 = mat.conjugate(matrix, mat.getColSize(matrix));
            }
        }

        else if (strcmp(ch_arg, "transpose") == 0)
        {

          matrix1 = mat.transposed(matrix, mat.getRowSize(matrix), mat.getColSize(matrix));
//                  cout << "got here" << endl;
        }


        else if (strcmp(ch_arg, "inverse") == 0)
        {
          if (mat.getColSize(matrix) != mat.getRowSize(matrix))
          {
            cout << "Size missmatch" << endl;
          }
          else
          {
            matrix1 = mat.inverse(matrix, mat.getRowSize(matrix));
          }
        }


	/* else if (strcmp(ch_arg, "ref") == 0)
        {
          cout << "ref" << endl;
	  cout << "Function not implemented yet." << endl;
	  
        }

        else if (strcmp(ch_arg, "rref") == 0)
        {
          cout << "rref" << endl;
	  cout << "Function not implemented yet." << endl;
	  
	  }*/

        mat.output_matrix(matrix1, mat.getRowSize(matrix1), mat.getColSize(matrix1));

        if (num_args == 4)
        {
          if (strcmp(pars.getArgument(ch_inputed, 3), ">") != 0)
          {
            cout << "Syntax ERROR" << endl;
            cr.showOne(ch_arg);
          }
          else
          {
            char* ch = pars.getArgument(ch_inputed, 4);
            {
              if (s.recall(ch) != NULL)
              {
                cout << "Matrix " << ch << " already exists" << endl;
              }
              else
              {
                s.saveMem(matrix1, ch);
                cout << "Matrix saved under the name: " << ch << endl;
              }
            }
          }
        }

     }

     // cout << "Adjoint of a matrix" << endl;
    }


   //------------------------SHOW----------------------------------------------
    else if(strcmp(ch_arg, "show") == 0)
    {
      num_args = pars.getNumArgs(ch_inputed);

      if(num_args != 2)
      {
        cout << "Invalide number of arguments" << endl;
        cout << "Syntax:  show mem  or  show [matrix name]" << endl;
      }
      else
      {
        char* arg = pars.getArgument(ch_inputed, 2);
        float **matrix;

        if (strcmp(arg, "mem") != 0)
        {

         if (s.recall(arg) != NULL)
         {
           matrix = s.recall(arg);

            int r = mat.getRowSize(matrix);
            int c = mat.getColSize(matrix);

            mat.output_matrix(matrix, r, c);
         }
         else
         {
          cout << "Matrix " << arg << " not found." << endl;
         }
        }
        else
        {
          //mem information
          cout << "Information about memory not available in this version." << endl;


        }
      }


    }
    else if(strcmp(ch_arg, "del") == 0)
    {
      char* c = new char[20];
      int n = pars.getNumArgs(ch_inputed);
      c = pars.getArgument(ch_inputed, 2);
      if (n != 1)
      {	
      if (strcmp(c, "all") == 0)
      {
        int i = s.del_all();
        if (i != 0)
        {
          cout << "Error occured in function del_all()" << endl;
        }
        else
        {
          cout << "Memory cleared" << endl;
        }
      }
      else
      {

        int i = s.del_1(c);

        if (i != 0)
        {
          cout << "Error occured in function del_1()" << endl;
        }
        else
        {
          cout << "Matrix " << c << " deleted." << endl;
        }
      }
      }
      else
      {
	cr.showOne("del");
      }
        
      

      //cout << "Deleting memory information" << endl;
    }


    else if(strcmp(ch_arg, "list") == 0)
    {


      char* c =  new char[20];


      num_args = pars.getNumArgs(ch_inputed);
      cout << "COMMAND REFERENCE\n" << endl;
     if (num_args == 1)
     {
      cr.showAll();
     }
     else
     {
      strcpy(c, pars.getArgument(ch_inputed, 2));

      cr.showOne(c);

      }
    }


    else if(strcmp(ch_arg, "quit") == 0)
    {
      cout << "Exiting program..." << endl;
    }

   /*else if(strcmp(ch_arg, (char *)EOF) == 0)
   {
     delete[] ch_inputed;
     delete[] ch_arg;
     break;
     }*/
    else// if (flag == 0)
    {
      cout << "\nInvalid command: " << ch_arg << endl;
    }



  }
  while (strcmp(ch_arg, "quit") != 0);
//  while ((strcmp(ch_arg, "quit") != 0) && (strcmp(ch_arg, (char *)EOF) != 0));
// while (strcmp(ch_arg, (char *)EOF) != 0) ;


  delete[] ch_inputed;
  delete[] ch_arg;
  return 0;
 }



