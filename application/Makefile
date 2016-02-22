WORKROOT=../
PUBLIC = ../public
DS=../ds

FLAGS=-Wall -g -Dprivate=public -Dprotected=public
CXX=g++
INCLUDES=-I$(DS)
PATTERN=*.cpp
TESTFILES=$(wildcard $(PATTERN))
EXE=$(basename $(TESTFILES))

all : $(EXE)
$(EXE) : % : %.cpp
	$(CXX) $^ -o $@ $(FLAGS) $(INCLUDES)
clean:
	rm -rf *.o $(EXE)
