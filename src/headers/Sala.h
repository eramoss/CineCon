#ifndef SALA_H
#define SALA_H
#include <string>
#include <vector>
#include "Assento.h"

class Sala{

public:
  Sala(/* args */);
  ~Sala();

/*getters*/
  std::string getId() const;
  int getTotalAssentos() const;
  int getAssentosReservados() const;
  std::vector<Assento> getAssentos() const;


/*setters*/
  Sala setId(const std::string&);
  Sala setTotalAssentos(int);
  Sala setAssentosReservados(int);
  Sala setAssentos(const std::vector<Assento>&);
  
private:
  std::string id;
  int totalAssentos;
  int assentosReservados;
  std::vector<Assento> assentos;
};


#endif