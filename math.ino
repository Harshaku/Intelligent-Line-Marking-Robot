//D to DMS
float D_DMS(double inputCoord){    
  //conversion below
  uint16_t wholeDegrees = 0.01*inputCoord;
  return wholeDegrees + (inputCoord - 100.0*wholeDegrees)/60.0;
}

// to calculate the distance between the two coordinates
float distance(float currentLat, float currentLon, float targetLat, float targetLon, float unit_conversion){
  //Pythagorean formula (not as accurate)

  /*float latDiff = abs(currentLat - targetLat); 
   float longDiff = abs(currentLon - targetLon); 
   latDiff = pow(latDiff, 2); 
   longDiff = pow(longDiff, 2); 
   float total = latDiff + longDiff; 
   return sqrt(total); */

  //Haversine formula

  float dLat = radians(targetLat - currentLat);
  float dLon = radians(targetLon - currentLon);
  float a = sin(dLat/2.0f)*sin(dLat / 2.0f) + cos(radians(currentLat)) * cos(radians(targetLat)) *
    sin(dLon/2.0f)*sin(dLon/2.0f);

  float d = 2.0f * atan2(sqrt(a), sqrt(1.0f - a));
  return d * Earth_Radius * unit_conversion;
}
