/***************************************************************************
                          Parse.h  -  description
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

 class Parser
 {

  public:
    Parser();
    ~Parser();

    int getNumArgs(char *ch);
    char *getArgument(char *ch, int x);

    int RemoveExtraSpaces(char *ch);//returns 0 if successful


    //int CheckString


 };


 /*   Constructor    */
 Parser::Parser() {}


 /*   Destructor     */
 Parser::~Parser() {}

 //------------------RemoveExtraSpaces------------------------------
 int Parser::RemoveExtraSpaces(char *ch)
 {
    int count = 0;
    int offset = 0;

   /*  Remove leading spaces  */
   while (ch[count] == ' ')
   {
    count++;
    offset++;
   }

    for (int i = 0; i < (signed)strlen(ch); i++)
    {
      ch[i] = ch[i+offset];
    }


    /*  Remove trailing spaces  */
    count = strlen(ch)-1;

    while (ch[count] == ' ')
    {
      ch[count] = '\0';
      count--;
    }


    /*  Remove double spaces  */
    count = 0;
    offset = 0;

    for (i = 0; i < (signed)strlen(ch); i++)
    {
      if (ch[i] == ' ')
      {
        count = i+1;
        while(ch[count] == ' ')
        {
          offset++;
          count++;
        }
        if (offset != 0)
        {
          for (int j = i+1; j < (signed)strlen(ch); j++)
          {
            ch[j] = ch[j+offset];
          }
        }
      }
      count = 0;
      offset = 0;
    }


   return 0;
 }


 //---------------------getNumArgs-------------------------------------
 int Parser::getNumArgs(char *ch)
 {
  int arg = 1;
  for (int i = 0; i < (signed)strlen(ch); i++)
  {
    if(ch[i] == ' ')
      arg++;
  }

  return (arg);
 }


 //---------------------getArgument------------------------------------
 char* Parser::getArgument(char *ch, int x)
 {
    char *arg_return;
    int size_to = 0;
    int counter = 0;
    int spaces = 0;



    /*   Get First Argument   */

    if (x == 1)
    {
      while ( (ch[counter] != ' ') && (ch[counter] != '\0') )
      {
        counter++;
        size_to++;
      }

	  
      arg_return = new char[size_to];
	  //arg_return = (char*)malloc(size_to);
		
      for (int i = 0; i < size_to; i++)
      {
        arg_return[i] = ch[i];
      }
	arg_return[i] = NULL;
	 //cout << "Debug: " << arg_return << endl;
      return (arg_return);
    }



    /*   Get Last argument   */

   else if (x == (getNumArgs(ch)))
    {
      for (int i = 0; i < (signed)strlen(ch); i++)
      {
        if (ch[i] == ' ')
        {
          spaces++;
          if (spaces == ((getNumArgs(ch)) - 1))
          {
            size_to = i;

          }
        }



      }

      arg_return = new char[strlen(ch) - size_to];

      for (i = size_to+1; i < (signed)strlen(ch); i++)
      {
        arg_return[counter] = ch[i];
        counter++;
      }
		arg_return[counter] = NULL;
		//cout << "Debug: " << arg_return << endl;
      return(arg_return);
    }


    /*   The argument number is not valid    */
    else if ((x > getNumArgs(ch)) || (x < 1))
    {
      return ('\0');
    }

    else
    {

    /*   Get Middle argument    */


    int lower_bound = 0;
    int upper_bound = 0;

    for (int i = 0; i < (signed)strlen(ch); i++)
    {
      if(ch[i] == ' ')
      {
        spaces++;
        if (spaces == (x-1))
        {
          lower_bound = i;
        }
        else if (spaces == x)
        {
          upper_bound = i;
        }
      }
    }

    arg_return = new char[upper_bound - lower_bound];

    for (i = lower_bound+1; i < upper_bound; i++)
    {
      arg_return[counter] = ch[i];
      counter++;
    }
	arg_return[counter] = NULL;
    return(arg_return);

    }
 }

