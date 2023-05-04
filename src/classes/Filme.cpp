#include "../headers/Filme.h"

Filme Filme::setData(const DataFilmeParams & params){

  tm tempTM = {
    0, params.minuto, params.hora, // seconds , minutes , seconds
    params.dia, params.mes - 1, params.ano - 1900 // 1-based day , 0-based month // year since 1900
  };
  time_t dataFilme = mktime(&tempTM);
  tm * DataTM = localtime(&dataFilme);

  this->data = mktime(DataTM);
  return * this;
}