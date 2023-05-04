#ifndef ASSENTO_H
#define ASSENTO_H
#include <string>
class Assento{

public:
  Assento(/* args */);
  ~Assento();

  std::string getId() const;
  bool isReservado() const;

  Assento setId(const std::string&);
  Assento setReservado(bool);

  private:
    std::string id;
    bool Reservado;
};


#endif