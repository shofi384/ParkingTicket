/*Shofiqur Rahman
  ID 23304447
  Professor Mohammad Azhar
  CSC.210-1701, Spring 2015
  March 31, 2015 */

/*This class should simulate a parking meter. The class's only responsibility is
  to know the number of minutes of parking time that has been purchased */

import java.util.Scanner;

public class parkingMeter
{
	private int boughtMin;
	Scanner key = new Scanner(System.in);
	
/*an empty constructor that asks the user for
	the number of minutes the ticket has been purchased for */
	public parkingMeter()
	{
		System.out.print("Please enter the number of minutes parking ticket purchased for: ");
		boughtMin = key.nextInt();
	}
	
//a constructor that accepts an int argument and sets the argument to boughtMin
	public parkingMeter(int m)
	{
		boughtMin = m;
	}
/*an mutator that accepts an integer argument 
	and sets the value to the boughtMen field*/
	public void setBoughtMin(int m)
	{
		boughtMin = m;
	}
//a accessor method that returns the value in boughtMin field
	public int getBoughtMin()
	{
		return boughtMin;
	}
}