CXXFLAGS += -O2
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

OBJDIR = ./obj

.PHONY: all
.PHONY: a
.PHONY: t1
.PHONY: t2
.PHONY: t3
.PHONY: t4

all: a t1 t2 t3 t4
	@echo No errors

a:
	${CXX} -c main.cpp ${OBJDIR}/main.o ${CXXFLAGS}
	${CXX} -c streamdest_buf.cpp ${OBJDIR}/streamdest_buf.o ${CXXFLAGS}

t1:
	${CXX} -c test_m16.cpp ${OBJDIR}/test_m16.o ${CXXFLAGS}
	${CXX} -c test_m32.cpp ${OBJDIR}/test_m32.o ${CXXFLAGS}
	${CXX} -c test_m64.cpp ${OBJDIR}/test_m64.o ${CXXFLAGS}
	${CXX} -c test_m8.cpp ${OBJDIR}/test_m8.o ${CXXFLAGS}

t2:
	${CXX} -c test_Instruction1.cpp ${OBJDIR}/test_Instruction1.o ${CXXFLAGS}
	${CXX} -c test_Instruction2.cpp ${OBJDIR}/test_Instruction2.o ${CXXFLAGS}
	${CXX} -c test_Instruction3.cpp ${OBJDIR}/test_Instruction3.o ${CXXFLAGS}
	${CXX} -c test_Instruction4.cpp ${OBJDIR}/test_Instruction4.o ${CXXFLAGS}
	${CXX} -c test_Instruction5.cpp ${OBJDIR}/test_Instruction5.o ${CXXFLAGS}
	${CXX} -c test_Instruction6.cpp ${OBJDIR}/test_Instruction6.o ${CXXFLAGS}
	${CXX} -c test_Instruction7.cpp ${OBJDIR}/test_Instruction7.o ${CXXFLAGS}
	${CXX} -c test_Instruction8.cpp ${OBJDIR}/test_Instruction8.o ${CXXFLAGS}
	${CXX} -c test_Instruction9.cpp ${OBJDIR}/test_Instruction9.o ${CXXFLAGS}

t3:
	${CXX} -c test_Instruction10.cpp ${OBJDIR}/test_Instruction10.o ${CXXFLAGS}
	${CXX} -c test_Instruction12.cpp ${OBJDIR}/test_Instruction12.o ${CXXFLAGS}
	${CXX} -c test_Instruction16.cpp ${OBJDIR}/test_Instruction16.o ${CXXFLAGS}
	${CXX} -c test_Instruction26.cpp ${OBJDIR}/test_Instruction26.o ${CXXFLAGS}
	${CXX} -c test_Instruction36.cpp ${OBJDIR}/test_Instruction36.o ${CXXFLAGS}

t4:
	${CXX} -c test_imm.cpp ${OBJDIR}/test_imm.o ${CXXFLAGS}
	${CXX} -c test_reg.cpp ${OBJDIR}/test_reg.o ${CXXFLAGS}
