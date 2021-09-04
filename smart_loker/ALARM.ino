void alarm(){
  
  
  if((rs1 == 1 && a==0) || (rs2 == 1 && b==0))
{

  Firebase.setString(firebaseData, "/status", "false");
}
else
{

  Firebase.setString(firebaseData, "/status", "true");
}
}
