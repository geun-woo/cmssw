#ifndef Interceptor_h
#define Interceptor_h

#include <vector>
#include <string>

#include "PhysicsTools/MVAComputer/interface/Calibration.h"
#include "PhysicsTools/MVAComputer/interface/Variable.h"

namespace PhysicsTools {

// forward declaration
class MVAComputer;

namespace Calibration {

class Interceptor : public VarProcessor {
    public:
	virtual std::string getInstanceName() const { return "Interceptor"; }
	virtual std::vector<PhysicsTools::Variable::Flags>
			configure(const PhysicsTools::MVAComputer *computer,
			          unsigned int n) = 0;
	virtual double intercept(const std::vector<double> *values) const = 0;
};

} // namespace Calibration
} // namespace PhysicsTools

#endif // Interceptor_h
