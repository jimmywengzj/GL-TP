GPP=g++
CC=${GPP}
GPPFLAGS=-ansi -pedantic -Wall -std=c++11

EXEC=main
OBJ=Main.o Service.o SensorFunctions.o UserFunctions.o Provider.o Cleaner.o User.o Sensor.o Measurement.o
TESTOBJ=Measurement.o Sensor.o
TESTMAINS=TestMeasurement TestSensor

${EXEC}: ${OBJ}
	${GPP} ${GPPFLAGS} -o ${EXEC} $^

%.o: %.cpp
	${GPP} ${GPPFLAGS} -o $@ -c $^

test-windows: ${TESTMAINS}
	$(foreach var,$(TESTMAINS),./$(var).exe ; )

test-linux: ${TESTMAINS}
	$(foreach var,$(TESTMAINS),./$(var),)

${TESTMAINS}: ${TESTOBJ}
	${GPP} ${GPPFLAGS} -c $@.cpp
	${GPP} ${GPPFLAGS} -o $@ $@.o $^


clean:
	del ${EXEC} ${OBJ} ${OBJ:.o=.gch}