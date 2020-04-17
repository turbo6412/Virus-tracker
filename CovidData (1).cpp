#include "CovidData.h"

CovidData::CovidData(){

}

int CovidData::readData(string filename) {
  int ctr = 0;
  myfile.open(filename);
  // conditional to check if file is opened properly
  if(myfile.is_open()){
    while(!myfile.eof()){
      myfile >> cName >> nDays >> nCases;
      ctr++;
      data.push_back(Stats(cName, nDays, nCases));
    }
  }
  return ctr;
}

int CovidData::getDays(string country){
  int most = 0;
  days.clear();         // clear second vector so previous data does not remain

  for(int x = 0; x < data.size(); x++){
    if(country == data[x]._name){
      days.push_back(data[x]._days);    // push number of days into second vector
    }                                   // so long as the country name is the same
  }                                     // as requested country
  if(!days.empty()){
    for(int y = 0; y < days.size(); y++){
      if(days[y] > most){
        most = days[y];
      }
    }
    return most;
  }
  return -1;
}
