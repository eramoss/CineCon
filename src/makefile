CC=g++
CFLAGS= -g


SOURCES=main.cpp \
        classes/Assento.cpp \
        classes/Bilhete.cpp \
        classes/Cliente.cpp \
        classes/Filme.cpp \
        classes/ListaCliente.cpp \
        classes/ListaFilme.cpp \
        classes/ListaSala.cpp \
        classes/ListaSessao.cpp \
        classes/Sala.cpp \
        classes/Sessao.cpp \
        classes/ListaCompra.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=CineCon

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
