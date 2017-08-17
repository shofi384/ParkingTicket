// Provided by:   Shofiqur Rahman
// Email Address: shofi384@gmail.com
//								srahman010@citymail.cuny.edu
// FILE: stats.cxx
// Class Implemented: statistician (see stats.h for documentation)

#include <cassert>
#include "stats.h"

namespace main_savitch_2C
{
			statistician::statistician()		// CONSTRUCTOR
			{count = 0;
				total = 0;}

			// MODIFICATION MEMBER FUNCTIONS
			void statistician::next(double r)
			{	++count;
				total +=r;
				if (count==1) {tinyest = r; largest = r;}
				else
					{ if(tinyest>r) tinyest = r;
					if(largest<r) largest = r;}}

			void statistician::reset( )
			{	count =0;
				total =0;}

			// CONSTANT MEMBER FUNCTIONS
			int statistician::length( ) const
			{	return count;}

			double statistician::sum( ) const
			{	return total;}

			double statistician::mean( ) const
			{	assert(length()>0);
				return (total/count);}

			double statistician::minimum( ) const
				{ assert(length()>0);
					return tinyest;}

			double statistician::maximum( ) const
			{ assert (length());
				return largest;}

				// FRIEND FUNCTIONS
        statistician operator +(const statistician& s1, const statistician& s2)
				{	statistician s;
					if (s1.length() == 0) return s2;
					if (s2.length() == 0) return s1;
					s.count = s1.length() + s2.length();
					s.total = s1.sum() + s2.sum();
					if(s1.minimum()>s2.minimum()) s.tinyest = s2.minimum();
						else s.tinyest = s1.minimum();
					if(s1.maximum()<s2.maximum()) s.largest = s2.maximum();
						else s.largest = s1.maximum();
					return s;}

        statistician operator *(double scale, const statistician& s)
				{	statistician s1;
					if(s.length() == 0) s1 = s;
					s1.count = s.length();
					s1.total = scale*s.sum();
					s1.tinyest = scale*s.minimum();
					s1.largest = scale*s.maximum();
					return s1;}

	    // NON-MEMBER functions for the statistician class
		bool operator ==(const statistician& s1, const statistician& s2)
		{	if(s1.length() != s2.length())
				return false;
			if(s1.length() == 0) return true;
			if(s1.sum()!= s2.sum())
				return false;
			if(s1.minimum()!= s2.minimum())
				return false;
			if(s1.maximum()!= s2.maximum())
				return false;
			else return true;}
}
