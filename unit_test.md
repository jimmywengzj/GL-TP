# Unit Tests

## Measurement

### Test creation

```cpp
public void testMeasurementCreation(){
    time_t date = "2022-05-04 12:00:00";
    int sensorId = 1;
    float valueO3 = 0.05;
    float valueNO2 = 0.05;
    float valueSO2 = 0.05;
    float valuePM10 = 0.05;
    Measurement measurement = new Measurement(date, sensorId, valueO3, valueNO2, valueSO2, valuePM10);
    assert(measurement != NULL);
    assert(measurements.getDate() == date);
    assert(measurement.getSensorId() == sensorId);
    assert(measurement.getValueO3() == valueO3);
    assert(measurement.getValueNO2() == valueNO2);
    assert(measurement.getValueSO2() == valueSO2);
    assert(measurement.getValuePM10() == valuePM10);
}
```

## Sensor

### Test creation

```cpp
public void testSensorCreation(){
    int id = 1;
    float lat = 49.05;
    float lon = -85.23;
    Sensor sensor = new Sensor(id, lat, lon);
    assert(sensor != NULL);
    assert(sensor.getId() == id);
    assert(sensor.getLatitude() == lat);
    assert(sensor.getLongitude() == lon);
    assert(sensor.getGood() == true);
    assert(sensor.getMeasurements() != NULL);
    assert(sensor.getMeasurements().size() == 0);
} 
```

### Test flagging 

```cpp
public void testSensorFlag(){
    int id = 1;
    float lat = 49.05;
    float lon = -85.23;
    Sensor sensor = new Sensor(id, lat, lon);

    sensor.setBad();
    assert(sensor.getGood() == false);
}
```

### Test adding Measurements

```cpp
public void testAddMeasurement(){
    int id = 1;
    float lat = 49.05;
    float lon = -85.23;
    Sensor sensor = new Sensor(id, lat, lon);

    time_t date = "2022-05-04 12:00:00";
    int sensorId = 1;
    float valueO3 = 0.05;
    float valueNO2 = 0.05;
    float valueSO2 = 0.05;
    float valuePM10 = 0.05;
    Measurement measurement = new Measurement(date, sensorId, valueO3, valueNO2, valueSO2, valuePM10);

    sensor.addMeasurement(measurement);
    assert(sensor.getMeasurements().size() == 1);
    /* Needs a redefinition of the == operator for Measurement */
    assert(sensor.getMeasurments().front() == measurement);
    
}
```

## User

### Test creation

```cpp
public void testUserCreation(){
    int id = 1;
    int initialPoints = 0;
    User user = new User(id, initialPoints);
    assert(user != NULL);
    assert(user.getId() == id);
    assert(user.getPoints() == initialPoints);
    assert(user.getGood() == true);
    assert(user.getSensors() != NULL);
    assert(user.getSensors().size() == 0);
}
```

### Test flagging 

```cpp
public void testSensorFlag(){
    int id = 1;
    int initialPoints = 0;
    User user = new User(id, initialPoints);

    user.setBad();
    assert(user.getGood() == false);
}
```

### Test adding Sensors

```cpp
public void testAddSensor(){
    int id = 1;
    int initialPoints = 0;
    User user = new User(id, initialPoints);

    int sensorId = 1;
    float lat = 49.05;
    float lon = -85.23;
    Sensor sensor = new Sensor(sensorId, lat, lon);

    user.addSensor(sensor);
    assert(user.getSensors().size() == 1);
    /* Needs a redefinition of the == operator for Sensor */
    assert(user.getSensors().front() == sensor);
}
```

## Cleaner

### Test creation

```cpp
public void testCleanerCreation(){
    int id = 1;
    float lat = 49.05;
    float lon = -85.23;
    time_t timestampStart = "2022-05-04 12:00:00";
    time_t timestampEnd = "2022-05-04 13:00:00";
    Cleaner cleaner = new Cleaner(id, lat, lon, timestampStart, timestampEnd);
    assert(cleaner != NULL);
    assert(cleaner.getId() == id);
    assert(cleaner.getLatitude() == lat);
    assert(cleaner.getLongitude() == lon);
    assert(cleaner.getTimestampStart() == timestampStart);
    assert(cleaner.getTimestampEnd() == timestampEnd);
}
```

## Provider 

### Test creation

```cpp
public void testProviderCreation(){
    int id = 1;
    Provider provider = new Provider(id);
    assert(provider != NULL);
    assert(provider.getId() == id);
    assert(provider.getCleaners() != NULL);
    assert(provider.getCleaners().size() == 0);
}
```

### Test adding Cleaners

```cpp
public void testAddCleaner(){
    int id = 1;
    Provider provider = new Provider(id);

    int cleanerId = 1;
    float lat = 49.05;
    float lon = -85.23;
    time_t timestampStart = "2022-05-04 12:00:00";
    time_t timestampEnd = "2022-05-04 13:00:00";
    Cleaner cleaner = new Cleaner(cleanerId, lat, lon, timestampStart, timestampEnd);

    provider.addCleaner(cleaner);
    assert(provider.getCleaners().size() == 1);
    /* Needs a redefinition of the == operator for Cleaner */
    assert(provider.getCleaners().front() == cleaner);
}
```
