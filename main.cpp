#include "list.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::istream;

bool getWord(stringstream &ss, string &word)
{
  while (getline(ss,word,' '))
    {
      if (word != "") return true;
    }
  return false;
}

bool getInt(stringstream &ss, int &val)
{
  string word;
  while (getline(ss,word,' '))
    {
      if (word == "") continue;
      try {
	val = stoi(word);
      } catch (...)
	{
	  return false;
	}
      return true;
    }
  return false;
}


void processInput(istream &is, List &x, bool silent=false)
{

  string cmd = "", uid = "", loc = "";
  int prior = 0;
  ifstream fin;
  bool flag;
  while (1) // loop forever
    {
      flag = false;
      if (!silent) cout << ">> ";
      // read a string from the command line
      if (!getline(is,cmd)) return;
      // save it as a string stream
      stringstream cmd_to_proc (cmd);
      // strip the command off for processing
      getWord(cmd_to_proc,cmd);
      // process the command
      if (cmd == "exit")
	{
	  exit(0);
	}
      if (cmd == "display")
	{
	  cout << "This list contains the following: " << endl;
	  cout << x << endl;
	  continue;
	}
      if (cmd == "load")
	{
	  if (getWord(cmd_to_proc,cmd))
	    {
	      fin.open(cmd);
	      if (fin.is_open())
		{
		  processInput(fin,x,true);
		}
	      else
		{
		  cout << "failed to open file!" << endl;
		}
	      fin.close();
	    }
	  continue;
	}
      if (cmd == "find")
	{
	  if (getWord(cmd_to_proc,cmd))
	    {
	      if (x.find(cmd,prior))
		{
		  cout << "Found! " << cmd << "(" << prior << ")" << endl;
		}
	      else
		{
		  cout << cmd << " not found!" << endl;
		}
	    }
	  continue;
	}

      if (cmd == "insert")
	{
	  if (!getWord(cmd_to_proc,cmd)) continue;
	  if (!getInt(cmd_to_proc,prior)) continue;
	  if (getWord(cmd_to_proc, loc))
	    {
	      if (!getWord(cmd_to_proc,uid)) continue;
	      if (loc == "before")
		{
		  flag = x.insertBefore(cmd, prior, uid);
		}
	      else if (loc == "after")
		{
		   flag = x.insertAfter(cmd,prior,uid);
		}
	      else continue;
	    }
	  else
	    {
		      flag = x.insert(cmd,prior);
	    }
	  if (!flag) cout << "Failed! ";
	  cout << cmd << " inserted into list!" << endl;
	  continue;

	}

      if (cmd == "remove")
	{
	  if (getWord(cmd_to_proc,cmd))
	    {
	      if (x.remove(cmd))
		{
		  cout << cmd << " removed from list!" << endl;
		}
	      else
		{
		  cout << cmd << " not found!" << endl;
		}
	    }
	  continue;
	}

    }
}



int main()
{
  
 List x;

 processInput(cin,x);
  return 0;
  




}
