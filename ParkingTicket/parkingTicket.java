/*Shofiqur Rahman
  ID 23304447
  Professor Mohammad Azhar
  CSC.210-1701, Spring 2015
  March 31, 2015 */
  
/*the parkingTickct class would simulate a parking ticket.
	The class's responsibilities are to report the make, model, color,
	and license number of the illegally parked car,
	to report the amount of the fine, which is $25 for the first hour
	or pan of an hour that the car is illegally parked, plus $10 for every additional hour
	or part of an hour that the car is illegally parked
	to report the name and badge number of the police officer issuing the ticket*/
	
import java.util.Scanner;
public class parkingTicket
{
	private String name, badge;
	private int minutes, hours, fine;
	
	Scanner key = new Scanner(System.in);
	parkedCar car = new parkedCar();	//creates a 'has a relationship' with the 'parkedCar' class
	parkingMeter meter = new parkingMeter();	//'has a relationship' with the 'parkingTicket' class
	
//an empty constructor that asks the user for the name and badge number of the police officer
	public parkingTicket()
	{
		System.out.print("Please enter the name of the officer: ");
		name = key.nextLine();
		System.out.print("Please enter the badge number of the officer: ");
		badge = key.nextLine();
	}
	
//another constructor that receives two String argument and sets them to the private fields
	public parkingTicket(String n, String b)
	{
		name = n;
		badge = b;
	}
	
//'showDetails' method to display the car's information
	public void showDetails()
	{
		System.out.println("\nCar's details: \n" + "Make: " + car.getMake()+
					"\nModel: "+car.getModel() + "\nColor: " + car.getColor()+
					"\nDriver's Licence No. " + car.getLicence() + "\n\nParking Time: "+
					car.getMin() + "\nPurchased Time: " + meter.getBoughtMin());
	}
	
   public int getIllegalMin()
   {
      minutes = car.getMin()-meter.getBoughtMin();
      return minutes;
   }

//'showFine' method that calculates the fine, sets it to the fine field, and displays the total fine
	public void showFine()
	{
		if (minutes>0)
      hours = (car.getMin()-meter.getBoughtMin())/60;
		fine = 25+(10*hours);
		System.out.println("\nTotal illegel parking minutes: " + minutes+
                     "\nTotal fine: " + fine);
	}
	
//'showOfficer' method to display the police officer's information
	public void showOfficer()
	{
		System.out.println("\nOfficer who inspected the above issue is: " + name+
					" and the badge number is: " + badge);
	}
	
//an accessor method to return the amount of fine
	public int getFine()
	{
		return fine;
	}
}