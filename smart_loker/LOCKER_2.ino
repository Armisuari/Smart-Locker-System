void locker_2(){
  
  if(Firebase.getString(firebaseData, "/Control/2"))
  {
    //Success
    //Serial.print("Get int data success, String = ");
    if (firebaseData.stringData() == "UNLOCKED")
    {

//      lcd2.setCursor(9,1);
//      lcd2.print ("OPENED");
      digitalWrite(sol2, LOW);
      //digitalWrite(LED_BUILTIN, LOW);
      state2 = true;
      Serial.println("   Loker 2 : UNLOCKED   ");
      b=1;
    }
    else
    {
      
     // lcd2.setCursor(9,1);
      //lcd2.print ("CLOSED");
      digitalWrite(sol2, HIGH);
      //digitalWrite(LED_BUILTIN, HIGH);
      state2 = false;
      Serial.println("   Loker 2 : LOCKED   ");
    }

  }else{
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }

}
