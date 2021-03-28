IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs --coverage

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp romano.hpp 
DEPS = $(patsubst % , $(IDIR)/% , $(_DEPS))

_OBJ = romano.o teste_romano.o
OBJ = $(patsubst % , $(ODIR)/% , $(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romano: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~