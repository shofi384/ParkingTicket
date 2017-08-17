/*Shofiqur Rahman
  ID 23304447
  Professor Mohammad Azhar
  CSC.210-1701, Spring 2015
  March 31, 2015 */
  
/*This class will simulate a parked car.
  The classes responsibilities are to know the car's
  make, model, color, license number, and the number
  of minutes that the car has been parked*/
  
import java.util.Scanner;

public class parkedCar
{
	private String make, model, color, licence;
	private int parkMin;
	Scanner key = new Scanner(System.in);
	
	public parkedCar()	//an empty constructor that asks the user for input to each of the private fields
	{
		System.out.print("Please enter the car's make: ");
		make = key.nextLine();
		System.out.print("Please enter the car's model: ");
		model = key.nextLine();
		System.out.print("Please enter the car's color: ");
		color = key.nextLine();
		System.out.print("Please enter the licence number: ");
		licence = key.nextLine();
		System.out.print("Please enter the number of minutes for which the car has been parked: ");
		parkMin = key.nextInt();
	}
	
	//This constructor accepts String arguments for car's make, model, color, license number,
	//and number of minutes the car has been parked
	
	public String getMake()
	{
		return make;
	}
	public String getModel()
	{
		return model;
	}
	public String getColor()
	{
		return color;
	}
	public String getLicence()
	{
		return licence;
	}
	public int getMin()
	{
		return parkMin;
	}
}