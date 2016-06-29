/***************************************************************************
                          SaveMem.h  -  description
                             -------------------
    begin                : Sun May 19 2002
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


 class Save
 {

  public:
    Save();
     ~Save();

    int saveMem (float **m, char *c);  //returns 0 for success

    int exists(char* c);      //0 -yes, 1 - no

    int del_1 (char* c);     //0 for success
    int del_all();                         //0 for success

    float **recall (char *c);

  private:
   float **Matrix[100];
   char* ch[100];

 };


 /*   Class Constructor   */
 Save::Save()
 {
  for (int i = 0; i < 100; i++)
    Matrix[i] = NULL;

  for (i = 0; i < 100; i++)
    //strcpy(&*ch[i], '\0');// = '\0';
    ch[i] = NULL;


 }

 /*   Class Destructor    */
 Save::~Save()
 {
   /*delete[] matrix;
     delete[] ch;*/
 }


 //--------------------saveMem----------------------------------------
 int Save::saveMem(float **m, char *c)
 {

  for (int i = 0; i < 100; i++)
  {
    if (Matrix[i] == NULL)
    {
      Matrix[i] = m;
      ch [i] = c;
      return 0; //success
    }
  }
  return 1;
 }


 //--------------------recall-----------------------------------------
 float **Save::recall(char *c)
 {
  for (int i = 0; i < 100; i++)
  {
    //cout << i << endl;
    //if (strcmp(ch[i], '\0') == 0)
    //{
     // return NULL;
    //}
    if (ch[i] && strcmp(ch[i], c) == 0)
    {
     
      return(Matrix[i]);
    }
  }
  return NULL; //matrix not found
 }


 //---------------------del_1-----------------------------------------
 int Save::del_1 (char* c)
 {

  for (int i = 0; i < 100; i++)
  {
    if (ch[i] && strcmp(ch[i], c) == 0)
    {
      Matrix[i] = NULL;
      ch[i] = '\0';

      return  0; //success
    }
  }

  return 1;
 }

 //----------------------del_all--------------------------------------
 int Save::del_all()
 {
  for (int i = 0; i < 100; i++)
  {
    Matrix[i] = NULL;
    ch[i] = '\0';
  }
  return 0;
 }


 //------------------------exists-------------------------------------
 int Save::exists(char* c)
 {
  for (int i = 0; i < 100; i++)
  {
    if (ch[i] && strcmp(ch[i], c) == 0)
      return 0; //yes
  }
  return 1; //no
 }



