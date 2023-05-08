#ifndef SALA_H
#define SALA_H
#include <string>
#include <vector>
#include "Assento.h"

class Sala{

public:
  Sala();
  Sala(const std::string& id,int totalAssentos);
  ~Sala();

/*getters*/
  std::string getId() const;
  int getTotalAssentos() const;
  std::vector<Assento> getAssentos() const;


/*setters*/
  Sala& setId(const std::string&);
  Sala& setTotalAssentos(int);
  Sala& setAssentos(const std::vector<Assento>&);
  
private:
  std::string id;
  int totalAssentos;
  std::vector<Assento> assentos;
};


#endif