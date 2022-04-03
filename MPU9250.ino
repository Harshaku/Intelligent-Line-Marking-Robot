/*
#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;

void setup() {
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with IMU
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
  // setting the accelerometer full scale range to +/-8G
  IMU.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  // setting the gyroscope full scale range to +/-500 deg/s
  IMU.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
  // setting DLPF bandwidth to 20 Hz
  IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  // setting SRD to 19 for a 50 Hz update rate
  IMU.setSrd(19);
}

void loop() {
  // read the sensor
  IMU.readSensor();

  // display the data
  Serial.print("ax = ");Serial.print(IMU.getAccelX_mss(),6);Serial.print("\t");
  Serial.print("ay = ");Serial.print(IMU.getAccelY_mss(),6);Serial.print("\t");
  Serial.print("az = ");Serial.print(IMU.getAccelZ_mss(),6);Serial.print("\t");
  Serial.print("gx = ");Serial.print(IMU.getGyroX_rads(),6);Serial.print("\t");
  Serial.print("gy = ");Serial.print(IMU.getGyroY_rads(),6);Serial.print("\t");
  Serial.print("gz = ");Serial.print(IMU.getGyroZ_rads(),6);Serial.print("\t");
  Serial.print("mx = ");Serial.print(IMU.getMagX_uT(),6);Serial.print("\t");
  Serial.print("my = ");Serial.print(IMU.getMagY_uT(),6);Serial.print("\t");
  Serial.print("mz = ");Serial.print(IMU.getMagZ_uT(),6);Serial.print("\t");
  Serial.print("Temp = ");Serial.println(IMU.getTemperature_C(),6);
  delay(20);
}
*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Try this one
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "MPU9250.h"

MPU9250 mpu;
//MPU9255 mpu; // You can also use MPU9255

MPU9250Setting setting;
setting.accel_fs_sel = ACCEL_FS_SEL::A16G;
setting.gyro_fs_sel = GYRO_FS_SEL::G2000DPS;
setting.mag_output_bits = MAG_OUTPUT_BITS::M16BITS;
setting.fifo_sample_rate = FIFO_SAMPLE_RATE::SMPL_200HZ;
setting.gyro_fchoice = 0x03;
setting.gyro_dlpf_cfg = GYRO_DLPF_CFG::DLPF_41HZ;
setting.accel_fchoice = 0x01;
setting.accel_dlpf_cfg = ACCEL_DLPF_CFG::DLPF_45HZ;

mpu.setup(0x68, setting);


void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);
  
    mpu.setup(0x68);  // change to your own address
    status = isConnectedMPU9250();
    if (status < 0) {
      Serial.println("IMU initialization unsuccessful");
      Serial.println("Check IMU wiring or try cycling power");
      Serial.print("Status: ");
      Serial.println(status);
      while(1) {}
    }
    mpu.setMagneticDeclination(10);
    void selectFilter(QuatFilterSel MADGWICK)
    // calibrate anytime you want to
    mpu.calibrateAccelGyro();
    mpu.calibrateMag();    
    Serial.print("MPU9250 is connected" + String(isConnectedMPU9250()));
}

void loop() {
    if (mpu.update()) {
        Serial.print(mpu.getEulerX()); Serial.print(", ");
        Serial.print(mpu.getEulerY()); Serial.print(", ");
        Serial.println(mpu.getEulerZ());
    }
}
