//fuzzymembership.cpp

#include "fuzzymembership.hpp"

namespace fuzzymembership
{
	double triangleMembership(const double fuzzyitem,const double peak, const double slope)
	{
		double membership = 0; 
		if(peak == fuzzyitem)
		{
			membership = 1;
		}
		else if ((fuzzyitem < peak) && (fuzzyitem > (peak - slope)))
		{
			membership = 1 - ((peak - fuzzyitem) / slope);
		}
		else if (fuzzyitem > peak && fuzzyitem < (peak + slope))
		{
			membership = ((peak + slope) - fuzzyitem) / slope;
		}

		return membership;
	}

	double trapezoidMembership(const double fuzzyitem,const double startpeak,const double endpeak, const double slope)
	{
		double membership = 0; 
		if(startpeak <= fuzzyitem && endpeak >= fuzzyitem)
		{
			membership = 1;
		}
		else if ((fuzzyitem < startpeak) && (fuzzyitem > (startpeak - slope)))
		{
			membership = 1 - ((startpeak - fuzzyitem) / slope);
		}
		else if (fuzzyitem > endpeak && fuzzyitem < (endpeak + slope))
		{
			membership = ((endpeak + slope) - fuzzyitem) / slope;
		}

		return membership;
	}	


	double sigmoidMembership(const double fuzzyitem,const double peak,const bool increasing, const double slope)
	{
		double membership = 0;
		if((peak <= fuzzyitem && increasing) || (peak >= fuzzyitem && !increasing))
		{
			membership = 1;
		}
		else if (increasing && (fuzzyitem > (peak - slope)))
		{
			membership = 1 - ((peak - fuzzyitem) / slope);
		}
		else if (!increasing && (fuzzyitem < (peak + slope)))
		{
			membership = ((peak + slope) - fuzzyitem) / slope;
		}

		return membership;
	}

}
