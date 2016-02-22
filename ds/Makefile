WORKROOT=../
PUBLIC = ../public

FLAGS=-Wall -g -Dprivate=public -Dprotected=public
CXX=g++

all : clean main
main : main.cpp *.h
	$(CXX) $^ -o $@ $(FLAGS)
clean:
	rm main
run:
	chmod +x main; ./main
