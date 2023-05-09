GPP=g++
CC=${GPP}
GPPFLAGS=-ansi -pedantic -Wall -std=c++11

EXEC=main
OBJ=main.o Service.o SensorFunctions.o UserFunctions.o Provider.o Cleaner.o User.o Sensor.o Measurement.o

${EXEC}: ${OBJ}
	${GPP} ${GPPFLAGS} -o ${EXEC} $^

%.o: %.cpp
	${GPP} ${GPPFLAGS} -o $@ -c $^

clean:
	del ${EXEC} ${OBJ} ${OBJ:.o=.gch}