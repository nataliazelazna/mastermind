CXX=g++
RM=rm -f

SRCS=mastermind.cpp colorHelpers.cpp code.cpp codemaker.cpp game.cpp
TARGET=mastermind
OBJS=$(subst .cc,.o,$(SRCS))

all: mastermind

mastermind: $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

clean:
	$(RM) $(OBJS)

