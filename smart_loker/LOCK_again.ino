void lock_again() {

if (state1 == true)
{

  if(millis() - prev >= interval*30)
{

  Firebase.setString(firebaseData, "/Control/1", "LOCKED");
  prev = millis();
}
}

if (state2 == true)
{

  if(millis() - prev2 >= interval*30)
{

  Firebase.setString(firebaseData, "/Control/2", "LOCKED");
  prev2 = millis();
}
}

if ((rs1 == 0 && a == 1)||(rs2 == 0 && b == 1))
{

  a=0;
  b=0;
}
}

// if (state3 == 1 && rs1 == 1){
//
//  state3 = 2;
// }
//
//if (state3 == 2 && rs1 == 0)
//{
//
//state3 = 3;
//}
//
//if (state3 == 3 && rs1 == 1)
//{
//
//  Firebase.setString(firebaseData, "/Control/1", "LOCKED");
//  state3 = 4;
//}
//if (rs1 == 0)
//
//{
//
//  Firebase.setString(firebaseData, "/Control/1", "LOCKED");
//}
//
//if (rs2 == 0)
//{
//
//  Firebase.setString(firebaseData, "/Control/2", "LOCKED");
//}
//}
