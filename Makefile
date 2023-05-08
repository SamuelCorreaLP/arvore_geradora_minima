CXX=g++
CXXFLAGS=-g -ggdb -O2 -Wall

TARGET=main
OBJS=main.o \
	grafo.o \
	agm.o  

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

main.o: grafo.h agm.h
grafo.o: grafo.h aresta.h
agm.o: agm.h aresta.h

$(TARGET): $(OBJS)
		   $(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
