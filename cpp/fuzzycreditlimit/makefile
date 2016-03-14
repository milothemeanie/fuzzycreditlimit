#------------------------------------------------------------------------------

SOURCE=fuzzycreditlimit.cpp fuzzymembership.cpp
MYPROGRAM=fuzzycreditlimit
MYINCLUDES=/home/scale/g++Projects/gLib/

CC=g++

#------------------------------------------------------------------------------

all: clean $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) $(SOURCE) -o$(MYPROGRAM)

clean:
	rm -f $(MYPROGRAM)

