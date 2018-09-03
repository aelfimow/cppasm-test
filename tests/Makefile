CXXFLAGS += -O2
# CXXFLAGS += -Wall
# CXXFLAGS += -Wextra
# CXXFLAGS += -pedantic
# CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

CXXFLAGS += -I../googletest/include
CXXFLAGS += -I../../cppasm/src

GTEST_OBJ = ../googletest/gtest-all.o
CPPASM_OBJ = ../../cppasm/src/obj/*.o

OBJDIR = ./obj

.PHONY: all
.PHONY: a
.PHONY: t1
.PHONY: t2
.PHONY: t3
.PHONY: t4

all: a t1 t2 t3 t4
	${CXX} ${GTEST_OBJ} ${CPPASM_OBJ} ${OBJDIR}/*.o -o cppasm-test.exe
	@echo No errors

a:
	${CXX} -c main.cpp -o ${OBJDIR}/main.o ${CXXFLAGS}
	${CXX} -c streamdest_buf.cpp -o ${OBJDIR}/streamdest_buf.o ${CXXFLAGS}

t1:
	${CXX} -c test_m16.cpp -o ${OBJDIR}/test_m16.o ${CXXFLAGS}
	${CXX} -c test_m32.cpp -o ${OBJDIR}/test_m32.o ${CXXFLAGS}
	${CXX} -c test_m64.cpp -o ${OBJDIR}/test_m64.o ${CXXFLAGS}
	${CXX} -c test_m8.cpp -o ${OBJDIR}/test_m8.o ${CXXFLAGS}

t2:
	${CXX} -c test_Instruction1.cpp -o ${OBJDIR}/test_Instruction1.o ${CXXFLAGS}
	${CXX} -c test_Instruction2.cpp -o ${OBJDIR}/test_Instruction2.o ${CXXFLAGS}
	${CXX} -c test_Instruction3.cpp -o ${OBJDIR}/test_Instruction3.o ${CXXFLAGS}
	${CXX} -c test_Instruction4.cpp -o ${OBJDIR}/test_Instruction4.o ${CXXFLAGS}
	${CXX} -c test_Instruction5.cpp -o ${OBJDIR}/test_Instruction5.o ${CXXFLAGS}
	${CXX} -c test_Instruction6.cpp -o ${OBJDIR}/test_Instruction6.o ${CXXFLAGS}
	${CXX} -c test_Instruction7.cpp -o ${OBJDIR}/test_Instruction7.o ${CXXFLAGS}
	${CXX} -c test_Instruction8.cpp -o ${OBJDIR}/test_Instruction8.o ${CXXFLAGS}
	${CXX} -c test_Instruction9.cpp -o ${OBJDIR}/test_Instruction9.o ${CXXFLAGS}

t3:
	${CXX} -c test_Instruction10.cpp -o ${OBJDIR}/test_Instruction10.o ${CXXFLAGS}
	${CXX} -c test_Instruction12.cpp -o ${OBJDIR}/test_Instruction12.o ${CXXFLAGS}
	${CXX} -c test_Instruction16.cpp -o ${OBJDIR}/test_Instruction16.o ${CXXFLAGS}
	${CXX} -c test_Instruction26.cpp -o ${OBJDIR}/test_Instruction26.o ${CXXFLAGS}
	${CXX} -c test_Instruction36.cpp -o ${OBJDIR}/test_Instruction36.o ${CXXFLAGS}

t4:
	${CXX} -c test_imm.cpp -o ${OBJDIR}/test_imm.o ${CXXFLAGS}
	${CXX} -c test_reg.cpp -o ${OBJDIR}/test_reg.o ${CXXFLAGS}
