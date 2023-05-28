CXX = g++
ARGS = -Wextra -Wall -Werror -std=c++17 -g
FILES = Application.cpp BaseObject.cpp main.cpp DerivedObject2.cpp DerivedObject3.cpp DerivedObject4.cpp DerivedObject5.cpp DerivedObject6.cpp

all: kursach

kursach:
	$(CXX) $(FILES) -o $@ $(ARGS)
