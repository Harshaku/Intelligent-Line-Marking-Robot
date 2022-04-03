//to obtain the steering angle for pure pursuit
float pure_pursuit(float wheel_speed,float theta,float phi,float Kdd = 1){
  //output is the steering angle alone!!
  float alpha = theta - phi;
  if (theta >= 90){
    alpha = 180-theta-phi;
  }
  float st_angle = atan(2*WheelDist*sin(theta-phi)/(Kdd*wheel_speed)); //for calculating the steering angle we are using pure pursuit formula,theta == angle of the ld with x axis, phi is the orientation 
  return st_angle;
}

float differential_turn(int trigger){
  if (trigger == 1){
      float vx = 0;
      float vy = 0;
      float w = -0.005/0.2;}
  else if (trigger == -1){
      float vx = 0;
      float vy = 0; 
      float w = 0.005/0.2; }
    
}

//the vehicle traces a the normal kinametics
void normal_mode(float wheel_speed,float phiFront){
      int phiRear = 0; 
      float vx = 0.5*wheelRadius*(wheel_speed*cos(phiFront) + wheel_speed*cos(phiRear));
      float vy = 0.5*wheelRadius*(wheel_speed*sin(abs(phiFront)) + wheel_speed*sin(abs(phiRear)));
      float w = (wheel_speed*sin(phiFront)-wheel_speed*sin(phiRear))*wheelRadius/WheelDist;
}
