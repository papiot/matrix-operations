/***************************************************************************
                          CReff.h  -  description
                             -------------------
    begin                : Sun Jun 16 2002
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
  class CReff
  {
    public:
      CReff();
      ~CReff();

    void showOne(char* ch);
    void showAll();

    private:
      char input[500];
      char add[500];
      char subst[500];
      char multiply[500];
      char generate[500];
      char det[500];
      char augment[500];
      char adjoint[500];
      char conjugate[500];
      char transpose[500];
      char inverse[500];
      char ref[500];
      char rref[500];
      char show[500];
      char del[500];
      char commands[500];




  };


  /*       Constructor       */
  CReff::CReff()
  {
    //strcpy(input, "This is a\nFucking\nTest\n\n");

    strcpy(input, "Syntax:\ninput [matrix name] [rows] [colums]\nIt inputs a matrix of rowsxcolums dimentions\n");

    strcpy(add, "Syntax:\nadd [left matrix] [right matrix]\nadd [left matrix] [right matrix] > [resulting matrix]\nThis command adds the left matrix to the right matrix and stores the result, optionally into the resulting matrix\n");


    strcpy(subst, "Syntax:\nsubst [left matrix] [right matrix]\nsubst [left matrix] [right matrix] > [resulting matrix]\nThis command substracts the right matrix from the left matrix and stores the result, optionally into the resulting matrix\n");


    strcpy(multiply, "Syntax:\nmultiply [left matrix] [right matrix]\nmultiply [left matrix] [right matrix] > [resulting matrix]\nThis command multiplies two matrices.  If there's a size missmatch an error is printed.  Using the > argument, the user can save the resulting matrix under a variable name\n");
    strcpy(generate, "Syntax:\ngenerate [matrix name] [rows] [columns] [min] [max]\nThis command generates a random rowsXcolums sized matrix, with random elements between min and max.\n");
    strcpy(det, "Syntax:\ndet [matrix name]\nThis command caluclate the determinant of a matrix.  If sizes are incorect (rows != cols) an error message is displayed.\n");
    strcpy(augment, "Syntax:\naugment [left matrix] [right matrix]\naugment [left matrix] [right matrix] > [resulting matrix]\nAugmenting the right matrix to the left matrix and optionally storing it into [resulting matrix].\n");
    strcpy(adjoint, "Syntax:\nadjoint [matrix name]\nadjoint [matrix name] > [resulting matrix]\nAdjoint of matrix [matrix name].\n");
    strcpy(conjugate, "Syntax:\nconjugate [matrix name]\nconjugate [matrix name] > [resulting matrix]\nConjugate of matrix [matrix name].\n");
    strcpy(transpose, "Syntax:\ntranspose [matrix name]\ntranspose [matrix name] > [resulting matrix]\nTranspose of matrix [matrix name].\n");
    strcpy(inverse, "Syntax:\ninverse [matrix name]\ninverse [matrix name] > [resulting matrix]\nInverse of matrix [matrix name].\n");
    // strcpy(ref, "Syntax:\nref [matrix name]\nref [matrix name] > [resutling matrix]\nBrings the matrix int the row-echelon form\n");
    // strcpy(rref, "Syntax:\nrref [matrix name]\nrref [matrix name] > [resutling matrix]\nBrings the matrix int the reduced-row-echelon form\n");
    strcpy(show, "Syntax:\nshow mem\nshow [matrix name]\nThis command displays a matrix, or information about the memory load\n");
    strcpy(del, "Syntax:\ndel all\ndel [matrix name]\nDeletes a specific or all matrices from the memory.\n");
    strcpy(commands, "input add subst multiply generate det augment adjoint conjugate transpose inverse ref rref show del\n");

  }


  /*       Destructor        */
  CReff::~CReff()
  {
   delete [] input;
   delete[] add;
   delete[] subst;
   delete[] multiply;
   delete[] generate;
   delete[] det;
   delete[] augment;
   delete[] adjoint;
   delete[] conjugate;
   delete[] transpose;
   delete[] inverse;
   delete[] ref;
   delete[] rref;
   delete[] show;
   delete[] del;
   delete[] commands;
  }


  //--------------------------showOne------------------------------------------

  void CReff::showOne(char* ch)
  {
    if (strcmp(ch, "input") == 0)
    {
      cout << input << endl;
    }
    else if (strcmp(ch, "add") == 0)
    {
      cout << add << endl;
    }
    else if (strcmp(ch, "subst") == 0)
    {
      cout << subst << endl;
    }
    else if (strcmp(ch, "multiply") == 0)
    {
      cout << multiply << endl;
    }
    else if (strcmp(ch, "generate") == 0)
    {
      cout << generate << endl;
    }
    else if (strcmp(ch, "det") == 0)
    {
      cout << det << endl;
    }
    else if (strcmp(ch, "augment") == 0)
    {
      cout << augment << endl;
    }
    else if (strcmp(ch, "adjoint") == 0)
    {
      cout << adjoint << endl;
    }
    else if (strcmp(ch, "conjugate") == 0)
    {
      cout << conjugate << endl;
    }
    else if (strcmp(ch, "transpose") == 0)
    {
      cout << transpose << endl;
    }
    else if (strcmp(ch, "inverse") == 0)
    {
      cout << inverse << endl;
    }
    /*else if (strcmp(ch, "ref") == 0)
    {
      cout << ref << endl;
    }
    else if (strcmp(ch, "rref") == 0)
    {
      cout << rref << endl;
    }*/
    else if (strcmp(ch, "show") == 0)
    {
      cout << show << endl;
    }
    else if (strcmp(ch, "del") == 0)
    {
      cout << del << endl;
    }
    else if (strcmp(ch, "?") == 0)
    {
      cout << commands << endl;
    }
    else
    {
      cout << "Command " << ch << " does not exist!" << endl;
    }
    return;
  }



  //----------------------show all----------------------------

void  CReff::showAll()
{
  cout << input << endl;
  cout << add << endl;
  cout << subst << endl;
  cout << multiply << endl;
  cout << generate << endl;
  cout << det << endl;
  cout << augment << endl;
  cout << conjugate << endl;
  cout << transpose << endl;
  cout << inverse << endl;
  //cout << ref << endl;
  //cout << rref << endl;
  cout << show << endl;
  cout << del << endl;
}
