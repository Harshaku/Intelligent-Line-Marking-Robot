// to calculate theta
float cal_theta(float curr_pos[],float target_pos[]){
  float latLength = distance(curr_pos[1], curr_pos[0], target_pos[1], curr_pos[0], 1); 
  float lonLength = distance(curr_pos[1],  curr_pos[0],  curr_pos[1], target_pos[0], 1);
  if(latLength == 0)
    latLength == 0.0001; 
  if(lonLength == 0)
    lonLength == 0.0001; 
  float theta = degrees(atan(lonLength/latLength));
  return theta; //output for diff or for pure pursuit
}
