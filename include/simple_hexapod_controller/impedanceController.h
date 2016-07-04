#ifndef IMPEDANCECONTROLLER_H_
#define IMPEDANCECONTROLLER_H_

#include "standardIncludes.h"
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

typedef std::vector< double > state_type;

class ImpedanceController
{
public:
	ImpedanceController(const Parameters &p);
	~ImpedanceController();
	
	void init(Parameters p);
	
	// Calculate and return adapted position of the feet in z-direction
	std::vector<std::vector<double> > &updateImpedance(const std::vector<std::vector<double> > &effort);
	
	// Get zero leg position for inititialzing
	std::vector<std::vector<double> > returnZeroLegMatrix(void) const;
private:
	Parameters PARAMS;
	std::vector<std::vector<double> > TIP_FORCE;
	std::vector<std::vector<state_type> > IMPEDANCE_STATE;
	std::vector<std::vector<double> > DELTA_Z;
	double DELTA_T;
	double VIRT_MASS;
	double VIRT_STIFF;
	double VIRT_DAMP;
	double FORCE_GAIN;
	
	// Solve ODE of the impedance controller
	void calculateDeltaZ(int side, int leg);
};

#endif /* IMPEDANCECONTROLLER_H_ */