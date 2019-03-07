GTEST_ROOT = C:\Users\ANEA\googletest\build
GTEST_INCLUDE = $(GTEST_ROOT)\include
GTEST_LIB = $(GTEST_ROOT)\lib
GTEST_LIBLIST = -lgtest -lgtest_main -lgmock -lgmock_main
OBJS = NumWord.o NumWordTest.o
EXE = NumWord.exe

all: $(EXE)

clean:
	-rm -f *.o *.d *.exe
	
$(EXE): $(OBJS)
	g++ -L$(GTEST_LIB) -o $@ $^ $(GTEST_LIBLIST)

%.o: %.cpp
	g++ -std=gnu++11 -I $(GTEST_INCLUDE) -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF$*.d -MT$@ -o $@ $<
