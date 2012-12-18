# compiler
CC= gcc #icc#gcc

# linker
LD=ld

# current path
CURDIR=.

# source path
SRC=$(CURDIR)/src

# matlab path 
MATPATH=/opt/Matlab/R2011a# for local server
#MATPATH=/opt2/Matlab/R2011a# for servers of college

# Matlab link path
MATLINK=-Wl,-rpath=$(MATPATH)/bin/glnxa64

# Matlab link option
MATLIB=$(MATLINK) -L$(MATPATH)/bin/glnxa64 -lmx -leng

# Matlab link path
MATINC=-I$(MATPATH)/extern/include

# link option
LIB=-lm $(MATLIB)

# C compiler compile option
CFLAGS=-O3 #-DMATLAB_SIMULATION -g

all:abd2d
abd2d:abd2d.o 
	$(CC) -o abd2d abd2d.o $(LIB)
abd2d.o:$(SRC)/abd2d.c $(SRC)/*.h
	$(CC) $(CFLAGS) -c $(SRC)/abd2d.c $(MATINC)
clean:
	rm -f *.o abd2d


