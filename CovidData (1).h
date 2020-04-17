#pragma once

/*
  I will first begin by creating and declaring my prototypes and variables I will
  need. Once finished, I will then create a struct that will contain the country
  names, days, and cases in an object that will then be put into a vector as the
  file is being read. For the readData() function, a counter will be added that
  will increment each time a line is read from a file. For the getDays() function,
  it will first check if the given country exists. If not, -1 will be returned.
  Otherwise I will use for loops and if statements to find the country and push
  the number of days from the first vector to a second vector. By iterating through
  the second vector, the max amount of days will be found and returned.
*/

#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Stats{
  string _name;
  int _days;
  int _cases;
  Stats(string Cname, int Ndays, int Ncases): _name(Cname), _days(Ndays), _cases(Ncases) {}
};

class CovidData{
public:
  ifstream myfile;
  string cName;
  int nDays;
  int nCases;
  vector<Stats> data;               // first vector from reading file
  vector<int> days;                 // second vector for finding max days
  CovidData();                      // default constructor
  int readData(string filename);    // reads in file
  int getDays(string country);      // returns # of days associated w/ country
};
