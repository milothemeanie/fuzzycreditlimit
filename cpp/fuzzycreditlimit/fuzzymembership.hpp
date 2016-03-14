//fuzzymemberships.hpp

namespace fuzzymembership
{
	double triangleMembership(const double fuzzyitem,const double peak, const double slope);
	double trapezoidMembership(const double fuzzyitem,const double startpeak,const double endpeak, const double slope);
	double sigmoidMembership(const double fuzzyitem,const double peak,const bool increasing, const double slope);
}
