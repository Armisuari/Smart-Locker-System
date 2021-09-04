void locker_1(){
  
  if(Firebase.getString(firebaseData, "/Control/1"))
  {
    //Success
    //Serial.print("Get int data success, String = ");
    if (firebaseData.stringData() == "UNLOCKED")
    {

     // lcd1.setCursor(9,1);
     // lcd1.print ("OPENED");
      digitalWrite(sol1, LOW);
      //digitalWrite(LED_BUILTIN, LOW);
      state1 = true;
      Serial.print("Loker 1 : UNLOCKED");
      a=1;
    }
    else
    {
      
      //lcd1.setCursor(9,1);
      //lcd1.print ("CLOSED");
      digitalWrite(sol1, HIGH);
      //digitalWrite(LED_BUILTIN, HIGH);
      state1 = false;
     Serial.print("Loker 1 : LOCKED");
    }



  }else{
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }
}
