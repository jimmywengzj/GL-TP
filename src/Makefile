GPP=g++
CC=${GPP}
GPPFLAGS= -ansi -pedantic -Wall -std=c++17
GPPTESTFLAGS= -DMAP -Wno-maybe-uninitialized -Wno-uninitialized -fcompare-debug-second

EXEC=main
OBJ=Main.o Service.o ProviderFunctions.o SensorFunctions.o UserFunctions.o Provider.o Cleaner.o User.o Sensor.o Measurement.o
TESTOBJ=Provider.o Cleaner.o User.o Measurement.o Sensor.o
TESTMAINS=TestMeasurement TestSensor TestUser TestCleaner TestProvider

${EXEC}: ${OBJ}
	${GPP} ${GPPFLAGS} -o ${EXEC} $^

%.o: %.cpp
	${GPP} ${GPPFLAGS} -o $@ -c $^

test: clean ${TESTMAINS}
	echo All tested passed successfully

${TESTMAINS}: ${TESTOBJ}
	${GPP} ${GPPTESTFLAGS} ${GPPFLAGS} -c $@.cpp
	${GPP} ${GPPTESTFLAGS} ${GPPFLAGS} -o $@ $@.o $^
	./$@.exe

clean:
	del ${EXEC} *.o *.gch *.exe