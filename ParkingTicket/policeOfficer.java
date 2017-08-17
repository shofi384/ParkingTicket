/*Shofiqur Rahman
  ID 23304447
  Professor Mohammad Azhar
  CSC.210-1701, Spring 2015
  March 31, 2015 */

/*this policcOfficer class would simulate a police officer inspecting parked cars
	The class's responsibilities are to know the police officer's name and badge number
	To examine a ParkedCar object and a ParkingMeter object, and determine whether the car's time has expired
	To issue a parking ticket (generate a ParkingTicket object) if the car's time has expired*/
public class policeOfficer
{
   parkingTicket park = new parkingTicket();   //create a 'has a relationship' with the 'parkingTicket' class

//an accessor method that returns the police officer's name and badge number
   public void showOfficer()
   {
      park.showOfficer();
   }

//'writeTicket' method that executes if parking time expires and generates a parking ticket
//othwise shows a message that parking is not illegal
   public void writeTicket()
   {
      park.showDetails();
      
      if (park.getIllegalMin()>0)
         park.showFine();
      else
         System.out.println("Parking time has not expired yet.");
         
      park.showOfficer();
   }
}