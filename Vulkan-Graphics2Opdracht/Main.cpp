// custom header files
#include "va_mainApp.h"

// C++ Default headers / libs
#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main() {
	va::vaMainApp app{};

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}