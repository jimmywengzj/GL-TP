GPP=g++
CC=${GPP}
GPPFLAGS=-ansi -pedantic -Wall -std=c++11 -Wno-maybe-uninitialized -Wno-uninitialized

EXEC=main
OBJ=Main.o Service.o SensorFunctions.o UserFunctions.o Provider.o Cleaner.o User.o Sensor.o Measurement.o
TESTOBJ=Measurement.o Sensor.o
TESTMAINS=TestMeasurement TestSensor

${EXEC}: ${OBJ}
	${GPP} ${GPPFLAGS} -o ${EXEC} $^

%.o: %.cpp
	${GPP} ${GPPFLAGS} -o $@ -c $^

test: ${TESTMAINS}
	echo 'All tested passed successfully'

${TESTMAINS}: ${TESTOBJ}
	${GPP} ${GPPFLAGS} -c $@.cpp
	${GPP} ${GPPFLAGS} -o $@ $@.o $^
	./$@.exe

clean:
	del ${EXEC} *.o *.gch *.exe