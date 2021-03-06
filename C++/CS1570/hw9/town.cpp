//Programmer: DAVID GARDINER          Date: 11/14/16
//File: town.cpp                      Class: CS1570 A
//Purpose: Implementation of the town class.

#include "town.h"
using namespace std;

town::town(const short size)
{
  setSize(size);
  clear();
  build();
}

void town::clear()
{
  for(short i=0; i<actual_size; i++)
    for(short j=0; j<actual_size; j++)
      grid[i][j] = ' ';
}

void town::build()
{
  for(short i=0; i<actual_size; i++)
    for(short j=0; j<actual_size; j++)
    {
      if(!i || i==actual_size-1 || !j || j==actual_size-1)
      {
        if(i==(actual_size-1)/2 || j==(actual_size-1)/2)
          grid[i][j] = 'E';
        else
          grid[i][j] = 'W';
      }
    }
}

short town::getSize() const
{
  return actual_size;
} 

void town::setSize(const short size)
{
  if(size >= MIN_TOWN_SIZE && size <= MAX_TOWN_SIZE)
    actual_size = size;
  else
  {
    cout << "\nInvalid town size!" << endl;
    exit(1);
  }
  return;
}

char town::getPoint(const short row, const short col) const
{
  return grid[row][col];
}

void town::setPoint(const short x, const short y, const char c)
{
  grid[x][y]=c;
  return;
}

ostream& operator<<(ostream & o, const town & t)
{
  cout << " ";
  for(int j=0; j<t.getSize()*6-3; j++)
      cout << "-";
  cout << endl;
  for(short i=0; i<t.getSize(); i++)
  {  
    if(i)
    {
      cout << "|";
      for(int j=0; j<t.getSize(); j++)
        if(!j || j==t.getSize()-1)
        {
          if(i && j==t.getSize()-1)
          {
            if(j==t.getSize()-1)
            {
              if(i==t.getSize()-1)
                cout << "-";
              else
                cout << " ";
              cout << "|";
            }
            else
              cout << "  ";
          }
          cout << "---|";
        }
        else
        {
          if(i==t.getSize()-1)
            cout << "------";
          else
            cout << "  --- ";
        }
      cout << endl;
    }
      
    for(short j=0; j<t.getSize(); j++)
      cout << "| " << t.getPoint(i, j) << " | ";
    cout << endl;
    if(i!=t.getSize()-1)
    {
      cout << "|";
      for(short k=0; k<t.getSize(); k++)
      {
        if(!k || k==t.getSize()-1)
        {
          if(i && k==t.getSize()-1)
            if(k==t.getSize()-1)
            {
              if(i==t.getSize()-1)
                cout << "-";
              else
                cout << " ";
              cout << "|";
            }
            else
              cout << "  ";
          cout << "---|";
          if(!i && k!=t.getSize()-1)
            cout << "--";
        }
        else
        {
          if(!i)
          {
            cout << "-----";
            if(k==t.getSize()-2)
              cout << "|";
            else
              cout << "-";
          }
          else
            cout << "  --- ";
        }
      }
      cout << endl;
    }
  } 
  cout << " ";
  for(int j=0; j<t.getSize()*6-3; j++)
    cout << "-";
  cout << endl;
  return o;
}




